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
#include <gl/gl.h>
#include "menu.hpp"
#include "game.hpp"
#include "textures.hpp"
#include "particles.hpp"
#include "music.hpp"
#include "sound.hpp"
#include "graphics.hpp"
#include "config.hpp"

extern config_type  config;
extern sfx_type     sfx;
extern sound_type   sound[MAX_SOUNDS];
extern song_type    song;
extern music_type   music[MAX_MUSIC];
extern image_type   image;
extern texture_type texture[MAX_TEXTURES];
extern game_type    game;
       menu_type    menu;

int menu_init(void)
{
    menu.level                             = 0;
    menu.position                          = 0;
    menu.possition_max                     = 5;
    menu.background_scroll[0].x_dir        = 0;
    menu.background_scroll[0].y_dir        = 0;
    menu.background_scroll[0].x_pos        = 0.0f;
    menu.background_scroll[0].y_pos        = 0.0f;
    menu.background_scroll[0].scroll_rate  = 0.0005f;
    menu.background_scroll[1].x_dir        = 1;
    menu.background_scroll[1].y_dir        = 1;
    menu.background_scroll[1].x_pos        = 0.0f;
    menu.background_scroll[1].y_pos        = 0.0f;
    menu.background_scroll[1].scroll_rate  = 0.001f;
    return(1);
}

int menu_display(void)
{
   float z_pos = 1.0f;
   SDL_ShowCursor(SDL_ENABLE); // move out when menu active so it only gets called once!
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix();
//   display_backgrounds....
   z_pos -= 0.01f;
   glBindTexture( GL_TEXTURE_2D, texture[image.background_00].texture); //background
   glLoadIdentity();
   glBegin(GL_QUADS);
   glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos,z_pos);
   glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos,z_pos);
   glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos,z_pos);
   glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos,z_pos);
   glEnd();
   z_pos -= 0.01f;
   glBindTexture( GL_TEXTURE_2D, texture[image.background_01].texture); //background
   glLoadIdentity();
   glBegin(GL_QUADS);
   glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos,z_pos);
   glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos,z_pos);
   glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos,z_pos);
   glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos,z_pos);
   glEnd();
   switch (menu.level)
   {
   //-------------------- Main menu -------------------------------
      case 0:
         z_pos -= 0.01f;
         //Game logo
         glBindTexture( GL_TEXTURE_2D, texture[image.main_logo].texture);
         glLoadIdentity();
         glBegin(GL_QUADS);
         glTexCoord2i(0,0);glVertex3f(-0.95f, 0.95f, z_pos);
         glTexCoord2i(1,0);glVertex3f( 0.95f, 0.95f, z_pos);
         glTexCoord2i(1,1);glVertex3f( 0.95f, 0.65f, z_pos);
         glTexCoord2i(0,1);glVertex3f(-0.95f, 0.65f, z_pos);
         glEnd();
         //New game
         if (menu.position == 0) glBindTexture( GL_TEXTURE_2D, texture[image.new_game_highlighted].texture);
         else                    glBindTexture( GL_TEXTURE_2D, texture[image.new_game].texture);
         glLoadIdentity();
         glBegin(GL_QUADS);
         glTexCoord2i(0,0);glVertex3f(-0.50f, 0.50f, z_pos);
         glTexCoord2i(1,0);glVertex3f( 0.50f, 0.50f, z_pos);
         glTexCoord2i(1,1);glVertex3f( 0.50f, 0.30f, z_pos);
         glTexCoord2i(0,1);glVertex3f(-0.50f, 0.30f, z_pos);
         glEnd();
         //Load game
         if (menu.position == 1) glBindTexture( GL_TEXTURE_2D, texture[image.load_game_highlighted].texture);
         else                    glBindTexture( GL_TEXTURE_2D, texture[image.load_game].texture);
         glLoadIdentity();
         glBegin(GL_QUADS);
         glTexCoord2i(0,0);glVertex3f(-0.50f, 0.25f, z_pos);
         glTexCoord2i(1,0);glVertex3f( 0.50f, 0.25f, z_pos);
         glTexCoord2i(1,1);glVertex3f( 0.50f, 0.05f, z_pos);
         glTexCoord2i(0,1);glVertex3f(-0.50f, 0.05f, z_pos);
         glEnd();
         //Save game
         if (menu.position == 2) glBindTexture( GL_TEXTURE_2D, texture[image.save_game_highlighted].texture);
         else                    glBindTexture( GL_TEXTURE_2D, texture[image.save_game].texture);
         glLoadIdentity();
         glBegin(GL_QUADS);
         glTexCoord2i(0,0);glVertex3f(-0.50f, 0.00f, z_pos);
         glTexCoord2i(1,0);glVertex3f( 0.50f, 0.00f, z_pos);
         glTexCoord2i(1,1);glVertex3f( 0.50f,-0.20f, z_pos);
         glTexCoord2i(0,1);glVertex3f(-0.50f,-0.20f, z_pos);
         glEnd();
         //Resume game
         if (menu.position == 3) glBindTexture( GL_TEXTURE_2D, texture[image.resume_game_highlighted].texture);
         else                    glBindTexture( GL_TEXTURE_2D, texture[image.resume_game].texture);
         glLoadIdentity();
         glBegin(GL_QUADS);
         glTexCoord2i(0,0);glVertex3f(-0.50f,-0.25f, z_pos);
         glTexCoord2i(1,0);glVertex3f( 0.50f,-0.25f, z_pos);
         glTexCoord2i(1,1);glVertex3f( 0.50f,-0.45f, z_pos);
         glTexCoord2i(0,1);glVertex3f(-0.50f,-0.45f, z_pos);
         glEnd();
         //Options
         if (menu.position == 4) glBindTexture( GL_TEXTURE_2D, texture[image.options_highlighted].texture);
         else                    glBindTexture( GL_TEXTURE_2D, texture[image.options].texture);
         glLoadIdentity();
         glBegin(GL_QUADS);
         glTexCoord2i(0,0);glVertex3f(-0.50f,-0.50f, z_pos);
         glTexCoord2i(1,0);glVertex3f( 0.50f,-0.50f, z_pos);
         glTexCoord2i(1,1);glVertex3f( 0.50f,-0.70f, z_pos);
         glTexCoord2i(0,1);glVertex3f(-0.50f,-0.70f, z_pos);
         glEnd();
         //Quit game
         if (menu.position == 5) glBindTexture( GL_TEXTURE_2D, texture[image.quit_game_highlighted].texture);
         else                    glBindTexture( GL_TEXTURE_2D, texture[image.quit_game].texture);
         glLoadIdentity();
         glBegin(GL_QUADS);
         glTexCoord2i(0,0);glVertex3f(-0.50f,-0.75f, z_pos);
         glTexCoord2i(1,0);glVertex3f( 0.50f,-0.75f, z_pos);
         glTexCoord2i(1,1);glVertex3f( 0.50f,-0.95f, z_pos);
         glTexCoord2i(0,1);glVertex3f(-0.50f,-0.95f, z_pos);
         glEnd();
      break;
      default:
      break;
   }
   draw_particles();
   glPopMatrix();
   SDL_GL_SwapBuffers();
   return(1);
}

