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
#include "physics.hpp"
#include "savegame.hpp"

extern config_type  config;
extern sfx_type     sfx;
extern sound_type   sound[MAX_SOUNDS];
extern song_type    song;
extern music_type   music[MAX_MUSIC];
extern image_type   image;
extern texture_type texture[MAX_TEXTURES];
extern game_type    game;
       menu_type    menu;


int menu_system_init(void)
{
    int level_count  = 0;
    int button_count = 0;
    ///--------------main menu init -----------------------
    level_count  = 0;//level 0
    button_count = 0;
    menu.level[level_count].possition_x                                  =  0.00f;
    menu.level[level_count].possition_y                                  =  1.00f;
    menu.level[level_count].no_of_buttons                                =  5;
    menu.level[level_count].button_spacing                               =  0.025f;
    menu.level[level_count].button_width                                 =  1.00f;
    menu.level[level_count].button_height                                =  0.20f;
    menu.level[level_count].type_normal                                  =  true;
    menu.level[level_count].type_button_zoom                             =  true;
    menu.level[level_count].logo.drag                                    =  false;
    menu.level[level_count].logo.image                                   =  image.main_logo;
    menu.level[level_count].logo.height                                  =  0.40f;
    menu.level[level_count].logo.width                                   =  1.20f;
    menu.level[level_count].logo.possition_x                             =  menu.level[level_count].possition_x;
    menu.level[level_count].logo.possition_y                             =  menu.level[level_count].possition_y-(menu.level[level_count].logo.height/2);
    button_count = 0;//button 0
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.new_game;
    menu.level[level_count].button[button_count].image_highlighted       =  image.new_game_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 1;//button 1
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.load_game;
    menu.level[level_count].button[button_count].image_highlighted       =  image.load_game_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 2;//button 2
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.save_game;
    menu.level[level_count].button[button_count].image_highlighted       =  image.save_game_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 3;//button 3
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.resume_game;
    menu.level[level_count].button[button_count].image_highlighted       =  image.resume_game_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 4;//button 4
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.options;
    menu.level[level_count].button[button_count].image_highlighted       =  image.options_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 5;//button 5
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.quit_game;
    menu.level[level_count].button[button_count].image_highlighted       =  image.quit_game_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    ///-------------load game menu init -----------------------
    level_count  = 1;//level 1
    button_count = 0;
    menu.level[level_count].possition_x                                  =  menu.level[0].possition_x;
    menu.level[level_count].possition_y                                  =  menu.level[0].possition_y;
    menu.level[level_count].no_of_buttons                                =  menu.level[0].no_of_buttons;
    menu.level[level_count].button_spacing                               =  menu.level[0].button_spacing;
    menu.level[level_count].button_width                                 =  menu.level[0].button_width;
    menu.level[level_count].button_height                                =  menu.level[0].button_height;
    menu.level[level_count].type_normal                                  =  menu.level[0].type_normal;
    menu.level[level_count].type_button_zoom                             =  menu.level[0].type_button_zoom;
    menu.level[level_count].logo.drag                                    =  menu.level[0].logo.drag;
    menu.level[level_count].logo.image                                   =  image.load_game_highlighted;
    menu.level[level_count].logo.height                                  =  menu.level[0].logo.height;
    menu.level[level_count].logo.width                                   =  menu.level[0].logo.width;
    menu.level[level_count].logo.possition_x                             =  menu.level[0].possition_x;
    menu.level[level_count].logo.possition_y                             =  menu.level[0].possition_y-(menu.level[level_count].logo.height/2);
    button_count = 0;//button 0
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.game_0;
    menu.level[level_count].button[button_count].image_highlighted       =  image.game_0_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 1;//button 1
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.game_1;
    menu.level[level_count].button[button_count].image_highlighted       =  image.game_1_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 2;//button 2
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.game_2;
    menu.level[level_count].button[button_count].image_highlighted       =  image.game_2_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 3;//button 3
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.game_3;
    menu.level[level_count].button[button_count].image_highlighted       =  image.game_3_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 4;//button 4
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.game_4;
    menu.level[level_count].button[button_count].image_highlighted       =  image.game_4_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 5;//button 5
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.main_menu;
    menu.level[level_count].button[button_count].image_highlighted       =  image.main_menu_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    ///-------------Save game menu init -----------------------
    level_count  = 2;//level 2
    button_count = 0;
    menu.level[level_count].possition_x                                  =  menu.level[0].possition_x;
    menu.level[level_count].possition_y                                  =  menu.level[0].possition_y;
    menu.level[level_count].no_of_buttons                                =  menu.level[0].no_of_buttons;
    menu.level[level_count].button_spacing                               =  menu.level[0].button_spacing;
    menu.level[level_count].button_width                                 =  menu.level[0].button_width;
    menu.level[level_count].button_height                                =  menu.level[0].button_height;
    menu.level[level_count].type_normal                                  =  menu.level[0].type_normal;
    menu.level[level_count].type_button_zoom                             =  menu.level[0].type_button_zoom;
    menu.level[level_count].logo.drag                                    =  menu.level[0].logo.drag;
    menu.level[level_count].logo.image                                   =  image.save_game_highlighted;
    menu.level[level_count].logo.height                                  =  menu.level[0].logo.height;
    menu.level[level_count].logo.width                                   =  menu.level[0].logo.width;
    menu.level[level_count].logo.possition_x                             =  menu.level[0].possition_x;
    menu.level[level_count].logo.possition_y                             =  menu.level[0].possition_y-(menu.level[level_count].logo.height/2);
    button_count = 0;//button 0
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.game_0;
    menu.level[level_count].button[button_count].image_highlighted       =  image.game_0_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 1;//button 1
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.game_1;
    menu.level[level_count].button[button_count].image_highlighted       =  image.game_1_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 2;//button 2
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.game_2;
    menu.level[level_count].button[button_count].image_highlighted       =  image.game_2_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 3;//button 3
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.game_3;
    menu.level[level_count].button[button_count].image_highlighted       =  image.game_3_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 4;//button 4
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.game_4;
    menu.level[level_count].button[button_count].image_highlighted       =  image.game_4_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    button_count = 5;//button 5
    menu.level[level_count].button[button_count].button_zoom             =  0.00f;
    menu.level[level_count].button[button_count].image                   =  image.main_menu;
    menu.level[level_count].button[button_count].image_highlighted       =  image.main_menu_highlighted;
    menu.level[level_count].button[button_count].type_normal             =  true;
    menu.level[level_count].button[button_count].type_toggle             =  false;
    menu.level[level_count].button[button_count].type_horizontal_sellect =  false;
    //menu general settings ---------------------------------------------------------------------------------
    game.mouse_button_left                 = false;
    game.mouse_button_middle               = false;
    game.mouse_button_right                = false;
    menu.last_sellect                      = -1;
    menu.current_level                     = 0;
    menu.current_button                    = 0;
    menu.button_zoom_speed                 = 0.01f;
    menu.button_zoom_max                   = menu.level[level_count].button_spacing * 1.0;
    //-------------------------------------------------------------------------------------------------------
    return(1);
}

