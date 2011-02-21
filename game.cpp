/* Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "H2oH!"
 *
 * "H2oH!" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * "H2oH!" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "H2oH!" If not, see <http://www.gnu.org/licenses/>.
 */

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <gl/gl.h>
#include <physfs.h>
#include <Box2D/Box2D.h>
#include "game.hpp"
#include "config.hpp"
#include "textures.hpp"
#include "particles.hpp"
#include "music.hpp"
#include "menu.hpp"
#include "sound.hpp"

extern config_type   config;
extern particle_type particle[MAX_PARTICLES];
extern menu_type     menu;
extern sfx_type      sfx;
extern sound_type    sound[MAX_SOUNDS];
extern song_type     song;
extern music_type    music[MAX_MUSIC];
extern image_type    image;
extern texture_type  texture[MAX_TEXTURES];
       game_type     game;

const char  App_Name[] = "H2oH!";
const char  App_Icon[] = "data/icon.bmp";
const char  App_ConF[] = "H2oH.cfg";
const char  App_LogF[] = "H2oH.log";
const char  App_DatF[] = "H2oH.dat";

Uint32       colorkey;
SDL_Surface *App_Icon_Surface;
char        *argv[0];

int game_init(void)
{
   background_init();
   game.status_menu_active = true;
   game.status_game_active = false;
   game.status_quit_active = false;
   load_default_config();
   init_log_file(App_LogF);
   //load_config_file(App_ConF);
   //----------------------------------- Start the PhysicsFS ----------------------
   //Log_File(App_Logf,"Starting PhysicsFS...");
   PHYSFS_init(argv[0]);
   PHYSFS_addToSearchPath(App_DatF, 1);
   //----------------------------------- SDL Video --------------------------------
   putenv("SDL_VIDEO_WINDOW_POS");
   putenv("SDL_VIDEO_CENTERED=1");
   getenv("SDL_VIDEO_WINDOW_POS");
   getenv("SDL_VIDEO_CENTERED");
   SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD);
   if (config.screen_fullscreen) SDL_SetVideoMode(config.screen_resolution_x,config.screen_resolution_y,config.screen_bbp,SDL_OPENGL | SDL_FULLSCREEN);
   else                          SDL_SetVideoMode(config.screen_resolution_x,config.screen_resolution_y,config.screen_bbp,SDL_OPENGL);
   if (config.screen_double_buffering) SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
   App_Icon_Surface = SDL_LoadBMP(App_Icon);
   colorkey = SDL_MapRGB(App_Icon_Surface->format, 255, 0, 255);
   SDL_SetColorKey(App_Icon_Surface, SDL_SRCCOLORKEY, colorkey);
   SDL_WM_SetIcon(App_Icon_Surface,NULL);
   SDL_WM_SetCaption(App_Name, 0);
   //----------------------------------- SDL Audio --------------------------------
   SDL_Init(SDL_INIT_AUDIO);
   Mix_AllocateChannels(config.audio_channels);
   Mix_OpenAudio(config.audio_rate, AUDIO_S16, 2, config.audio_buffers);
   Mix_Volume(-1,config.audio_sound_volume);
   Mix_VolumeMusic(config.audio_music_volume);
   init_textures();
   init_sounds();
   init_music();
   game_load_resources();
   init_particles();
   init_gl();

   return(1);
}

int game_load_resources()
{
   load_music();
   load_sounds();
   load_textures();
   return(1);
}

int game_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    background_display();
    glPushMatrix();

    glPopMatrix();
    SDL_GL_SwapBuffers();
    return(1);
}

int game_process(void)
{
   background_process();
   while (SDL_PollEvent(&game.event))
   {
      if (game.event.type == SDL_QUIT) game.status_quit_active = true;
      if (game.event.type == SDL_KEYDOWN)
      {
         if (game.event.key.keysym.sym == SDLK_ESCAPE)
         {
            SDL_ShowCursor(SDL_ENABLE);
            game.status_menu_active  = true;
            game.status_game_active  = false;
            menu.last_sellect        = -1;
            menu.current_level       = 0;
            menu.current_button      = 0;
            game.mouse_button_left   = false;
            game.mouse_button_middle = false;
            game.mouse_button_right  = false;
         }
      }
   }
   return(1);
}

