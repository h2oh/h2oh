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

extern image_type   image;
extern texture_type texture[MAX_TEXTURES];
extern game_type game;
       menu_type menu;

int menu_init(void)
{
    menu.level         = 0;
    menu.position      = 0;
    menu.possition_max = 0;
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
   glTexCoord2i(0,0);glVertex3f(-1.00f, 1.00f, z_pos);
   glTexCoord2i(1,0);glVertex3f( 1.00f, 1.00f, z_pos);
   glTexCoord2i(1,1);glVertex3f( 1.00f,-1.00f, z_pos);
   glTexCoord2i(0,1);glVertex3f(-1.00f,-1.00f, z_pos);
   glEnd();
   z_pos -= 0.01f;
   glBindTexture( GL_TEXTURE_2D, texture[image.background_01].texture); //background
   glLoadIdentity();
   glBegin(GL_QUADS);
   glTexCoord2i(0,0);glVertex3f(-1.00f, 1.00f, z_pos);
   glTexCoord2i(1,0);glVertex3f( 1.00f, 1.00f, z_pos);
   glTexCoord2i(1,1);glVertex3f( 1.00f,-1.00f, z_pos);
   glTexCoord2i(0,1);glVertex3f(-1.00f,-1.00f, z_pos);
   glEnd();

   switch (menu.level)
   {
   //-------------------- Main menu -------------------------------
      case 0:
         z_pos -= 0.01f;
         //Game logo
         glBindTexture( GL_TEXTURE_2D, texture[image.game_logo].texture); //Game logo
         glLoadIdentity();
         glBegin(GL_QUADS);
         glTexCoord2i(0,0);glVertex3f(-0.95f, 0.95f, z_pos);
         glTexCoord2i(1,0);glVertex3f( 0.95f, 0.95f, z_pos);
         glTexCoord2i(1,1);glVertex3f( 0.95f, 0.65f, z_pos);
         glTexCoord2i(0,1);glVertex3f(-0.95f, 0.65f, z_pos);
         glEnd();
/*
         //New game
         glBegin(GL_QUADS);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f(-0.50f, 0.50f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f( 0.50f, 0.50f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f( 0.50f, 0.30f,0.5f);
         glColor4f(0.0f,0.0f,1.0f,0.75f);glVertex3f(-0.50f, 0.30f,0.5f);
         glEnd();
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
   glPopMatrix();
   SDL_GL_SwapBuffers();
   return(1);
}

int menu_process(void)
{
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