int menu_system_display(void)
{
   float t_z_pos = 0.0f;
   float z_pos   = 1.0f;
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   //-------------------- Display menu -------------------------------
   z_pos -= 0.01f;
   //Menu logo
   glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].logo.image].texture);
   glLoadIdentity();
   glBegin(GL_QUADS);
   glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].logo.possition_x-(menu.level[menu.current_level].logo.width/2),menu.level[menu.current_level].logo.possition_y+(menu.level[menu.current_level].logo.height/2), z_pos);
   glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].logo.possition_x+(menu.level[menu.current_level].logo.width/2),menu.level[menu.current_level].logo.possition_y+(menu.level[menu.current_level].logo.height/2), z_pos);
   glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].logo.possition_x+(menu.level[menu.current_level].logo.width/2),menu.level[menu.current_level].logo.possition_y-(menu.level[menu.current_level].logo.height/2), z_pos);
   glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].logo.possition_x-(menu.level[menu.current_level].logo.width/2),menu.level[menu.current_level].logo.possition_y-(menu.level[menu.current_level].logo.height/2), z_pos);
   glEnd();
   z_pos -= 0.03f;
   for(int button_count = 0;button_count < menu.level[menu.current_level].no_of_buttons+1; button_count++)
   {
      if (menu.current_button == button_count) t_z_pos = z_pos -= 0.01f;
      else t_z_pos = z_pos;
      if (menu.current_button == button_count) glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_highlighted].texture);
      else glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image].texture);
         glLoadIdentity();
         glBegin(GL_QUADS);
         glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].possition_x-(menu.level[menu.current_level].button_width/2)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.possition_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
         glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].possition_x+(menu.level[menu.current_level].button_width/2)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.possition_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
         glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].possition_x+(menu.level[menu.current_level].button_width/2)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.possition_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
         glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].possition_x-(menu.level[menu.current_level].button_width/2)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.possition_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
         glEnd();
    }
   draw_particles();
   glPopMatrix();
   SDL_GL_SwapBuffers();
   return(1);
}

