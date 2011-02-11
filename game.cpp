/* Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "h2oh"
 *
 * "h2oh" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * "h2oh" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "h2oh" If not, see <http://www.gnu.org/licenses/>.
 */

#include <SDL/SDL.h>
#include <gl/gl.h>
#include "game.hpp"
#include "config.hpp"

extern config_type config;

const char App_Name[] = "h20h";
const char App_Icon[] = "data/icon.bmp";

game_type    game;
Uint32       colorkey;
SDL_Surface *App_Icon_Surface;

int game_init(void)
{
   game.status_menu_active = true;
   game.status_game_active = false;
   game.status_quit_active = false;
   init_config();
   //----------------------------------- SDL Video --------------------------------
   SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD);
   if (config.screen_fullscreen) SDL_SetVideoMode(config.screen_resolution_x,config.screen_resolution_y,config.screen_bbp,SDL_OPENGL | SDL_FULLSCREEN);
   else                          SDL_SetVideoMode(config.screen_resolution_x,config.screen_resolution_y,config.screen_bbp,SDL_OPENGL);
   if (config.screen_double_buffering) SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
   App_Icon_Surface = SDL_LoadBMP(App_Icon);
   colorkey = SDL_MapRGB(App_Icon_Surface->format, 255, 0, 255);
   SDL_SetColorKey(App_Icon_Surface, SDL_SRCCOLORKEY, colorkey);
   SDL_WM_SetIcon(App_Icon_Surface,NULL);
   SDL_WM_SetCaption(App_Name, 0);
   SDL_ShowCursor(SDL_DISABLE);
   //----------------------------------- SDL Audio --------------------------------
   SDL_Init(SDL_INIT_AUDIO);
   return(1);
}

int game_display(void)
{
    glPushMatrix();

    glPopMatrix();
    SDL_GL_SwapBuffers();
    return(1);
}

int game_process(void)
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

int game_deinit(void)
{
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
  return(0);
}