int game_deinit(void)
{


  save_config_file(App_ConF);
  kill_music();
  kill_sounds();
  kill_textures();
  PHYSFS_deinit();
  SDL_Quit();
  return(1);
}

int init_gl(void)
{
  glViewport(0, 0,config.screen_resolution_x,config.screen_resolution_y);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  if (config.screen_alpha_blending) glEnable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_TEXTURE_2D);
  return(1);
}

int background_process(void)
{
// -------------------------   background 0  -----------------------------------
   if (game.background_scroll[0].x_dir == 0)
   {
      game.background_scroll[0].x_pos -= game.background_scroll[0].scroll_rate;
      if (game.background_scroll[0].x_pos < 0.0f) game.background_scroll[0].x_dir = 1;
   }
   if (game.background_scroll[0].x_dir == 1)
   {
      game.background_scroll[0].x_pos += game.background_scroll[0].scroll_rate;
      if (game.background_scroll[0].x_pos > 1.0f) game.background_scroll[0].x_dir = 0;
   }

   if (game.background_scroll[0].y_dir == 0)
   {
      game.background_scroll[0].y_pos -= game.background_scroll[0].scroll_rate;
      if (game.background_scroll[0].y_pos < 0.0f) game.background_scroll[0].y_dir = 1;
   }
   if (game.background_scroll[0].y_dir == 1)
   {
      game.background_scroll[0].y_pos += game.background_scroll[0].scroll_rate;
      if (game.background_scroll[0].y_pos > 0.75f) game.background_scroll[0].y_dir = 0;
   }
// -------------------------   background 1  -----------------------------------
   if (game.background_scroll[1].x_dir == 0)
   {
      game.background_scroll[1].x_pos -= game.background_scroll[1].scroll_rate;
      if (game.background_scroll[1].x_pos < 0.0f) game.background_scroll[1].x_dir = 1;
   }
   if (game.background_scroll[1].x_dir == 1)
   {
      game.background_scroll[1].x_pos += game.background_scroll[1].scroll_rate;
      if (game.background_scroll[1].x_pos > 1.0f) game.background_scroll[1].x_dir = 0;
   }

   if (game.background_scroll[1].y_dir == 0)
   {
      game.background_scroll[1].y_pos -= game.background_scroll[1].scroll_rate;
      if (game.background_scroll[1].y_pos < 0.0f) game.background_scroll[1].y_dir = 1;
   }
   if (game.background_scroll[1].y_dir == 1)
   {
      game.background_scroll[1].y_pos += game.background_scroll[1].scroll_rate;
      if (game.background_scroll[1].y_pos > 0.75f) game.background_scroll[1].y_dir = 0;
   }
   return(1);
}

int background_init    (void)
{
   game.background_scroll[0].x_dir        = 0;
   game.background_scroll[0].y_dir        = 0;
   game.background_scroll[0].x_pos        = 0.0f;
   game.background_scroll[0].y_pos        = 0.0f;
   game.background_scroll[0].scroll_rate  = 0.0005f;
   game.background_scroll[1].x_dir        = 1;
   game.background_scroll[1].y_dir        = 1;
   game.background_scroll[1].x_pos        = 0.0f;
   game.background_scroll[1].y_pos        = 0.0f;
   game.background_scroll[1].scroll_rate  = 0.001f;
   return(1);
};

