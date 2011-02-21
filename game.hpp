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

struct background_scroll_type
{
   int   x_dir;
   int   y_dir;
   float x_pos;
   float y_pos;
   float scroll_rate;
};

struct game_type
{
   bool      status_menu_active;
   bool      status_game_active;
   bool      status_quit_active;
   SDL_Event event;
   bool      mouse_button_left;
   bool      mouse_button_middle;
   bool      mouse_button_right;
   float     mouse_x;
   float     mouse_y;
   float     mouse_xrel;
   float     mouse_yrel;
   background_scroll_type background_scroll[2];
};

int game_init(void);
int game_load_resources();
int game_display(void);
int game_process(void);
int game_deinit(void);
int init_gl(void);
int background_init    (void);
int background_process (void);
int background_display (void);



