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
   int background_00;
   int background_01;
   int particle_flake;
};

int init_textures(void);
int load_texture (int texture_number, const char File_Name[]);
int load_textures(void);
int kill_textures(void);

