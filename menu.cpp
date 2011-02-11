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
#include "menu.hpp"
#include "game.hpp"

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
    glPushMatrix();

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