bool mouse_over_button(int level_count, int button_count, float mouse_x, float mouse_y)
{
   if ((mouse_x > menu.level[level_count].possition_x-(menu.level[level_count].button_width/2)-menu.level[level_count].button[button_count].button_zoom)
    && (mouse_x < menu.level[level_count].possition_x+(menu.level[level_count].button_width/2)+menu.level[level_count].button[button_count].button_zoom)
    && (mouse_y > (menu.level[menu.current_level].logo.possition_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom)
    && (mouse_y < (menu.level[menu.current_level].logo.possition_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom))
   return(true);
   else return(false);
};

bool mouse_over_logo(int level_count, float mouse_x, float mouse_y)
{
   if ((mouse_x > menu.level[level_count].logo.possition_x-(menu.level[level_count].logo.width/2))
    && (mouse_x < menu.level[level_count].logo.possition_x+(menu.level[level_count].logo.width/2))
    && (mouse_y > menu.level[level_count].logo.possition_y-(menu.level[level_count].logo.height/2))
    && (mouse_y < menu.level[level_count].logo.possition_y+(menu.level[level_count].logo.height/2)))
   return(true);
   else return(false);
}

int menu_system_process(void)
{
    int button_count = 0;
    play_music(song.menu_001);
    background_process();
    process_particles();
    while (SDL_PollEvent(&game.event))
    {
       if (game.event.type == SDL_MOUSEMOTION)
       {
           game.mouse_x      = res_to_gl(game.event.motion.x,config.screen_resolution_x);
           game.mouse_y      = res_to_gl(game.event.motion.y,config.screen_resolution_y);
           game.mouse_xrel   = res_to_gl(game.event.motion.xrel,config.screen_resolution_x);
           game.mouse_yrel   = res_to_gl(game.event.motion.yrel,config.screen_resolution_y);
           if (!config.screen_fullscreen) game.mouse_y *= -1;
       }
       if (game.event.type == SDL_MOUSEBUTTONUP)
       {
           switch(game.event.button.button)
           {
              case 1:
                game.mouse_button_left = false;
              break;
              case 2:
                game.mouse_button_middle = false;
              break;
              case 3:
                game.mouse_button_right = false;
              break;
              default:
              break;
           }
       }
       if (game.event.type == SDL_MOUSEBUTTONDOWN)
       {
           switch(game.event.button.button)
           {
              case 1:
                game.mouse_button_left = true;
              break;
              case 2:
                game.mouse_button_middle = true;
              break;
              case 3:
                game.mouse_button_right = true;
              break;
              default:
              break;
           }
       }
       if (game.event.type == SDL_QUIT) game.status_quit_active = true;
       if (game.event.type == SDL_KEYDOWN)
       {
          if (game.event.key.keysym.sym == SDLK_ESCAPE)
          {
             switch (menu.current_level)
             {
                case 0: //main menu
                   game.status_quit_active = true;
                break;
                case 1: //load game menu
                   menu.current_level       = 0;
                   menu.current_button      = 1;
                   game.mouse_button_left   = false;
                   game.mouse_button_middle = false;
                   game.mouse_button_right  = false;
                   menu.last_sellect        = -1;
                   play_sound(sfx.menu_select);
                break;
                case 2: //save game menu
                   menu.current_level       = 0;
                   menu.current_button      = 2;
                   game.mouse_button_left   = false;
                   game.mouse_button_middle = false;
                   game.mouse_button_right  = false;
                   menu.last_sellect        = -1;
                   play_sound(sfx.menu_select);
                break;
                case 3: //options menu
                   menu.current_level       = 0;
                   menu.current_button      = 4;
                   game.mouse_button_left   = false;
                   game.mouse_button_middle = false;
                   game.mouse_button_right  = false;
                   menu.last_sellect        = -1;
                   play_sound(sfx.menu_select);
                break;
             }
          }
          if (game.event.key.keysym.sym == SDLK_UP)
          {
              menu.current_button--;
              if (menu.current_button < 0) menu.current_button = 0;
              else play_sound(sfx.menu_move);
          }
          if (game.event.key.keysym.sym == SDLK_DOWN)
          {
              menu.current_button++;
              if (menu.current_button > menu.level[menu.current_level].no_of_buttons) menu.current_button = menu.level[menu.current_level].no_of_buttons;
              else play_sound(sfx.menu_move);
          }
          if ((game.event.key.keysym.sym == SDLK_RETURN) || (game.event.key.keysym.sym == SDLK_SPACE))
          {
             switch (menu.current_level)
             {
                case 0: //main menu
                switch (menu.current_button)
                {
                   case 0: //new game selected
                      game_init();
                      SDL_ShowCursor(SDL_DISABLE);
                      game.status_menu_active  = false;
                      game.status_game_active  = true;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      play_sound(sfx.menu_select);
                   break;
                   case 1: //load game selected
                      menu.current_level       = 1;
                      menu.current_button      = 0;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      play_sound(sfx.menu_select);
                   break;
                   case 2: //save game selected
                      menu.current_level       = 2;
                      menu.current_button      = 0;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      play_sound(sfx.menu_select);
                   break;
                   case 3: //resume game selected
                      SDL_ShowCursor(SDL_DISABLE);
                      game.status_menu_active  = false;
                      game.status_game_active  = true;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      play_sound(sfx.menu_select);
                   break;
                   case 4: //options selected
                      menu.current_level       = 3;
                      menu.current_button      = 0;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      play_sound(sfx.menu_select);
                   break;
                   case 5: //quit game selected
                      game.status_quit_active = true;
                   break;
                   default:
                   break;
                }
                break;
                case 1: //Load game menu
                switch (menu.current_button)
                {
                   case 0: //load game 0
                      game_init();
                      Load_Game(button_count);
                      SDL_ShowCursor(SDL_DISABLE);
                      game.status_menu_active  = false;
                      game.status_game_active  = true;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      menu.last_sellect        = -1;
                      play_sound(sfx.menu_select);
                   break;
                   case 1: //load game 1
                      game_init();
                      Load_Game(button_count);
                      SDL_ShowCursor(SDL_DISABLE);
                      game.status_menu_active  = false;
                      game.status_game_active  = true;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      menu.last_sellect        = -1;
                      play_sound(sfx.menu_select);
                   break;
                   case 2: //load game 2
                      game_init();
                      Load_Game(button_count);
                      SDL_ShowCursor(SDL_DISABLE);
                      game.status_menu_active  = false;
                      game.status_game_active  = true;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      menu.last_sellect        = -1;
                      play_sound(sfx.menu_select);
                   break;
                   case 3: //load game 3
                      game_init();
                      Load_Game(button_count);
                      SDL_ShowCursor(SDL_DISABLE);
                      game.status_menu_active  = false;
                      game.status_game_active  = true;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      menu.last_sellect        = -1;
                      play_sound(sfx.menu_select);
                   break;
                   case 4: //load game 4
                      game_init();
                      Load_Game(button_count);
                      SDL_ShowCursor(SDL_DISABLE);
                      game.status_menu_active  = false;
                      game.status_game_active  = true;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      menu.last_sellect        = -1;
                      play_sound(sfx.menu_select);
                   break;
                   case 5: //back to main menu
                      menu.current_level       = 0;
                      menu.current_button      = 1;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      menu.last_sellect        = -1;
                      play_sound(sfx.menu_select);
                   break;
                   default:
                   break;
                }
                break;
                case 2: //Save game menu
                switch (menu.current_button)
                {
                   case 0: //Save game 0
                      game_init();
                      Load_Game(button_count);
                      SDL_ShowCursor(SDL_DISABLE);
                      game.status_menu_active  = false;
                      game.status_game_active  = true;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      menu.last_sellect        = -1;
                      play_sound(sfx.menu_select);
                   break;
                   case 1: //Save game 1
                      game_init();
                      Load_Game(button_count);
                      SDL_ShowCursor(SDL_DISABLE);
                      game.status_menu_active  = false;
                      game.status_game_active  = true;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      menu.last_sellect        = -1;
                      play_sound(sfx.menu_select);
                   break;
                   case 2: //Save game 2
                      game_init();
                      Load_Game(button_count);
                      SDL_ShowCursor(SDL_DISABLE);
                      game.status_menu_active  = false;
                      game.status_game_active  = true;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      menu.last_sellect        = -1;
                      play_sound(sfx.menu_select);
                   break;
                   case 3: //Save game 3
                      game_init();
                      Load_Game(button_count);
                      SDL_ShowCursor(SDL_DISABLE);
                      game.status_menu_active  = false;
                      game.status_game_active  = true;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      menu.last_sellect        = -1;
                      play_sound(sfx.menu_select);
                   break;
                   case 4: //Save game 4
                      game_init();
                      Load_Game(button_count);
                      SDL_ShowCursor(SDL_DISABLE);
                      game.status_menu_active  = false;
                      game.status_game_active  = true;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      menu.last_sellect        = -1;
                      play_sound(sfx.menu_select);
                   break;
                   case 5: //back to main menu
                      menu.current_level       = 0;
                      menu.current_button      = 1;
                      game.mouse_button_left   = false;
                      game.mouse_button_middle = false;
                      game.mouse_button_right  = false;
                      menu.last_sellect        = -1;
                      play_sound(sfx.menu_select);
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
    //-------------------- Mouse -------------------------------
    if (mouse_over_logo(menu.current_level,game.mouse_x,game.mouse_y))//drag menu? :P
    {
        if (game.mouse_button_left)
        {
           if (!menu.level[menu.current_level].logo.drag)
           {
               menu.level[menu.current_level].logo.drag_offset_x = game.mouse_x - menu.level[menu.current_level].logo.possition_x;
               menu.level[menu.current_level].logo.drag_offset_y = game.mouse_y - menu.level[menu.current_level].logo.possition_y;
               menu.level[menu.current_level].logo.drag = true;
           }
           else
           {
               menu.level[menu.current_level].logo.possition_x = game.mouse_x - menu.level[menu.current_level].logo.drag_offset_x;
               menu.level[menu.current_level].logo.possition_y = game.mouse_y - menu.level[menu.current_level].logo.drag_offset_y;
               menu.level[menu.current_level].possition_x = menu.level[menu.current_level].logo.possition_x;
               for(int level_count = 0;level_count < MAX_LEVELS;level_count++)
               {
                  menu.level[level_count].logo.possition_x = menu.level[menu.current_level].logo.possition_x;
                  menu.level[level_count].logo.possition_y = menu.level[menu.current_level].logo.possition_y;
                  menu.level[level_count].possition_x = menu.level[menu.current_level].possition_x;
               }
           }
        }
        else
        {
            menu.level[menu.current_level].logo.drag = false;
        }
    }
    if (!menu.level[menu.current_level].logo.drag) switch (menu.current_level)
    {
    //-------------------- Main menu -------------------------------
      case 0:
         button_count = 0;// new game
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               game_init();
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 1;//load game
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               menu.current_level       = 1;
               menu.current_button      = 0;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 2;//save game
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               menu.current_level       = 2;
               menu.current_button      = 0;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 3;//resume game
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = button_count;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 4;//options
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               menu.current_level       = 3;
               menu.current_button      = 0;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 5;//quit game
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               menu.last_sellect = button_count;
               play_sound(sfx.menu_select);
               game.status_quit_active = true;
            }
         }
      break;
    //-------------------- Load game menu -------------------------------
      case 1:
         button_count = 0;// load game 0
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 1;// load game 1
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 2;// load game 2
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 3;// load game 3
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 4;// load game 4
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 5;//back to main menu
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               menu.current_level       = 0;
               menu.current_button      = 1;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
        break;
    //-------------------- Save game menu -------------------------------
      case 2:
         button_count = 0;// save game 0
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               game_init();
               Save_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 1;// save game 1
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               game_init();
               Save_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 2;// save game 2
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               game_init();
               Save_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 3;// save game 3
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               game_init();
               Save_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 4;// save game 4
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               game_init();
               Save_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
         button_count = 5;//back to main menu
         if (mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y))
         {
            if (menu.current_button != button_count)
            {
               menu.last_sellect = -1;
               menu.current_button = button_count;
               play_sound(sfx.menu_move);
            }
            if ((game.mouse_button_left) && (menu.last_sellect != button_count))
            {
               menu.current_level       = 0;
               menu.current_button      = 2;
               game.mouse_button_left   = false;
               game.mouse_button_middle = false;
               game.mouse_button_right  = false;
               menu.last_sellect        = -1;
               play_sound(sfx.menu_select);
            }
         }
        break;
        default:
        break;
    }
    if(menu.level[menu.current_level].type_button_zoom) //if button zoom type, process zoom
    {
       for(int button_count = 0;button_count < menu.level[menu.current_level].no_of_buttons+1; button_count++)
       {
           if(menu.current_button == button_count)
           {
               menu.level[menu.current_level].button[button_count].button_zoom += menu.button_zoom_speed;
               if(menu.level[menu.current_level].button[button_count].button_zoom > menu.button_zoom_max) menu.level[menu.current_level].button[button_count].button_zoom = menu.button_zoom_max;
           }
           else
           {
               menu.level[menu.current_level].button[button_count].button_zoom -= menu.button_zoom_speed;
               if(menu.level[menu.current_level].button[button_count].button_zoom < 0.0f) menu.level[menu.current_level].button[button_count].button_zoom = 0.0f;
           }
       }
    }
    return(1);
}
