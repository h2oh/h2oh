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
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "textures.hpp"
#include "game.hpp"
#include "config.hpp"

#define GL_BGR  0x80E0
#define GL_BGRA 0x80E1
image_type   image;
texture_type texture[MAX_TEXTURES];
const char App_LogF[] = "H2oH.log";

int load_textures(void)
{
   int texture_count = 0;
   load_texture(texture_count,"data/textures/menu/main_logo.png");image.main_logo = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/new_game.png");image.new_game = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/new_game_highlighted.png");image.new_game_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/save_game.png");image.save_game = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/save_game_highlighted.png");image.save_game_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/load_game.png");image.load_game = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/load_game_highlighted.png");image.load_game_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/resume_game.png");image.resume_game = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/resume_game_highlighted.png");image.resume_game_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/quit_game.png");image.quit_game = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/quit_game_highlighted.png");image.quit_game_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/options.png");image.options = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/options_highlighted.png");image.options_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/main_menu.png");image.main_menu = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/main_menu_highlighted.png");image.main_menu_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_0.png");image.game_0 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_0_highlighted.png");image.game_0_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_1.png");image.game_1 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_1_highlighted.png");image.game_1_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_2.png");image.game_2 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_2_highlighted.png");image.game_2_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_3.png");image.game_3 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_3_highlighted.png");image.game_3_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_4.png");image.game_4 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_4_highlighted.png");image.game_4_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_5.png");image.game_5 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_5_highlighted.png");image.game_5_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/backgrounds/background_00.png");image.background_00 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/backgrounds/background_01.png");image.background_01 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/particles/flake.png");image.particle_flake = texture_count;texture_count++;
   return(1);
};

int init_textures(void)
{
   for(int count = 0; count < MAX_TEXTURES; count++)
   {
      texture[count].texture = texture[count].texture;
   }
   return(1);
};

int kill_textures(void)
{
   for(int count = 0; count < MAX_TEXTURES; count++)
   {
      glDeleteTextures(1, &texture[count].texture);
   }
   return(1);
};

int load_texture (int texture_number, const char File_Name[])
{
   SDL_Surface *surface;
   GLenum       texture_format = GL_RGBA;
   GLint        no_of_colors;

   if ((surface = IMG_Load(File_Name)))
   {
      if ((surface->w & (surface->w - 1)) != 0 );
      if ((surface->h & (surface->h - 1)) != 0 );
      no_of_colors = surface->format->BytesPerPixel;
      if (no_of_colors == 4)
      {
         if (surface->format->Rmask == 0x000000ff) texture_format = GL_RGBA;
         else texture_format = GL_BGRA;
      }
      else if (no_of_colors == 3)
      {
         if (surface->format->Rmask == 0x000000ff) texture_format = GL_RGB;
         else texture_format = GL_BGR;
      }
      else write_log_file(App_LogF,"The image is not 24bit...");
      glGenTextures( 1, &texture[texture_number].texture);
      glBindTexture( GL_TEXTURE_2D, texture[texture_number].texture);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
      glTexImage2D( GL_TEXTURE_2D, 0, no_of_colors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels );
   }
   else
   {
      write_log_file(App_LogF,"SDL could not load image.");
      SDL_Quit();
      return(0);
   }
   if (surface) SDL_FreeSurface(surface);
   return(1);
}