//bool mouse_over_button(float bx, float bw, float by, float bh, float mx, float my); /// sunday!!!!!

bool mouse_over_button(float bx1, float bx2, float by1, float by2, float mx, float my) // just a quick hack fix sunday!!!!
{
    float bxt = 0.0f;
    float byt = 0.0f;
    if (bx1 > bx2)
    {
        bxt = bx1;
        bx1 = bx2;
        bx2 = bxt;
    };
    if (by1 > by2)
    {
        byt = by1;
        by1 = by2;
        by2 = byt;
    };
    if ((mx > bx1) && (mx < bx2) && (my > by1) && (my < by2)) return(true);
    else return(false);
};

//I know mouse is not working!!!! I will fix it on sunday, it is late and I am tied! :P lol

int menu_process(void)
{
    play_music(song.menu_001);
    background_process();
    process_particles();
    while (SDL_PollEvent(&game.event))
    {
       if (game.event.type == SDL_MOUSEMOTION)
       {
           game.mouse_button = game.event.button.button;
           game.mouse_x      = res_to_gl(game.event.motion.x,config.screen_resolution_x);
           game.mouse_y      = res_to_gl(game.event.motion.y,config.screen_resolution_y);
           game.mouse_xrel   = res_to_gl(game.event.motion.xrel,config.screen_resolution_x);
           game.mouse_yrel   = res_to_gl(game.event.motion.yrel,config.screen_resolution_y);
       }
       if (game.event.type == SDL_MOUSEBUTTONUP)
       {
           game.mouse_button = game.event.button.button;
           game.mouse_x      = res_to_gl(game.event.motion.x,config.screen_resolution_x);
           game.mouse_y      = res_to_gl(game.event.motion.y,config.screen_resolution_y);
           game.mouse_xrel   = res_to_gl(game.event.motion.xrel,config.screen_resolution_x);
           game.mouse_yrel   = res_to_gl(game.event.motion.yrel,config.screen_resolution_y);
       }
       if (game.event.type == SDL_MOUSEBUTTONDOWN)
       {
           game.mouse_button = game.event.button.button;
           game.mouse_x      = res_to_gl(game.event.motion.x,config.screen_resolution_x);
           game.mouse_y      = res_to_gl(game.event.motion.y,config.screen_resolution_y);
           game.mouse_xrel   = res_to_gl(game.event.motion.xrel,config.screen_resolution_x);
           game.mouse_yrel   = res_to_gl(game.event.motion.yrel,config.screen_resolution_y);
       }
       if (game.event.type == SDL_QUIT) game.status_quit_active = true;
       if (game.event.type == SDL_KEYDOWN)
       {
          if (game.event.key.keysym.sym == SDLK_ESCAPE)
          {
              game.status_quit_active = true;
          }
          if (game.event.key.keysym.sym == SDLK_UP)
          {
              menu.position--;
              if (menu.position < 0) menu.position = 0;
              else play_sound(sfx.menu_move);
          }
          if (game.event.key.keysym.sym == SDLK_DOWN)
          {
              menu.position++;
              if (menu.position > menu.possition_max) menu.position = menu.possition_max;
              else play_sound(sfx.menu_move);
          }
          if ((game.event.key.keysym.sym == SDLK_RETURN) || (game.event.key.keysym.sym == SDLK_SPACE))
          {
             switch (menu.level)
             {
                case 0: //main menu
                switch (menu.position)
                {
                   case 0: //new game selected
                   break;
                   case 1: //load game selected
                   break;
                   case 2: //save game selected
                   break;
                   case 3: //resume game selected
                   break;
                   case 4: //options selected
                   break;
                   case 5: //quit game selected
                      game.status_quit_active = true;
                   break;
                   default:
                   break;
                }
                break;
                default:
                break;
             }
             play_sound(sfx.menu_select);
          }
       }
    }
    // process mouse!
    //fix below on sunday!!!!!!!!
    if (mouse_over_button(-0.50f, 0.50f, 0.30f, 0.50f,game.mouse_x,game.mouse_y))
    {
        menu.position = 0;
        play_sound(sfx.menu_move);
    }
    if (mouse_over_button(-0.50f, 0.50f, 0.05f, 0.25f,game.mouse_x,game.mouse_y))
    {
        menu.position = 1;
        play_sound(sfx.menu_move);
    }
    if (mouse_over_button(-0.50f, 0.50f, 0.00f,-0.20f,game.mouse_x,game.mouse_y))
    {
        menu.position = 2;
        play_sound(sfx.menu_move);
    }
    if (mouse_over_button(-0.50f, 0.50f,-0.45f,-0.25f,game.mouse_x,game.mouse_y))
    {
        menu.position = 3;
        play_sound(sfx.menu_move);
    }
    if (mouse_over_button(-0.50f, 0.50f,-0.50f,-0.70f,game.mouse_x,game.mouse_y))
    {
        menu.position = 4;
        play_sound(sfx.menu_move);
    }
    if (mouse_over_button(-0.50f, 0.50f,-0.75f,-0.95f,game.mouse_x,game.mouse_y))
    {
        menu.position = 5;
        play_sound(sfx.menu_move);
    }
    //-----------------------------------------------------------
    return(1);
}

