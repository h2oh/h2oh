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

#include <gl/gl.h>

const int MAX_TEXTURES = 32;
struct texture_type
{
   GLuint texture;
};

struct image_type
{
   int main_logo;
   int new_game;
   int new_game_highlighted;
   int save_game;
   int save_game_highlighted;
   int load_game;
   int load_game_highlighted;
   int resume_game;
   int resume_game_highlighted;
   int quit_game;
   int quit_game_highlighted;
   int options;
   int options_highlighted;
   int main_menu;
   int main_menu_highlighted;
   int game_0;
   int game_0_highlighted;
   int game_1;
   int game_1_highlighted;
   int game_2;
   int game_2_highlighted;
   int game_3;
   int game_3_highlighted;
   int game_4;
   int game_4_highlighted;
   int game_5;
   int game_5_highlighted;
   int options_menu;
   int options_menu_highlighted;
   int audio;
   int audio_highlighted;
   int graphics;
   int graphics_highlighted;
   int keyboard;
   int keyboard_highlighted;
   int mouse;
   int mouse_highlighted;
   int gamepad;
   int gamepad_highlighted;
   int arrow_left;
   int arrow_left_highlighted;
   int arrow_right;
   int arrow_right_highlighted;
   int bar;
   int bar_highlighted;
   int slider_bar_top;
   int slider_bar_bottom;
   int background_00;
   int background_01;
   int particle_flake;
};

int init_textures(void);
int load_texture (int texture_number, const char File_Name[]);
int load_textures(void);
int kill_textures(void);