int background_display (void)
{
   float z_pos   = 0.0f;
   glPushMatrix();
 //---------------------------------- display backgrounds ---------------------------------------------------------------------
   if (game.background_scroll[3].x_pos > game.background_scroll[2].x_pos)
   {
       z_pos = 0.16f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[3].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f( 2.000f + game.background_scroll[2].x_pos,-2.000f + game.background_scroll[3].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f( 2.000f + game.background_scroll[2].x_pos, 2.000f + game.background_scroll[3].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f( 2.000f + game.background_scroll[3].x_pos, 2.000f + game.background_scroll[3].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f( 2.000f + game.background_scroll[3].x_pos,-2.000f + game.background_scroll[3].y_pos,z_pos);
       glEnd();
   }
   else
   {
       z_pos = 0.16f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[3].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f(-2.000f + game.background_scroll[3].x_pos,-2.000f + game.background_scroll[3].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f(-2.000f + game.background_scroll[3].x_pos, 2.000f + game.background_scroll[3].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f(-2.000f + game.background_scroll[2].x_pos, 2.000f + game.background_scroll[3].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f(-2.000f + game.background_scroll[2].x_pos,-2.000f + game.background_scroll[3].y_pos,z_pos);
       glEnd();
   }
   if (game.background_scroll[2].x_pos > game.background_scroll[3].x_pos)
   {
       z_pos = 0.16f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[2].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f( 2.000f + game.background_scroll[3].x_pos,-2.000f + game.background_scroll[2].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f( 2.000f + game.background_scroll[3].x_pos, 2.000f + game.background_scroll[2].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f( 2.000f + game.background_scroll[2].x_pos, 2.000f + game.background_scroll[2].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f( 2.000f + game.background_scroll[2].x_pos,-2.000f + game.background_scroll[2].y_pos,z_pos);
       glEnd();
   }
   else
   {
       z_pos = 0.16f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[2].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f(-2.000f + game.background_scroll[2].x_pos,-2.000f + game.background_scroll[2].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f(-2.000f + game.background_scroll[2].x_pos, 2.000f + game.background_scroll[2].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f(-2.000f + game.background_scroll[3].x_pos, 2.000f + game.background_scroll[2].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f(-2.000f + game.background_scroll[3].x_pos,-2.000f + game.background_scroll[2].y_pos,z_pos);
       glEnd();
   }

   if (game.background_scroll[1].x_pos > game.background_scroll[0].x_pos)
   {
       z_pos = 0.15f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[1].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f( 2.000f + game.background_scroll[0].x_pos,-2.000f + game.background_scroll[1].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f( 2.000f + game.background_scroll[0].x_pos, 2.000f + game.background_scroll[1].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f( 2.000f + game.background_scroll[1].x_pos, 2.000f + game.background_scroll[1].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f( 2.000f + game.background_scroll[1].x_pos,-2.000f + game.background_scroll[1].y_pos,z_pos);
       glEnd();
   }
   else
   {
       z_pos = 0.15f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[1].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f(-2.000f + game.background_scroll[1].x_pos,-2.000f + game.background_scroll[1].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f(-2.000f + game.background_scroll[1].x_pos, 2.000f + game.background_scroll[1].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f(-2.000f + game.background_scroll[0].x_pos, 2.000f + game.background_scroll[1].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f(-2.000f + game.background_scroll[0].x_pos,-2.000f + game.background_scroll[1].y_pos,z_pos);
       glEnd();
   }
   if (game.background_scroll[0].x_pos > game.background_scroll[1].x_pos)
   {
       z_pos = 0.15f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[0].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f( 2.000f + game.background_scroll[1].x_pos,-2.000f + game.background_scroll[0].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f( 2.000f + game.background_scroll[1].x_pos, 2.000f + game.background_scroll[0].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f( 2.000f + game.background_scroll[0].x_pos, 2.000f + game.background_scroll[0].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f( 2.000f + game.background_scroll[0].x_pos,-2.000f + game.background_scroll[0].y_pos,z_pos);
       glEnd();
   }
   else
   {
       z_pos = 0.15f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[0].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f(-2.000f + game.background_scroll[0].x_pos,-2.000f + game.background_scroll[0].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f(-2.000f + game.background_scroll[0].x_pos, 2.000f + game.background_scroll[0].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f(-2.000f + game.background_scroll[1].x_pos, 2.000f + game.background_scroll[0].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f(-2.000f + game.background_scroll[1].x_pos,-2.000f + game.background_scroll[0].y_pos,z_pos);
       glEnd();
   }
//--------------------------------------------------------------------------------------------------------------------------------------

    glPopMatrix();

    return(1);
};