int background_process(void)
{
// -------------------------   background 0  -----------------------------------
   if (menu.background_scroll[0].x_dir == 0)
   {
      menu.background_scroll[0].x_pos -= menu.background_scroll[0].scroll_rate;
      if (menu.background_scroll[0].x_pos < 0.0f) menu.background_scroll[0].x_dir = 1;
   }
   if (menu.background_scroll[0].x_dir == 1)
   {
      menu.background_scroll[0].x_pos += menu.background_scroll[0].scroll_rate;
      if (menu.background_scroll[0].x_pos > 1.0f) menu.background_scroll[0].x_dir = 0;
   }

   if (menu.background_scroll[0].y_dir == 0)
   {
      menu.background_scroll[0].y_pos -= menu.background_scroll[0].scroll_rate;
      if (menu.background_scroll[0].y_pos < 0.0f) menu.background_scroll[0].y_dir = 1;
   }
   if (menu.background_scroll[0].y_dir == 1)
   {
      menu.background_scroll[0].y_pos += menu.background_scroll[0].scroll_rate;
      if (menu.background_scroll[0].y_pos > 0.75f) menu.background_scroll[0].y_dir = 0;
   }
// -------------------------   background 1  -----------------------------------
   if (menu.background_scroll[1].x_dir == 0)
   {
      menu.background_scroll[1].x_pos -= menu.background_scroll[1].scroll_rate;
      if (menu.background_scroll[1].x_pos < 0.0f) menu.background_scroll[1].x_dir = 1;
   }
   if (menu.background_scroll[1].x_dir == 1)
   {
      menu.background_scroll[1].x_pos += menu.background_scroll[1].scroll_rate;
      if (menu.background_scroll[1].x_pos > 1.0f) menu.background_scroll[1].x_dir = 0;
   }

   if (menu.background_scroll[1].y_dir == 0)
   {
      menu.background_scroll[1].y_pos -= menu.background_scroll[1].scroll_rate;
      if (menu.background_scroll[1].y_pos < 0.0f) menu.background_scroll[1].y_dir = 1;
   }
   if (menu.background_scroll[1].y_dir == 1)
   {
      menu.background_scroll[1].y_pos += menu.background_scroll[1].scroll_rate;
      if (menu.background_scroll[1].y_pos > 0.75f) menu.background_scroll[1].y_dir = 0;
   }
   return(1);
}
