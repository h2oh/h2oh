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

extern sound_type sound[MAX_SOUNDS];
extern music_type music[MAX_MUSIC];
extern image_type   image;
extern texture_type texture[MAX_TEXTURES];
extern game_type game;
       menu_type menu;

int menu_init(void)
{
    menu.level                             = 0;
    menu.position                          = 0;
    menu.possition_max                     = 0;
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
         glBindTexture( GL_TEXTURE_2D, texture[image.game_logo].texture);
         glLoadIdentity();
         glBegin(GL_QUADS);
         glTexCoord2i(0,0);glVertex3f(-0.95f, 0.95f, z_pos);
         glTexCoord2i(1,0);glVertex3f( 0.95f, 0.95f, z_pos);
         glTexCoord2i(1,1);glVertex3f( 0.95f, 0.65f, z_pos);
         glTexCoord2i(0,1);glVertex3f(-0.95f, 0.65f, z_pos);
         glEnd();
         //New game
         glBindTexture( GL_TEXTURE_2D, texture[image.game_logo].texture);
         glLoadIdentity();
         glBegin(GL_QUADS);
         glTexCoord2i(0,0);glVertex3f(-0.50f, 0.50f,0.5f);
         glTexCoord2i(1,0);glVertex3f( 0.50f, 0.50f,0.5f);
         glTexCoord2i(1,1);glVertex3f( 0.50f, 0.30f,0.5f);
         glTexCoord2i(0,1);glVertex3f(-0.50f, 0.30f,0.5f);
         glEnd();
/*
         //Load game
         glBegin(GL_QUADS);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f(-0.50f, 0.25f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f( 0.50f, 0.25f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f( 0.50f, 0.05f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f(-0.50f, 0.05f,0.5f);
         glEnd();
         //Save game
         glBegin(GL_QUADS);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f(-0.50f, 0.00f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f( 0.50f, 0.00f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f( 0.50f,-0.20f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f(-0.50f,-0.20f,0.5f);
         glEnd();
         //Resume game
         glBegin(GL_QUADS);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f(-0.50f,-0.25f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f( 0.50f,-0.25f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f( 0.50f,-0.45f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f(-0.50f,-0.45f,0.5f);
         glEnd();
         //Options
         glBegin(GL_QUADS);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f(-0.50f,-0.50f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f( 0.50f,-0.50f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f( 0.50f,-0.70f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f(-0.50f,-0.70f,0.5f);
         glEnd();
         //Quit game
         glBegin(GL_QUADS);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f(-0.50f,-0.75f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f( 0.50f,-0.75f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f( 0.50f,-0.95f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f(-0.50f,-0.95f,0.5f);
         glEnd();
*/
      break;
      default:
      // thrown error
      break;
   }
   draw_particles();
   glPopMatrix();
   SDL_GL_SwapBuffers();
   return(1);
}

int menu_process(void)
{
    background_process();
    process_particles();
    while (SDL_PollEvent(&game.event))
    {
       if (game.event.type == SDL_QUIT) game.status_quit_active = true;
       if (game.event.type == SDL_KEYDOWN)
       {
          if (game.event.key.keysym.sym == SDLK_ESCAPE)
          {
              game.status_quit_active = true;
          }
       }
    }
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
