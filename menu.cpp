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
/*0A0A55*/

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
    menu.level[level_count].type_normal                                              =  true;
    menu.level[level_count].type_button_zoom                                         =  true;
    menu.level[level_count].type_button_fade                                         =  true;
    menu.level[level_count].logo.drag                                                =  false;
    menu.level[level_count].logo.image                                               =  image.main_logo;
    menu.level[level_count].no_of_buttons                                            =  5;
    menu.level[level_count].position_x                                               =  0.00f;
    menu.level[level_count].position_y                                               =  1.00f-(menu.level[level_count].no_of_buttons*0.01f);
    menu.level[level_count].logo.width                                               =  (0.15f*menu.level[level_count].no_of_buttons);
    menu.level[level_count].logo.height                                              =  (menu.level[level_count].logo.width/2);
    menu.level[level_count].logo.position_x                                          =  menu.level[level_count].position_x;
    menu.level[level_count].logo.position_y                                          =  menu.level[level_count].position_y-(menu.level[level_count].logo.height/2);
    menu.level[level_count].button_width                                             =  ((menu.level[level_count].logo.width/6)*5);
    menu.level[level_count].button_height                                            =  (menu.level[level_count].button_width/3);
    menu.level[level_count].button_spacing                                           =  (menu.level[level_count].button_height/8);
    for (button_count=0;button_count<MAX_BUTTONS+1;button_count++)
    {
       menu.level[level_count].button[button_count].button_zoom                      =  0.00f;
       menu.level[level_count].button[button_count].button_fade                      =  menu.button_fade_max;
       menu.level[level_count].button[button_count].type_normal                      =  true;
       menu.level[level_count].button[button_count].type_select                      =  false;
       menu.level[level_count].button[button_count].type_slider                      =  false;
    }
    button_count = 0;//button 0
    menu.level[level_count].button[button_count].image                               =  image.new_game;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.new_game_highlighted;
    button_count = 1;//button 1
    menu.level[level_count].button[button_count].image                               =  image.load_game;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.load_game_highlighted;
    button_count = 2;//button 2
    menu.level[level_count].button[button_count].image                               =  image.save_game;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.save_game_highlighted;
    button_count = 3;//button 3
    menu.level[level_count].button[button_count].image                               =  image.resume_game;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.resume_game_highlighted;
    button_count = 4;//button 4
    menu.level[level_count].button[button_count].image                               =  image.options;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.options_highlighted;
    button_count = 5;//button 5
    menu.level[level_count].button[button_count].image                               =  image.quit_game;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.quit_game_highlighted;
    ///-------------load game menu init -----------------------
    level_count  = 1;//level 1
    button_count = 0;
    menu.level[level_count].position_x                                               =  menu.level[0].position_x;
    menu.level[level_count].position_y                                               =  menu.level[0].position_y;
    menu.level[level_count].no_of_buttons                                            =  menu.level[0].no_of_buttons;
    menu.level[level_count].button_spacing                                           =  menu.level[0].button_spacing;
    menu.level[level_count].button_width                                             =  menu.level[0].button_width;
    menu.level[level_count].button_height                                            =  menu.level[0].button_height;
    menu.level[level_count].type_normal                                              =  menu.level[0].type_normal;
    menu.level[level_count].type_button_zoom                                         =  menu.level[0].type_button_zoom;
    menu.level[level_count].type_button_fade                                         =  menu.level[0].type_button_fade;
    menu.level[level_count].logo.drag                                                =  menu.level[0].logo.drag;
    menu.level[level_count].logo.image                                               =  image.load_game_highlighted;
    menu.level[level_count].logo.height                                              =  menu.level[0].logo.height;
    menu.level[level_count].logo.width                                               =  menu.level[0].logo.width;
    menu.level[level_count].logo.position_x                                          =  menu.level[0].position_x;
    menu.level[level_count].logo.position_y                                          =  menu.level[0].position_y-(menu.level[level_count].logo.height/2);
    for (button_count=0;button_count<MAX_BUTTONS+1;button_count++)
    {
       menu.level[level_count].button[button_count].button_zoom                      =  0.00f;
       menu.level[level_count].button[button_count].button_fade                      =  menu.button_fade_max;
       menu.level[level_count].button[button_count].type_normal                      =  true;
       menu.level[level_count].button[button_count].type_select                      =  false;
       menu.level[level_count].button[button_count].type_slider                      =  false;
    }
    button_count = 0;//button 0
    menu.level[level_count].button[button_count].image                               =  image.game_0;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.game_0_highlighted;
    button_count = 1;//button 1
    menu.level[level_count].button[button_count].image                               =  image.game_1;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.game_1_highlighted;
    button_count = 2;//button 2
    menu.level[level_count].button[button_count].image                               =  image.game_2;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.game_2_highlighted;
    button_count = 3;//button 3
    menu.level[level_count].button[button_count].image                               =  image.game_3;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.game_3_highlighted;
    button_count = 4;//button 4
    menu.level[level_count].button[button_count].image                               =  image.game_4;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.game_4_highlighted;
    button_count = 5;//button 5
    menu.level[level_count].button[button_count].image                               =  image.main_menu;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.main_menu_highlighted;
    ///-------------Save game menu init -----------------------
    level_count  = 2;//level 2
    button_count = 0;
    menu.level[level_count].position_x                                               =  menu.level[0].position_x;
    menu.level[level_count].position_y                                               =  menu.level[0].position_y;
    menu.level[level_count].no_of_buttons                                            =  menu.level[0].no_of_buttons;
    menu.level[level_count].button_spacing                                           =  menu.level[0].button_spacing;
    menu.level[level_count].button_width                                             =  menu.level[0].button_width;
    menu.level[level_count].button_height                                            =  menu.level[0].button_height;
    menu.level[level_count].type_normal                                              =  menu.level[0].type_normal;
    menu.level[level_count].type_button_zoom                                         =  menu.level[0].type_button_zoom;
    menu.level[level_count].type_button_fade                                         =  menu.level[0].type_button_fade;
    menu.level[level_count].logo.drag                                                =  menu.level[0].logo.drag;
    menu.level[level_count].logo.image                                               =  image.save_game_highlighted;
    menu.level[level_count].logo.height                                              =  menu.level[0].logo.height;
    menu.level[level_count].logo.width                                               =  menu.level[0].logo.width;
    menu.level[level_count].logo.position_x                                          =  menu.level[0].position_x;
    menu.level[level_count].logo.position_y                                          =  menu.level[0].position_y-(menu.level[level_count].logo.height/2);
    for (button_count=0;button_count<MAX_BUTTONS+1;button_count++)
    {
       menu.level[level_count].button[button_count].button_zoom                      =  0.00f;
       menu.level[level_count].button[button_count].button_fade                      =  menu.button_fade_max;
       menu.level[level_count].button[button_count].type_normal                      =  true;
       menu.level[level_count].button[button_count].type_select                      =  false;
       menu.level[level_count].button[button_count].type_slider                      =  false;
    }
    button_count = 0;//button 0
    menu.level[level_count].button[button_count].image                               =  image.game_0;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.game_0_highlighted;
    button_count = 1;//button 1
    menu.level[level_count].button[button_count].image                               =  image.game_1;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.game_1_highlighted;
    button_count = 2;//button 2
    menu.level[level_count].button[button_count].image                               =  image.game_2;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.game_2_highlighted;
    button_count = 3;//button 3
    menu.level[level_count].button[button_count].image                               =  image.game_3;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.game_3_highlighted;
    button_count = 4;//button 4
    menu.level[level_count].button[button_count].image                               =  image.game_4;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.game_4_highlighted;
    button_count = 5;//button 5
    menu.level[level_count].button[button_count].image                               =  image.main_menu;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.main_menu_highlighted;
    ///-------------Options menu init -----------------------
    level_count  = 3;//level 3
    button_count = 0;
    menu.level[level_count].position_x                                               =  menu.level[0].position_x;
    menu.level[level_count].position_y                                               =  menu.level[0].position_y;
    menu.level[level_count].no_of_buttons                                            =  menu.level[0].no_of_buttons;
    menu.level[level_count].button_spacing                                           =  menu.level[0].button_spacing;
    menu.level[level_count].button_width                                             =  menu.level[0].button_width;
    menu.level[level_count].button_height                                            =  menu.level[0].button_height;
    menu.level[level_count].type_normal                                              =  menu.level[0].type_normal;
    menu.level[level_count].type_button_zoom                                         =  menu.level[0].type_button_zoom;
    menu.level[level_count].type_button_fade                                         =  menu.level[0].type_button_fade;
    menu.level[level_count].logo.drag                                                =  menu.level[0].logo.drag;
    menu.level[level_count].logo.image                                               =  image.options_menu_highlighted;
    menu.level[level_count].logo.height                                              =  menu.level[0].logo.height;
    menu.level[level_count].logo.width                                               =  menu.level[0].logo.width;
    menu.level[level_count].logo.position_x                                          =  menu.level[0].position_x;
    menu.level[level_count].logo.position_y                                          =  menu.level[0].position_y-(menu.level[level_count].logo.height/2);
    for (button_count=0;button_count<MAX_BUTTONS+1;button_count++)
    {
       menu.level[level_count].button[button_count].button_zoom                      =  0.00f;
       menu.level[level_count].button[button_count].button_fade                      =  menu.button_fade_max;
       menu.level[level_count].button[button_count].type_normal                      =  true;
       menu.level[level_count].button[button_count].type_select                      =  false;
       menu.level[level_count].button[button_count].type_slider                      =  false;
    }
    button_count = 0;//button 0
    menu.level[level_count].button[button_count].image                               =  image.audio;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.audio_highlighted;
    button_count = 1;//button 1
    menu.level[level_count].button[button_count].image                               =  image.graphics;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.graphics_highlighted;
    button_count = 2;//button 2
    menu.level[level_count].button[button_count].image                               =  image.keyboard;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.keyboard_highlighted;
    button_count = 3;//button 3
    menu.level[level_count].button[button_count].image                               =  image.mouse;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.mouse_highlighted;
    button_count = 4;//button 4
    menu.level[level_count].button[button_count].image                               =  image.gamepad;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.gamepad_highlighted;
    button_count = 5;//button 5
    menu.level[level_count].button[button_count].image                               =  image.main_menu;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.main_menu_highlighted;
    ///-------------Options - Audio menu init -----------------------
    level_count  = 4;//level 4
    button_count = 0;
    menu.level[level_count].position_x                                               =  menu.level[0].position_x;
    menu.level[level_count].position_y                                               =  menu.level[0].position_y;
    menu.level[level_count].no_of_buttons                                            =  menu.level[0].no_of_buttons;
    menu.level[level_count].button_spacing                                           =  menu.level[0].button_spacing;
    menu.level[level_count].button_width                                             =  menu.level[0].button_width;
    menu.level[level_count].button_height                                            =  menu.level[0].button_height;
    menu.level[level_count].type_normal                                              =  menu.level[0].type_normal;
    menu.level[level_count].type_button_zoom                                         =  menu.level[0].type_button_zoom;
    menu.level[level_count].type_button_fade                                         =  menu.level[0].type_button_fade;
    menu.level[level_count].logo.drag                                                =  menu.level[0].logo.drag;
    menu.level[level_count].logo.image                                               =  image.audio_highlighted;
    menu.level[level_count].logo.height                                              =  menu.level[0].logo.height;
    menu.level[level_count].logo.width                                               =  menu.level[0].logo.width;
    menu.level[level_count].logo.position_x                                          =  menu.level[0].position_x;
    menu.level[level_count].logo.position_y                                          =  menu.level[0].position_y-(menu.level[level_count].logo.height/2);
    for (button_count=0;button_count<MAX_BUTTONS+1;button_count++)
    {
       menu.level[level_count].button[button_count].button_zoom                      =  0.00f;
       menu.level[level_count].button[button_count].button_fade                      =  menu.button_fade_max;
       menu.level[level_count].button[button_count].type_normal                      =  true;
       menu.level[level_count].button[button_count].type_select                      =  false;
       menu.level[level_count].button[button_count].type_slider                      =  false;
       menu.level[level_count].button[button_count].image_bar_under                  =  image.slider_bar_bottom;
       menu.level[level_count].button[button_count].image_bar_value                  =  image.slider_bar_top;
       menu.level[level_count].button[button_count].image_left                       =  image.arrow_left;
       menu.level[level_count].button[button_count].image_left_highlighted           =  image.arrow_left_highlighted;
       menu.level[level_count].button[button_count].image_right                      =  image.arrow_right;
       menu.level[level_count].button[button_count].image_right_highlighted          =  image.arrow_right_highlighted;
    }
    button_count = 0;//button 0
    menu.level[level_count].button[button_count].image                               =  image.music_volume;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.music_volume_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  128;
    menu.level[level_count].button[button_count].mod_value                           =  (menu.level[level_count].button[button_count].max_value/10);
    menu.level[level_count].button[button_count].current_value                       =  config.audio_music_volume;
    menu.level[level_count].button[button_count].type_slider                         =  true;
    menu.level[level_count].button[button_count].type_select                         =  false;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 1;//button 1
    menu.level[level_count].button[button_count].image                               =  image.sound_volume;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.sound_volume_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  128;
    menu.level[level_count].button[button_count].mod_value                           =  (menu.level[level_count].button[button_count].max_value/10);
    menu.level[level_count].button[button_count].current_value                       =  config.audio_sound_volume;
    menu.level[level_count].button[button_count].type_slider                         =  true;
    menu.level[level_count].button[button_count].type_select                         =  false;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 2;//button 2
    menu.level[level_count].button[button_count].image                               =  image.audio_rate;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.audio_rate_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  2;
    menu.level[level_count].button[button_count].current_value                       =  config.audio_rate_menu;
    menu.level[level_count].button[button_count].select_option[0].image              =  image._22050;
    menu.level[level_count].button[button_count].select_option[0].image_highlighted  =  image._22050_highlighted;
    menu.level[level_count].button[button_count].select_option[1].image              =  image._44100;
    menu.level[level_count].button[button_count].select_option[1].image_highlighted  =  image._44100_highlighted;
    menu.level[level_count].button[button_count].select_option[2].image              =  image._44800;
    menu.level[level_count].button[button_count].select_option[2].image_highlighted  =  image._44800_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 3;//button 3
    menu.level[level_count].button[button_count].image                               =  image.audio_buffer;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.audio_buffer_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  3;
    menu.level[level_count].button[button_count].current_value                       =  config.audio_buffers_menu;
    menu.level[level_count].button[button_count].select_option[0].image              =  image._1024;
    menu.level[level_count].button[button_count].select_option[0].image_highlighted  =  image._1024_highlighted;
    menu.level[level_count].button[button_count].select_option[1].image              =  image._2048;
    menu.level[level_count].button[button_count].select_option[1].image_highlighted  =  image._2048_highlighted;
    menu.level[level_count].button[button_count].select_option[2].image              =  image._4096;
    menu.level[level_count].button[button_count].select_option[2].image_highlighted  =  image._4096_highlighted;
    menu.level[level_count].button[button_count].select_option[3].image              =  image._8192;
    menu.level[level_count].button[button_count].select_option[3].image_highlighted  =  image._8192_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 4;//button 4
    menu.level[level_count].button[button_count].image                               =  image.channels;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.channels_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  3;
    menu.level[level_count].button[button_count].current_value                       =  config.audio_channels_menu;
    menu.level[level_count].button[button_count].select_option[0].image              =  image._4;
    menu.level[level_count].button[button_count].select_option[0].image_highlighted  =  image._4_highlighted;
    menu.level[level_count].button[button_count].select_option[1].image              =  image._8;
    menu.level[level_count].button[button_count].select_option[1].image_highlighted  =  image._8_highlighted;
    menu.level[level_count].button[button_count].select_option[2].image              =  image._16;
    menu.level[level_count].button[button_count].select_option[2].image_highlighted  =  image._16_highlighted;
    menu.level[level_count].button[button_count].select_option[3].image              =  image._32;
    menu.level[level_count].button[button_count].select_option[3].image_highlighted  =  image._32_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 5;//button 5
    menu.level[level_count].button[button_count].image                               =  image.options_menu;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.options_menu_highlighted;
    ///-------------Options - Graphics menu init -----------------------
    level_count  = 5;//level 5
    button_count = 0;
    menu.level[level_count].position_x                                               =  menu.level[0].position_x;
    menu.level[level_count].position_y                                               =  menu.level[0].position_y;
    menu.level[level_count].no_of_buttons                                            =  menu.level[0].no_of_buttons;
    menu.level[level_count].button_spacing                                           =  menu.level[0].button_spacing;
    menu.level[level_count].button_width                                             =  menu.level[0].button_width;
    menu.level[level_count].button_height                                            =  menu.level[0].button_height;
    menu.level[level_count].type_normal                                              =  menu.level[0].type_normal;
    menu.level[level_count].type_button_zoom                                         =  menu.level[0].type_button_zoom;
    menu.level[level_count].type_button_fade                                         =  menu.level[0].type_button_fade;
    menu.level[level_count].logo.drag                                                =  menu.level[0].logo.drag;
    menu.level[level_count].logo.image                                               =  image.graphics_highlighted;
    menu.level[level_count].logo.height                                              =  menu.level[0].logo.height;
    menu.level[level_count].logo.width                                               =  menu.level[0].logo.width;
    menu.level[level_count].logo.position_x                                          =  menu.level[0].position_x;
    menu.level[level_count].logo.position_y                                          =  menu.level[0].position_y-(menu.level[level_count].logo.height/2);
    for (button_count=0;button_count<MAX_BUTTONS+1;button_count++)
    {
       menu.level[level_count].button[button_count].button_zoom                      =  0.00f;
       menu.level[level_count].button[button_count].button_fade                      =  menu.button_fade_max;
       menu.level[level_count].button[button_count].type_normal                      =  true;
       menu.level[level_count].button[button_count].type_select                      =  false;
       menu.level[level_count].button[button_count].type_slider                      =  false;
       menu.level[level_count].button[button_count].image_bar_under                  =  image.slider_bar_bottom;
       menu.level[level_count].button[button_count].image_bar_value                  =  image.slider_bar_top;
       menu.level[level_count].button[button_count].image_left                       =  image.arrow_left;
       menu.level[level_count].button[button_count].image_left_highlighted           =  image.arrow_left_highlighted;
       menu.level[level_count].button[button_count].image_right                      =  image.arrow_right;
       menu.level[level_count].button[button_count].image_right_highlighted          =  image.arrow_right_highlighted;
    }
    button_count = 0;//button 0
    menu.level[level_count].button[button_count].image                               =  image.fullscreen;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.fullscreen_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  1;
    menu.level[level_count].button[button_count].current_value                       =  config.screen_fullscreen_menu;
    menu.level[level_count].button[button_count].select_option[0].image              =  image.disabled;
    menu.level[level_count].button[button_count].select_option[0].image_highlighted  =  image.disabled_highlighted;
    menu.level[level_count].button[button_count].select_option[1].image              =  image.enabled;
    menu.level[level_count].button[button_count].select_option[1].image_highlighted  =  image.enabled_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 1;//button 1
    menu.level[level_count].button[button_count].image                               =  image.resolution;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.resolution_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  7;
    menu.level[level_count].button[button_count].current_value                       =  config.screen_resolution_menu;
    menu.level[level_count].button[button_count].select_option[0].image              =  image._640x480;
    menu.level[level_count].button[button_count].select_option[0].image_highlighted  =  image._640x480_highlighted;
    menu.level[level_count].button[button_count].select_option[1].image              =  image._600x800;
    menu.level[level_count].button[button_count].select_option[1].image_highlighted  =  image._600x800_highlighted;
    menu.level[level_count].button[button_count].select_option[2].image              =  image._1024x768;
    menu.level[level_count].button[button_count].select_option[2].image_highlighted  =  image._1024x768_highlighted;
    menu.level[level_count].button[button_count].select_option[3].image              =  image._1280x1024;
    menu.level[level_count].button[button_count].select_option[3].image_highlighted  =  image._1280x1024_highlighted;
    menu.level[level_count].button[button_count].select_option[4].image              =  image._1366x768;
    menu.level[level_count].button[button_count].select_option[4].image_highlighted  =  image._1366x768_highlighted;
    menu.level[level_count].button[button_count].select_option[5].image              =  image._1440x900;
    menu.level[level_count].button[button_count].select_option[5].image_highlighted  =  image._1440x900_highlighted;
    menu.level[level_count].button[button_count].select_option[6].image              =  image._1680x1050;
    menu.level[level_count].button[button_count].select_option[6].image_highlighted  =  image._1680x1050_highlighted;
    menu.level[level_count].button[button_count].select_option[7].image              =  image._1920x1080;
    menu.level[level_count].button[button_count].select_option[7].image_highlighted  =  image._1920x1080_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 2;//button 2
    menu.level[level_count].button[button_count].image                               =  image.bbp;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.bbp_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  1;
    menu.level[level_count].button[button_count].current_value                       =  config.screen_bbp_menu;
    menu.level[level_count].button[button_count].select_option[0].image              =  image._16;
    menu.level[level_count].button[button_count].select_option[0].image_highlighted  =  image._16_highlighted;
    menu.level[level_count].button[button_count].select_option[1].image              =  image._32;
    menu.level[level_count].button[button_count].select_option[1].image_highlighted  =  image._32_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 3;//button 3
    menu.level[level_count].button[button_count].image                               =  image.alpha_blending;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.alpha_blending_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  1;
    menu.level[level_count].button[button_count].current_value                       =  config.screen_alpha_blending_menu;
    menu.level[level_count].button[button_count].select_option[0].image              =  image.disabled;
    menu.level[level_count].button[button_count].select_option[0].image_highlighted  =  image.disabled_highlighted;
    menu.level[level_count].button[button_count].select_option[1].image              =  image.enabled;
    menu.level[level_count].button[button_count].select_option[1].image_highlighted  =  image.enabled_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 4;//button 4
    menu.level[level_count].button[button_count].image                               =  image.double_buffering;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.double_buffering_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  1;
    menu.level[level_count].button[button_count].current_value                       =  config.screen_double_buffering_menu;
    menu.level[level_count].button[button_count].select_option[0].image              =  image.disabled;
    menu.level[level_count].button[button_count].select_option[0].image_highlighted  =  image.disabled_highlighted;
    menu.level[level_count].button[button_count].select_option[1].image              =  image.enabled;
    menu.level[level_count].button[button_count].select_option[1].image_highlighted  =  image.enabled_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 5;//button 5
    menu.level[level_count].button[button_count].image                               =  image.options_menu;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.options_menu_highlighted;
    ///-------------Options - Keyboard menu init -----------------------
    level_count  = 6;//level 6
    button_count = 0;
    menu.level[level_count].position_x                                               =  menu.level[0].position_x;
    menu.level[level_count].position_y                                               =  menu.level[0].position_y;
    menu.level[level_count].no_of_buttons                                            =  menu.level[0].no_of_buttons;
    menu.level[level_count].button_spacing                                           =  menu.level[0].button_spacing;
    menu.level[level_count].button_width                                             =  menu.level[0].button_width;
    menu.level[level_count].button_height                                            =  menu.level[0].button_height;
    menu.level[level_count].type_normal                                              =  menu.level[0].type_normal;
    menu.level[level_count].type_button_zoom                                         =  menu.level[0].type_button_zoom;
    menu.level[level_count].type_button_fade                                         =  menu.level[0].type_button_fade;
    menu.level[level_count].logo.drag                                                =  menu.level[0].logo.drag;
    menu.level[level_count].logo.image                                               =  image.keyboard_highlighted;
    menu.level[level_count].logo.height                                              =  menu.level[0].logo.height;
    menu.level[level_count].logo.width                                               =  menu.level[0].logo.width;
    menu.level[level_count].logo.position_x                                          =  menu.level[0].position_x;
    menu.level[level_count].logo.position_y                                          =  menu.level[0].position_y-(menu.level[level_count].logo.height/2);
    for (button_count=0;button_count<MAX_BUTTONS+1;button_count++)
    {
       menu.level[level_count].button[button_count].button_zoom                      =  0.00f;
       menu.level[level_count].button[button_count].button_fade                      =  menu.button_fade_max;
       menu.level[level_count].button[button_count].type_normal                      =  true;
       menu.level[level_count].button[button_count].type_select                      =  false;
       menu.level[level_count].button[button_count].type_slider                      =  false;
       menu.level[level_count].button[button_count].image_bar_under                  =  image.slider_bar_bottom;
       menu.level[level_count].button[button_count].image_bar_value                  =  image.slider_bar_top;
       menu.level[level_count].button[button_count].image_left                       =  image.arrow_left;
       menu.level[level_count].button[button_count].image_left_highlighted           =  image.arrow_left_highlighted;
       menu.level[level_count].button[button_count].image_right                      =  image.arrow_right;
       menu.level[level_count].button[button_count].image_right_highlighted          =  image.arrow_right_highlighted;
    }
    button_count = 0;//button 0
    menu.level[level_count].button[button_count].image                               =  image.movement;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.movement_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  1;
    menu.level[level_count].button[button_count].current_value                       =  config.keyboard_movement_menu;
    menu.level[level_count].button[button_count].select_option[0].image              =  image.wasd;
    menu.level[level_count].button[button_count].select_option[0].image_highlighted  =  image.wasd_highlighted;
    menu.level[level_count].button[button_count].select_option[1].image              =  image.arrows;
    menu.level[level_count].button[button_count].select_option[1].image_highlighted  =  image.arrows_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 1;//button 1
    menu.level[level_count].button[button_count].image                               =  image.key_run;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.key_run_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  25;
    menu.level[level_count].button[button_count].current_value                       =  config.keyboard_run_menu;
    menu.level[level_count].button[button_count].select_option[ 0].image             =  image.a;
    menu.level[level_count].button[button_count].select_option[ 0].image_highlighted =  image.a_highlighted;
    menu.level[level_count].button[button_count].select_option[ 1].image             =  image.b;
    menu.level[level_count].button[button_count].select_option[ 1].image_highlighted =  image.b_highlighted;
    menu.level[level_count].button[button_count].select_option[ 2].image             =  image.c;
    menu.level[level_count].button[button_count].select_option[ 2].image_highlighted =  image.c_highlighted;
    menu.level[level_count].button[button_count].select_option[ 3].image             =  image.d;
    menu.level[level_count].button[button_count].select_option[ 3].image_highlighted =  image.d_highlighted;
    menu.level[level_count].button[button_count].select_option[ 4].image             =  image.e;
    menu.level[level_count].button[button_count].select_option[ 4].image_highlighted =  image.e_highlighted;
    menu.level[level_count].button[button_count].select_option[ 5].image             =  image.f;
    menu.level[level_count].button[button_count].select_option[ 5].image_highlighted =  image.f_highlighted;
    menu.level[level_count].button[button_count].select_option[ 6].image             =  image.g;
    menu.level[level_count].button[button_count].select_option[ 6].image_highlighted =  image.g_highlighted;
    menu.level[level_count].button[button_count].select_option[ 7].image             =  image.h;
    menu.level[level_count].button[button_count].select_option[ 7].image_highlighted =  image.h_highlighted;
    menu.level[level_count].button[button_count].select_option[ 8].image             =  image.i;
    menu.level[level_count].button[button_count].select_option[ 8].image_highlighted =  image.i_highlighted;
    menu.level[level_count].button[button_count].select_option[ 9].image             =  image.j;
    menu.level[level_count].button[button_count].select_option[ 9].image_highlighted =  image.j_highlighted;
    menu.level[level_count].button[button_count].select_option[10].image             =  image.k;
    menu.level[level_count].button[button_count].select_option[10].image_highlighted =  image.k_highlighted;
    menu.level[level_count].button[button_count].select_option[11].image             =  image.l;
    menu.level[level_count].button[button_count].select_option[11].image_highlighted =  image.l_highlighted;
    menu.level[level_count].button[button_count].select_option[12].image             =  image.m;
    menu.level[level_count].button[button_count].select_option[12].image_highlighted =  image.m_highlighted;
    menu.level[level_count].button[button_count].select_option[13].image             =  image.n;
    menu.level[level_count].button[button_count].select_option[13].image_highlighted =  image.n_highlighted;
    menu.level[level_count].button[button_count].select_option[14].image             =  image.o;
    menu.level[level_count].button[button_count].select_option[14].image_highlighted =  image.o_highlighted;
    menu.level[level_count].button[button_count].select_option[15].image             =  image.p;
    menu.level[level_count].button[button_count].select_option[15].image_highlighted =  image.p_highlighted;
    menu.level[level_count].button[button_count].select_option[16].image             =  image.q;
    menu.level[level_count].button[button_count].select_option[16].image_highlighted =  image.q_highlighted;
    menu.level[level_count].button[button_count].select_option[17].image             =  image.r;
    menu.level[level_count].button[button_count].select_option[17].image_highlighted =  image.r_highlighted;
    menu.level[level_count].button[button_count].select_option[18].image             =  image.s;
    menu.level[level_count].button[button_count].select_option[18].image_highlighted =  image.s_highlighted;
    menu.level[level_count].button[button_count].select_option[19].image             =  image.t;
    menu.level[level_count].button[button_count].select_option[19].image_highlighted =  image.t_highlighted;
    menu.level[level_count].button[button_count].select_option[20].image             =  image.u;
    menu.level[level_count].button[button_count].select_option[20].image_highlighted =  image.u_highlighted;
    menu.level[level_count].button[button_count].select_option[21].image             =  image.v;
    menu.level[level_count].button[button_count].select_option[21].image_highlighted =  image.v_highlighted;
    menu.level[level_count].button[button_count].select_option[22].image             =  image.w;
    menu.level[level_count].button[button_count].select_option[22].image_highlighted =  image.w_highlighted;
    menu.level[level_count].button[button_count].select_option[23].image             =  image.x;
    menu.level[level_count].button[button_count].select_option[23].image_highlighted =  image.x_highlighted;
    menu.level[level_count].button[button_count].select_option[24].image             =  image.y;
    menu.level[level_count].button[button_count].select_option[24].image_highlighted =  image.y_highlighted;
    menu.level[level_count].button[button_count].select_option[25].image             =  image.z;
    menu.level[level_count].button[button_count].select_option[25].image_highlighted =  image.z_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 2;//button 2
    menu.level[level_count].button[button_count].image                               =  image.key_jump;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.key_jump_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  25;
    menu.level[level_count].button[button_count].current_value                       =  config.keyboard_jump_menu;
    menu.level[level_count].button[button_count].select_option[ 0].image             =  image.a;
    menu.level[level_count].button[button_count].select_option[ 0].image_highlighted =  image.a_highlighted;
    menu.level[level_count].button[button_count].select_option[ 1].image             =  image.b;
    menu.level[level_count].button[button_count].select_option[ 1].image_highlighted =  image.b_highlighted;
    menu.level[level_count].button[button_count].select_option[ 2].image             =  image.c;
    menu.level[level_count].button[button_count].select_option[ 2].image_highlighted =  image.c_highlighted;
    menu.level[level_count].button[button_count].select_option[ 3].image             =  image.d;
    menu.level[level_count].button[button_count].select_option[ 3].image_highlighted =  image.d_highlighted;
    menu.level[level_count].button[button_count].select_option[ 4].image             =  image.e;
    menu.level[level_count].button[button_count].select_option[ 4].image_highlighted =  image.e_highlighted;
    menu.level[level_count].button[button_count].select_option[ 5].image             =  image.f;
    menu.level[level_count].button[button_count].select_option[ 5].image_highlighted =  image.f_highlighted;
    menu.level[level_count].button[button_count].select_option[ 6].image             =  image.g;
    menu.level[level_count].button[button_count].select_option[ 6].image_highlighted =  image.g_highlighted;
    menu.level[level_count].button[button_count].select_option[ 7].image             =  image.h;
    menu.level[level_count].button[button_count].select_option[ 7].image_highlighted =  image.h_highlighted;
    menu.level[level_count].button[button_count].select_option[ 8].image             =  image.i;
    menu.level[level_count].button[button_count].select_option[ 8].image_highlighted =  image.i_highlighted;
    menu.level[level_count].button[button_count].select_option[ 9].image             =  image.j;
    menu.level[level_count].button[button_count].select_option[ 9].image_highlighted =  image.j_highlighted;
    menu.level[level_count].button[button_count].select_option[10].image             =  image.k;
    menu.level[level_count].button[button_count].select_option[10].image_highlighted =  image.k_highlighted;
    menu.level[level_count].button[button_count].select_option[11].image             =  image.l;
    menu.level[level_count].button[button_count].select_option[11].image_highlighted =  image.l_highlighted;
    menu.level[level_count].button[button_count].select_option[12].image             =  image.m;
    menu.level[level_count].button[button_count].select_option[12].image_highlighted =  image.m_highlighted;
    menu.level[level_count].button[button_count].select_option[13].image             =  image.n;
    menu.level[level_count].button[button_count].select_option[13].image_highlighted =  image.n_highlighted;
    menu.level[level_count].button[button_count].select_option[14].image             =  image.o;
    menu.level[level_count].button[button_count].select_option[14].image_highlighted =  image.o_highlighted;
    menu.level[level_count].button[button_count].select_option[15].image             =  image.p;
    menu.level[level_count].button[button_count].select_option[15].image_highlighted =  image.p_highlighted;
    menu.level[level_count].button[button_count].select_option[16].image             =  image.q;
    menu.level[level_count].button[button_count].select_option[16].image_highlighted =  image.q_highlighted;
    menu.level[level_count].button[button_count].select_option[17].image             =  image.r;
    menu.level[level_count].button[button_count].select_option[17].image_highlighted =  image.r_highlighted;
    menu.level[level_count].button[button_count].select_option[18].image             =  image.s;
    menu.level[level_count].button[button_count].select_option[18].image_highlighted =  image.s_highlighted;
    menu.level[level_count].button[button_count].select_option[19].image             =  image.t;
    menu.level[level_count].button[button_count].select_option[19].image_highlighted =  image.t_highlighted;
    menu.level[level_count].button[button_count].select_option[20].image             =  image.u;
    menu.level[level_count].button[button_count].select_option[20].image_highlighted =  image.u_highlighted;
    menu.level[level_count].button[button_count].select_option[21].image             =  image.v;
    menu.level[level_count].button[button_count].select_option[21].image_highlighted =  image.v_highlighted;
    menu.level[level_count].button[button_count].select_option[22].image             =  image.w;
    menu.level[level_count].button[button_count].select_option[22].image_highlighted =  image.w_highlighted;
    menu.level[level_count].button[button_count].select_option[23].image             =  image.x;
    menu.level[level_count].button[button_count].select_option[23].image_highlighted =  image.x_highlighted;
    menu.level[level_count].button[button_count].select_option[24].image             =  image.y;
    menu.level[level_count].button[button_count].select_option[24].image_highlighted =  image.y_highlighted;
    menu.level[level_count].button[button_count].select_option[25].image             =  image.z;
    menu.level[level_count].button[button_count].select_option[25].image_highlighted =  image.z_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 3;//button 3
    menu.level[level_count].button[button_count].image                               =  image.key_duck;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.key_duck_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  25;
    menu.level[level_count].button[button_count].current_value                       =  config.keyboard_duck_menu;
    menu.level[level_count].button[button_count].select_option[ 0].image             =  image.a;
    menu.level[level_count].button[button_count].select_option[ 0].image_highlighted =  image.a_highlighted;
    menu.level[level_count].button[button_count].select_option[ 1].image             =  image.b;
    menu.level[level_count].button[button_count].select_option[ 1].image_highlighted =  image.b_highlighted;
    menu.level[level_count].button[button_count].select_option[ 2].image             =  image.c;
    menu.level[level_count].button[button_count].select_option[ 2].image_highlighted =  image.c_highlighted;
    menu.level[level_count].button[button_count].select_option[ 3].image             =  image.d;
    menu.level[level_count].button[button_count].select_option[ 3].image_highlighted =  image.d_highlighted;
    menu.level[level_count].button[button_count].select_option[ 4].image             =  image.e;
    menu.level[level_count].button[button_count].select_option[ 4].image_highlighted =  image.e_highlighted;
    menu.level[level_count].button[button_count].select_option[ 5].image             =  image.f;
    menu.level[level_count].button[button_count].select_option[ 5].image_highlighted =  image.f_highlighted;
    menu.level[level_count].button[button_count].select_option[ 6].image             =  image.g;
    menu.level[level_count].button[button_count].select_option[ 6].image_highlighted =  image.g_highlighted;
    menu.level[level_count].button[button_count].select_option[ 7].image             =  image.h;
    menu.level[level_count].button[button_count].select_option[ 7].image_highlighted =  image.h_highlighted;
    menu.level[level_count].button[button_count].select_option[ 8].image             =  image.i;
    menu.level[level_count].button[button_count].select_option[ 8].image_highlighted =  image.i_highlighted;
    menu.level[level_count].button[button_count].select_option[ 9].image             =  image.j;
    menu.level[level_count].button[button_count].select_option[ 9].image_highlighted =  image.j_highlighted;
    menu.level[level_count].button[button_count].select_option[10].image             =  image.k;
    menu.level[level_count].button[button_count].select_option[10].image_highlighted =  image.k_highlighted;
    menu.level[level_count].button[button_count].select_option[11].image             =  image.l;
    menu.level[level_count].button[button_count].select_option[11].image_highlighted =  image.l_highlighted;
    menu.level[level_count].button[button_count].select_option[12].image             =  image.m;
    menu.level[level_count].button[button_count].select_option[12].image_highlighted =  image.m_highlighted;
    menu.level[level_count].button[button_count].select_option[13].image             =  image.n;
    menu.level[level_count].button[button_count].select_option[13].image_highlighted =  image.n_highlighted;
    menu.level[level_count].button[button_count].select_option[14].image             =  image.o;
    menu.level[level_count].button[button_count].select_option[14].image_highlighted =  image.o_highlighted;
    menu.level[level_count].button[button_count].select_option[15].image             =  image.p;
    menu.level[level_count].button[button_count].select_option[15].image_highlighted =  image.p_highlighted;
    menu.level[level_count].button[button_count].select_option[16].image             =  image.q;
    menu.level[level_count].button[button_count].select_option[16].image_highlighted =  image.q_highlighted;
    menu.level[level_count].button[button_count].select_option[17].image             =  image.r;
    menu.level[level_count].button[button_count].select_option[17].image_highlighted =  image.r_highlighted;
    menu.level[level_count].button[button_count].select_option[18].image             =  image.s;
    menu.level[level_count].button[button_count].select_option[18].image_highlighted =  image.s_highlighted;
    menu.level[level_count].button[button_count].select_option[19].image             =  image.t;
    menu.level[level_count].button[button_count].select_option[19].image_highlighted =  image.t_highlighted;
    menu.level[level_count].button[button_count].select_option[20].image             =  image.u;
    menu.level[level_count].button[button_count].select_option[20].image_highlighted =  image.u_highlighted;
    menu.level[level_count].button[button_count].select_option[21].image             =  image.v;
    menu.level[level_count].button[button_count].select_option[21].image_highlighted =  image.v_highlighted;
    menu.level[level_count].button[button_count].select_option[22].image             =  image.w;
    menu.level[level_count].button[button_count].select_option[22].image_highlighted =  image.w_highlighted;
    menu.level[level_count].button[button_count].select_option[23].image             =  image.x;
    menu.level[level_count].button[button_count].select_option[23].image_highlighted =  image.x_highlighted;
    menu.level[level_count].button[button_count].select_option[24].image             =  image.y;
    menu.level[level_count].button[button_count].select_option[24].image_highlighted =  image.y_highlighted;
    menu.level[level_count].button[button_count].select_option[25].image             =  image.z;
    menu.level[level_count].button[button_count].select_option[25].image_highlighted =  image.z_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 4;//button 4
    menu.level[level_count].button[button_count].image                               =  image.key_select;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.key_select_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  25;
    menu.level[level_count].button[button_count].current_value                       =  config.keyboard_select_menu;
    menu.level[level_count].button[button_count].select_option[ 0].image             =  image.a;
    menu.level[level_count].button[button_count].select_option[ 0].image_highlighted =  image.a_highlighted;
    menu.level[level_count].button[button_count].select_option[ 1].image             =  image.b;
    menu.level[level_count].button[button_count].select_option[ 1].image_highlighted =  image.b_highlighted;
    menu.level[level_count].button[button_count].select_option[ 2].image             =  image.c;
    menu.level[level_count].button[button_count].select_option[ 2].image_highlighted =  image.c_highlighted;
    menu.level[level_count].button[button_count].select_option[ 3].image             =  image.d;
    menu.level[level_count].button[button_count].select_option[ 3].image_highlighted =  image.d_highlighted;
    menu.level[level_count].button[button_count].select_option[ 4].image             =  image.e;
    menu.level[level_count].button[button_count].select_option[ 4].image_highlighted =  image.e_highlighted;
    menu.level[level_count].button[button_count].select_option[ 5].image             =  image.f;
    menu.level[level_count].button[button_count].select_option[ 5].image_highlighted =  image.f_highlighted;
    menu.level[level_count].button[button_count].select_option[ 6].image             =  image.g;
    menu.level[level_count].button[button_count].select_option[ 6].image_highlighted =  image.g_highlighted;
    menu.level[level_count].button[button_count].select_option[ 7].image             =  image.h;
    menu.level[level_count].button[button_count].select_option[ 7].image_highlighted =  image.h_highlighted;
    menu.level[level_count].button[button_count].select_option[ 8].image             =  image.i;
    menu.level[level_count].button[button_count].select_option[ 8].image_highlighted =  image.i_highlighted;
    menu.level[level_count].button[button_count].select_option[ 9].image             =  image.j;
    menu.level[level_count].button[button_count].select_option[ 9].image_highlighted =  image.j_highlighted;
    menu.level[level_count].button[button_count].select_option[10].image             =  image.k;
    menu.level[level_count].button[button_count].select_option[10].image_highlighted =  image.k_highlighted;
    menu.level[level_count].button[button_count].select_option[11].image             =  image.l;
    menu.level[level_count].button[button_count].select_option[11].image_highlighted =  image.l_highlighted;
    menu.level[level_count].button[button_count].select_option[12].image             =  image.m;
    menu.level[level_count].button[button_count].select_option[12].image_highlighted =  image.m_highlighted;
    menu.level[level_count].button[button_count].select_option[13].image             =  image.n;
    menu.level[level_count].button[button_count].select_option[13].image_highlighted =  image.n_highlighted;
    menu.level[level_count].button[button_count].select_option[14].image             =  image.o;
    menu.level[level_count].button[button_count].select_option[14].image_highlighted =  image.o_highlighted;
    menu.level[level_count].button[button_count].select_option[15].image             =  image.p;
    menu.level[level_count].button[button_count].select_option[15].image_highlighted =  image.p_highlighted;
    menu.level[level_count].button[button_count].select_option[16].image             =  image.q;
    menu.level[level_count].button[button_count].select_option[16].image_highlighted =  image.q_highlighted;
    menu.level[level_count].button[button_count].select_option[17].image             =  image.r;
    menu.level[level_count].button[button_count].select_option[17].image_highlighted =  image.r_highlighted;
    menu.level[level_count].button[button_count].select_option[18].image             =  image.s;
    menu.level[level_count].button[button_count].select_option[18].image_highlighted =  image.s_highlighted;
    menu.level[level_count].button[button_count].select_option[19].image             =  image.t;
    menu.level[level_count].button[button_count].select_option[19].image_highlighted =  image.t_highlighted;
    menu.level[level_count].button[button_count].select_option[20].image             =  image.u;
    menu.level[level_count].button[button_count].select_option[20].image_highlighted =  image.u_highlighted;
    menu.level[level_count].button[button_count].select_option[21].image             =  image.v;
    menu.level[level_count].button[button_count].select_option[21].image_highlighted =  image.v_highlighted;
    menu.level[level_count].button[button_count].select_option[22].image             =  image.w;
    menu.level[level_count].button[button_count].select_option[22].image_highlighted =  image.w_highlighted;
    menu.level[level_count].button[button_count].select_option[23].image             =  image.x;
    menu.level[level_count].button[button_count].select_option[23].image_highlighted =  image.x_highlighted;
    menu.level[level_count].button[button_count].select_option[24].image             =  image.y;
    menu.level[level_count].button[button_count].select_option[24].image_highlighted =  image.y_highlighted;
    menu.level[level_count].button[button_count].select_option[25].image             =  image.z;
    menu.level[level_count].button[button_count].select_option[25].image_highlighted =  image.z_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 5;//button 5
    menu.level[level_count].button[button_count].image                               =  image.options_menu;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.options_menu_highlighted;
    ///-------------Options - Mouse menu init -----------------------
    level_count  = 7;//level 7
    button_count = 0;
    menu.level[level_count].position_x                                               =  menu.level[0].position_x;
    menu.level[level_count].position_y                                               =  menu.level[0].position_y;
    menu.level[level_count].no_of_buttons                                            =  menu.level[0].no_of_buttons;
    menu.level[level_count].button_spacing                                           =  menu.level[0].button_spacing;
    menu.level[level_count].button_width                                             =  menu.level[0].button_width;
    menu.level[level_count].button_height                                            =  menu.level[0].button_height;
    menu.level[level_count].type_normal                                              =  menu.level[0].type_normal;
    menu.level[level_count].type_button_zoom                                         =  menu.level[0].type_button_zoom;
    menu.level[level_count].type_button_fade                                         =  menu.level[0].type_button_fade;
    menu.level[level_count].logo.drag                                                =  menu.level[0].logo.drag;
    menu.level[level_count].logo.image                                               =  image.mouse_highlighted;
    menu.level[level_count].logo.height                                              =  menu.level[0].logo.height;
    menu.level[level_count].logo.width                                               =  menu.level[0].logo.width;
    menu.level[level_count].logo.position_x                                          =  menu.level[0].position_x;
    menu.level[level_count].logo.position_y                                          =  menu.level[0].position_y-(menu.level[level_count].logo.height/2);
    for (button_count=0;button_count<MAX_BUTTONS+1;button_count++)
    {
       menu.level[level_count].button[button_count].button_zoom                      =  0.00f;
       menu.level[level_count].button[button_count].button_fade                      =  menu.button_fade_max;
       menu.level[level_count].button[button_count].type_normal                      =  true;
       menu.level[level_count].button[button_count].type_select                      =  false;
       menu.level[level_count].button[button_count].type_slider                      =  false;
    }
    button_count = 0;//button 0
    menu.level[level_count].button[button_count].image                               =  image.audio;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.audio_highlighted;
    button_count = 1;//button 1
    menu.level[level_count].button[button_count].image                               =  image.graphics;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.graphics_highlighted;
    button_count = 2;//button 2
    menu.level[level_count].button[button_count].image                               =  image.keyboard;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.keyboard_highlighted;
    button_count = 3;//button 3
    menu.level[level_count].button[button_count].image                               =  image.mouse;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.mouse_highlighted;
    button_count = 4;//button 4
    menu.level[level_count].button[button_count].image                               =  image.gamepad;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.gamepad_highlighted;
    button_count = 5;//button 5
    menu.level[level_count].button[button_count].image                               =  image.options_menu;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.options_menu_highlighted;
    ///-------------Options - Gamepad menu init -----------------------
    level_count  = 8;//level 8
    button_count = 0;
    menu.level[level_count].position_x                                               =  menu.level[0].position_x;
    menu.level[level_count].position_y                                               =  menu.level[0].position_y;
    menu.level[level_count].no_of_buttons                                            =  menu.level[0].no_of_buttons;
    menu.level[level_count].button_spacing                                           =  menu.level[0].button_spacing;
    menu.level[level_count].button_width                                             =  menu.level[0].button_width;
    menu.level[level_count].button_height                                            =  menu.level[0].button_height;
    menu.level[level_count].type_normal                                              =  menu.level[0].type_normal;
    menu.level[level_count].type_button_zoom                                         =  menu.level[0].type_button_zoom;
    menu.level[level_count].type_button_fade                                         =  menu.level[0].type_button_fade;
    menu.level[level_count].logo.drag                                                =  menu.level[0].logo.drag;
    menu.level[level_count].logo.image                                               =  image.gamepad_highlighted;
    menu.level[level_count].logo.height                                              =  menu.level[0].logo.height;
    menu.level[level_count].logo.width                                               =  menu.level[0].logo.width;
    menu.level[level_count].logo.position_x                                          =  menu.level[0].position_x;
    menu.level[level_count].logo.position_y                                          =  menu.level[0].position_y-(menu.level[level_count].logo.height/2);
    for (button_count=0;button_count<MAX_BUTTONS+1;button_count++)
    {
       menu.level[level_count].button[button_count].button_zoom                      =  0.00f;
       menu.level[level_count].button[button_count].button_fade                      =  menu.button_fade_max;
       menu.level[level_count].button[button_count].type_normal                      =  true;
       menu.level[level_count].button[button_count].type_select                      =  false;
       menu.level[level_count].button[button_count].type_slider                      =  false;
       menu.level[level_count].button[button_count].image_bar_under                  =  image.slider_bar_bottom;
       menu.level[level_count].button[button_count].image_bar_value                  =  image.slider_bar_top;
       menu.level[level_count].button[button_count].image_left                       =  image.arrow_left;
       menu.level[level_count].button[button_count].image_left_highlighted           =  image.arrow_left_highlighted;
       menu.level[level_count].button[button_count].image_right                      =  image.arrow_right;
       menu.level[level_count].button[button_count].image_right_highlighted          =  image.arrow_right_highlighted;
    }
    button_count = 0;//button 0
    menu.level[level_count].button[button_count].image                               =  image.invert_axes;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.invert_axes_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  1;
    menu.level[level_count].button[button_count].current_value                       =  config.gamepad_invert_axes ;
    menu.level[level_count].button[button_count].select_option[0].image              =  image.enabled;
    menu.level[level_count].button[button_count].select_option[0].image_highlighted  =  image.enabled_highlighted;
    menu.level[level_count].button[button_count].select_option[1].image              =  image.disabled;
    menu.level[level_count].button[button_count].select_option[1].image_highlighted  =  image.disabled_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 1;//button 1
    menu.level[level_count].button[button_count].image                               =  image.button_run;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.button_run_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  config.gamepad_no_buttons-1;
    menu.level[level_count].button[button_count].current_value                       =  config.gamepad_run_menu;
    menu.level[level_count].button[button_count].select_option[ 0].image             =  image._0;
    menu.level[level_count].button[button_count].select_option[ 0].image_highlighted =  image._0_highlighted;
    menu.level[level_count].button[button_count].select_option[ 1].image             =  image._1;
    menu.level[level_count].button[button_count].select_option[ 1].image_highlighted =  image._1_highlighted;
    menu.level[level_count].button[button_count].select_option[ 2].image             =  image._2;
    menu.level[level_count].button[button_count].select_option[ 2].image_highlighted =  image._2_highlighted;
    menu.level[level_count].button[button_count].select_option[ 3].image             =  image._3;
    menu.level[level_count].button[button_count].select_option[ 3].image_highlighted =  image._3_highlighted;
    menu.level[level_count].button[button_count].select_option[ 4].image             =  image._4;
    menu.level[level_count].button[button_count].select_option[ 4].image_highlighted =  image._4_highlighted;
    menu.level[level_count].button[button_count].select_option[ 5].image             =  image._5;
    menu.level[level_count].button[button_count].select_option[ 5].image_highlighted =  image._5_highlighted;
    menu.level[level_count].button[button_count].select_option[ 6].image             =  image._6;
    menu.level[level_count].button[button_count].select_option[ 6].image_highlighted =  image._6_highlighted;
    menu.level[level_count].button[button_count].select_option[ 7].image             =  image._7;
    menu.level[level_count].button[button_count].select_option[ 7].image_highlighted =  image._7_highlighted;
    menu.level[level_count].button[button_count].select_option[ 8].image             =  image._8;
    menu.level[level_count].button[button_count].select_option[ 8].image_highlighted =  image._8_highlighted;
    menu.level[level_count].button[button_count].select_option[ 9].image             =  image._9;
    menu.level[level_count].button[button_count].select_option[ 9].image_highlighted =  image._9_highlighted;
    menu.level[level_count].button[button_count].select_option[10].image             =  image._10;
    menu.level[level_count].button[button_count].select_option[10].image_highlighted =  image._10_highlighted;
    menu.level[level_count].button[button_count].select_option[11].image             =  image._11;
    menu.level[level_count].button[button_count].select_option[11].image_highlighted =  image._11_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 2;//button 2
    menu.level[level_count].button[button_count].image                               =  image.button_jump;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.button_jump_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  config.gamepad_no_buttons-1;
    menu.level[level_count].button[button_count].current_value                       =  config.gamepad_jump_menu;
    menu.level[level_count].button[button_count].select_option[ 0].image             =  image._0;
    menu.level[level_count].button[button_count].select_option[ 0].image_highlighted =  image._0_highlighted;
    menu.level[level_count].button[button_count].select_option[ 1].image             =  image._1;
    menu.level[level_count].button[button_count].select_option[ 1].image_highlighted =  image._1_highlighted;
    menu.level[level_count].button[button_count].select_option[ 2].image             =  image._2;
    menu.level[level_count].button[button_count].select_option[ 2].image_highlighted =  image._2_highlighted;
    menu.level[level_count].button[button_count].select_option[ 3].image             =  image._3;
    menu.level[level_count].button[button_count].select_option[ 3].image_highlighted =  image._3_highlighted;
    menu.level[level_count].button[button_count].select_option[ 4].image             =  image._4;
    menu.level[level_count].button[button_count].select_option[ 4].image_highlighted =  image._4_highlighted;
    menu.level[level_count].button[button_count].select_option[ 5].image             =  image._5;
    menu.level[level_count].button[button_count].select_option[ 5].image_highlighted =  image._5_highlighted;
    menu.level[level_count].button[button_count].select_option[ 6].image             =  image._6;
    menu.level[level_count].button[button_count].select_option[ 6].image_highlighted =  image._6_highlighted;
    menu.level[level_count].button[button_count].select_option[ 7].image             =  image._7;
    menu.level[level_count].button[button_count].select_option[ 7].image_highlighted =  image._7_highlighted;
    menu.level[level_count].button[button_count].select_option[ 8].image             =  image._8;
    menu.level[level_count].button[button_count].select_option[ 8].image_highlighted =  image._8_highlighted;
    menu.level[level_count].button[button_count].select_option[ 9].image             =  image._9;
    menu.level[level_count].button[button_count].select_option[ 9].image_highlighted =  image._9_highlighted;
    menu.level[level_count].button[button_count].select_option[10].image             =  image._10;
    menu.level[level_count].button[button_count].select_option[10].image_highlighted =  image._10_highlighted;
    menu.level[level_count].button[button_count].select_option[11].image             =  image._11;
    menu.level[level_count].button[button_count].select_option[11].image_highlighted =  image._11_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 3;//button 3
    menu.level[level_count].button[button_count].image                               =  image.button_duck;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.button_duck_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  config.gamepad_no_buttons-1;
    menu.level[level_count].button[button_count].current_value                       =  config.gamepad_duck_menu;
    menu.level[level_count].button[button_count].select_option[ 0].image             =  image._0;
    menu.level[level_count].button[button_count].select_option[ 0].image_highlighted =  image._0_highlighted;
    menu.level[level_count].button[button_count].select_option[ 1].image             =  image._1;
    menu.level[level_count].button[button_count].select_option[ 1].image_highlighted =  image._1_highlighted;
    menu.level[level_count].button[button_count].select_option[ 2].image             =  image._2;
    menu.level[level_count].button[button_count].select_option[ 2].image_highlighted =  image._2_highlighted;
    menu.level[level_count].button[button_count].select_option[ 3].image             =  image._3;
    menu.level[level_count].button[button_count].select_option[ 3].image_highlighted =  image._3_highlighted;
    menu.level[level_count].button[button_count].select_option[ 4].image             =  image._4;
    menu.level[level_count].button[button_count].select_option[ 4].image_highlighted =  image._4_highlighted;
    menu.level[level_count].button[button_count].select_option[ 5].image             =  image._5;
    menu.level[level_count].button[button_count].select_option[ 5].image_highlighted =  image._5_highlighted;
    menu.level[level_count].button[button_count].select_option[ 6].image             =  image._6;
    menu.level[level_count].button[button_count].select_option[ 6].image_highlighted =  image._6_highlighted;
    menu.level[level_count].button[button_count].select_option[ 7].image             =  image._7;
    menu.level[level_count].button[button_count].select_option[ 7].image_highlighted =  image._7_highlighted;
    menu.level[level_count].button[button_count].select_option[ 8].image             =  image._8;
    menu.level[level_count].button[button_count].select_option[ 8].image_highlighted =  image._8_highlighted;
    menu.level[level_count].button[button_count].select_option[ 9].image             =  image._9;
    menu.level[level_count].button[button_count].select_option[ 9].image_highlighted =  image._9_highlighted;
    menu.level[level_count].button[button_count].select_option[10].image             =  image._10;
    menu.level[level_count].button[button_count].select_option[10].image_highlighted =  image._10_highlighted;
    menu.level[level_count].button[button_count].select_option[11].image             =  image._11;
    menu.level[level_count].button[button_count].select_option[11].image_highlighted =  image._11_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 4;//button 4
    menu.level[level_count].button[button_count].image                               =  image.button_select;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.button_select_highlighted;
    menu.level[level_count].button[button_count].max_value                           =  config.gamepad_no_buttons-1;
    menu.level[level_count].button[button_count].current_value                       =  config.gamepad_select_menu;
    menu.level[level_count].button[button_count].select_option[ 0].image             =  image._0;
    menu.level[level_count].button[button_count].select_option[ 0].image_highlighted =  image._0_highlighted;
    menu.level[level_count].button[button_count].select_option[ 1].image             =  image._1;
    menu.level[level_count].button[button_count].select_option[ 1].image_highlighted =  image._1_highlighted;
    menu.level[level_count].button[button_count].select_option[ 2].image             =  image._2;
    menu.level[level_count].button[button_count].select_option[ 2].image_highlighted =  image._2_highlighted;
    menu.level[level_count].button[button_count].select_option[ 3].image             =  image._3;
    menu.level[level_count].button[button_count].select_option[ 3].image_highlighted =  image._3_highlighted;
    menu.level[level_count].button[button_count].select_option[ 4].image             =  image._4;
    menu.level[level_count].button[button_count].select_option[ 4].image_highlighted =  image._4_highlighted;
    menu.level[level_count].button[button_count].select_option[ 5].image             =  image._5;
    menu.level[level_count].button[button_count].select_option[ 5].image_highlighted =  image._5_highlighted;
    menu.level[level_count].button[button_count].select_option[ 6].image             =  image._6;
    menu.level[level_count].button[button_count].select_option[ 6].image_highlighted =  image._6_highlighted;
    menu.level[level_count].button[button_count].select_option[ 7].image             =  image._7;
    menu.level[level_count].button[button_count].select_option[ 7].image_highlighted =  image._7_highlighted;
    menu.level[level_count].button[button_count].select_option[ 8].image             =  image._8;
    menu.level[level_count].button[button_count].select_option[ 8].image_highlighted =  image._8_highlighted;
    menu.level[level_count].button[button_count].select_option[ 9].image             =  image._9;
    menu.level[level_count].button[button_count].select_option[ 9].image_highlighted =  image._9_highlighted;
    menu.level[level_count].button[button_count].select_option[10].image             =  image._10;
    menu.level[level_count].button[button_count].select_option[10].image_highlighted =  image._10_highlighted;
    menu.level[level_count].button[button_count].select_option[11].image             =  image._11;
    menu.level[level_count].button[button_count].select_option[11].image_highlighted =  image._11_highlighted;
    menu.level[level_count].button[button_count].type_slider                         =  false;
    menu.level[level_count].button[button_count].type_select                         =  true;
    menu.level[level_count].button[button_count].type_normal                         =  false;
    button_count = 5;//button 5
    menu.level[level_count].button[button_count].image                               =  image.options_menu;
    menu.level[level_count].button[button_count].image_highlighted                   =  image.options_menu_highlighted;
    //menu general settings ---------------------------------------------------------------------------------
    menu.background_image                                                            = image.menu_background_00;
    game.mouse_button_left                                                           = false;
    game.mouse_button_middle                                                         = false;
    game.mouse_button_right                                                          = false;
    menu.last_sellect                                                                = -1;
    menu.current_level                                                               = 0;
    menu.current_button                                                              = 0;
    menu.button_zoom_speed                                                           = 0.01f;
    menu.button_zoom_max                                                             = menu.level[level_count].button_spacing * 1.0;
    menu.button_fade_speed                                                           = 0.02f;
    menu.button_fade_max                                                             = 0.6f;
    menu.option_select                                                               = false;
    menu.option_escape                                                               = false;
    menu.option_up                                                                   = false;
    menu.option_down                                                                 = false;
    menu.option_left                                                                 = false;
    menu.option_right                                                                = false;
    menu.data_changed                                                                = false;
    //-------------------------------------------------------------------------------------------------------
    return(1);
}

int menu_system_display(void)
{
   float t_z_pos    = 0.0f;
   float z_pos      = 1.0f;
   int button_count = 0;
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   //--------------------- If game is not active display a background image ---------------
   if (!game.status_game_active)
   {
      z_pos -= 0.01f;
      glBindTexture( GL_TEXTURE_2D, texture[image.background_02].texture);
      glLoadIdentity();
      glBegin(GL_QUADS);
      glNormal3d(0, 0, 1);
      glTexCoord2i(0,0);glVertex3f( 1.0f, 1.0f,z_pos);
      glTexCoord2i(1,0);glVertex3f(-1.0f, 1.0f,z_pos);
      glTexCoord2i(1,1);glVertex3f(-1.0f,-1.0f,z_pos);
      glTexCoord2i(0,1);glVertex3f( 1.0f,-1.0f,z_pos);
      glEnd();
   }
   //-------------------- Display menu -------------------------------
   //menu background
   z_pos -= 0.01f;
   button_count = menu.level[menu.current_level].no_of_buttons+1;
   glBindTexture( GL_TEXTURE_2D, texture[menu.background_image].texture);
   glLoadIdentity();
   glBegin(GL_QUADS);
   glNormal3d(0, 0, 1);
   glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].logo.position_x-(menu.level[menu.current_level].logo.width/2),(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom,z_pos);
   glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].logo.position_x+(menu.level[menu.current_level].logo.width/2),(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, z_pos);
   glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].logo.position_x+(menu.level[menu.current_level].logo.width/2),menu.level[menu.current_level].logo.position_y+(menu.level[menu.current_level].logo.height/2), z_pos);
   glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].logo.position_x-(menu.level[menu.current_level].logo.width/2),menu.level[menu.current_level].logo.position_y+(menu.level[menu.current_level].logo.height/2), z_pos);
   glEnd();
   //Menu logo
   z_pos -= 0.01f;
   glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].logo.image].texture);
   glLoadIdentity();
   glBegin(GL_QUADS);
   glNormal3d(0, 0, 1);
   glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].logo.position_x-(menu.level[menu.current_level].logo.width/2),menu.level[menu.current_level].logo.position_y+(menu.level[menu.current_level].logo.height/2), z_pos);
   glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].logo.position_x+(menu.level[menu.current_level].logo.width/2),menu.level[menu.current_level].logo.position_y+(menu.level[menu.current_level].logo.height/2), z_pos);
   glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].logo.position_x+(menu.level[menu.current_level].logo.width/2),menu.level[menu.current_level].logo.position_y-(menu.level[menu.current_level].logo.height/2), z_pos);
   glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].logo.position_x-(menu.level[menu.current_level].logo.width/2),menu.level[menu.current_level].logo.position_y-(menu.level[menu.current_level].logo.height/2), z_pos);
   glEnd();
   z_pos -= 0.03f;
   for(button_count = 0;button_count < menu.level[menu.current_level].no_of_buttons+1; button_count++)
   {
      glColor4f(1.0f,1.0f,1.0f,menu.level[menu.current_level].button[button_count].button_fade);
      if (menu.level[menu.current_level].button[button_count].type_normal)//normal button
      {
         if (menu.current_button == button_count) t_z_pos = z_pos -= 0.01f;
         else t_z_pos = z_pos;
         if (menu.current_button == button_count) glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_highlighted].texture);
         else glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image].texture);
            glLoadIdentity();
            glBegin(GL_QUADS);
            glNormal3d(0, 0, 1);
            glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].position_x-(menu.level[menu.current_level].button_width/2)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].position_x+(menu.level[menu.current_level].button_width/2)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].position_x+(menu.level[menu.current_level].button_width/2)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].position_x-(menu.level[menu.current_level].button_width/2)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glEnd();
      }
      if (menu.level[menu.current_level].button[button_count].type_slider)//slider button
      {
         if (menu.current_button == button_count) t_z_pos = z_pos -= 0.01f;
         else t_z_pos = z_pos;
         //bar background
            glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_bar_under].texture);
            glLoadIdentity();
            glBegin(GL_QUADS);
            glNormal3d(0, 0, 1);
            glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)                                                 +menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)                                                 +menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glEnd();
         //bar data
            glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_bar_value].texture);
            glLoadIdentity();
            glBegin(GL_QUADS);
            glNormal3d(0, 0, 1);
            glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)                                                 +menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)+((((menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom)-(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom))/menu.level[menu.current_level].button[button_count].max_value)*menu.level[menu.current_level].button[button_count].current_value)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)                                                 +menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)+((((menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom)-(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom))/menu.level[menu.current_level].button[button_count].max_value)*menu.level[menu.current_level].button[button_count].current_value)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glEnd();
         // button image
         if (menu.current_button == button_count) glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_highlighted].texture);
         else glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image].texture);
            glLoadIdentity();
            glBegin(GL_QUADS);
            glNormal3d(0, 0, 1);
            glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)                                                 -menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)                                                 -menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glEnd();
         //left arrow
         if ((menu.current_button == button_count) && (menu.level[menu.current_level].button[button_count].current_direction == 1)) glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_left_highlighted].texture);
         else glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_left].texture);
            glLoadIdentity();
            glBegin(GL_QUADS);
            glNormal3d(0, 0, 1);
            glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].position_x-( menu.level[menu.current_level].button_width/2)    -menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].position_x-( menu.level[menu.current_level].button_width/2)    -menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glEnd();
         //right arrow
         if ((menu.current_button == button_count) && (menu.level[menu.current_level].button[button_count].current_direction == 2)) glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_right_highlighted].texture);
         else glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_right].texture);
            glLoadIdentity();
            glBegin(GL_QUADS);
            glNormal3d(0, 0, 1);
            glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].position_x+( menu.level[menu.current_level].button_width/2)    +menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].position_x+( menu.level[menu.current_level].button_width/2)    +menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glEnd();
      }
      if (menu.level[menu.current_level].button[button_count].type_select)//select button
      {
         if (menu.current_button == button_count) t_z_pos = z_pos -= 0.01f;
         else t_z_pos = z_pos;
         //Button value
         if (menu.current_button == button_count) glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].select_option[menu.level[menu.current_level].button[button_count].current_value].image_highlighted].texture);
         else glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].select_option[menu.level[menu.current_level].button[button_count].current_value].image].texture);
            glLoadIdentity();
            glBegin(GL_QUADS);
            glNormal3d(0, 0, 1);
            glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)                                                 +menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)                                                 +menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glEnd();
         // button image
         if (menu.current_button == button_count) glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_highlighted].texture);
         else glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image].texture);
            glLoadIdentity();
            glBegin(GL_QUADS);
            glNormal3d(0, 0, 1);
            glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)                                                 -menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)                                                 -menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glEnd();
         //left arrow
         if ((menu.current_button == button_count) && (menu.level[menu.current_level].button[button_count].current_direction == 1)) glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_left_highlighted].texture);
         else glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_left].texture);
            glLoadIdentity();
            glBegin(GL_QUADS);
            glNormal3d(0, 0, 1);
            glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].position_x-( menu.level[menu.current_level].button_width/2)    -menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].position_x-((menu.level[menu.current_level].button_width/10)*3)+menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].position_x-( menu.level[menu.current_level].button_width/2)    -menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glEnd();
         //right arrow
         if ((menu.current_button == button_count) && (menu.level[menu.current_level].button[button_count].current_direction == 2)) glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_right_highlighted].texture);
         else glBindTexture( GL_TEXTURE_2D, texture[menu.level[menu.current_level].button[button_count].image_right].texture);
            glLoadIdentity();
            glBegin(GL_QUADS);
            glNormal3d(0, 0, 1);
            glTexCoord2i(0,0);glVertex3f(menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,0);glVertex3f(menu.level[menu.current_level].position_x+( menu.level[menu.current_level].button_width/2)    +menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(1,1);glVertex3f(menu.level[menu.current_level].position_x+( menu.level[menu.current_level].button_width/2)    +menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glTexCoord2i(0,1);glVertex3f(menu.level[menu.current_level].position_x+((menu.level[menu.current_level].button_width/10)*3)-menu.level[menu.current_level].button[button_count].button_zoom,(menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom, t_z_pos);
            glEnd();
      }
    }
   glPopMatrix();
   return(1);
}

bool mouse_over_button(int level_count, int button_count, float mouse_x, float mouse_y)
{
   if ((mouse_x > menu.level[level_count].position_x-(menu.level[level_count].button_width/2)-menu.level[level_count].button[button_count].button_zoom)
    && (mouse_x < menu.level[level_count].position_x+(menu.level[level_count].button_width/2)+menu.level[level_count].button[button_count].button_zoom)
    && (mouse_y > (menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)-(menu.level[menu.current_level].button_height/2)-menu.level[menu.current_level].button[button_count].button_zoom)
    && (mouse_y < (menu.level[menu.current_level].logo.position_y-menu.level[menu.current_level].logo.height)-((menu.level[menu.current_level].button_spacing+menu.level[menu.current_level].button_height)*button_count)+(menu.level[menu.current_level].button_height/2)+menu.level[menu.current_level].button[button_count].button_zoom))
   return(true);
   else return(false);
};

int mouse_over_select(int level_count, int button_count, float mouse_x, float mouse_y)
{
   int return_value = 0;
   if ((mouse_x <  menu.level[level_count].position_x-((menu.level[level_count].button_width/10)*3)+menu.level[level_count].button[button_count].button_zoom)
    && (mouse_x >  menu.level[level_count].position_x-( menu.level[level_count].button_width/2)    -menu.level[level_count].button[button_count].button_zoom)
    && (mouse_y < (menu.level[level_count].logo.position_y-menu.level[level_count].logo.height)-((menu.level[level_count].button_spacing+menu.level[level_count].button_height)*button_count)+(menu.level[level_count].button_height/2)+menu.level[level_count].button[button_count].button_zoom)
    && (mouse_y > (menu.level[level_count].logo.position_y-menu.level[level_count].logo.height)-((menu.level[level_count].button_spacing+menu.level[level_count].button_height)*button_count)-(menu.level[level_count].button_height/2)-menu.level[level_count].button[button_count].button_zoom))
   return_value = 1;//left arrow
   if ((mouse_x <  menu.level[level_count].position_x+( menu.level[level_count].button_width/2)    +menu.level[level_count].button[button_count].button_zoom)
    && (mouse_x >  menu.level[level_count].position_x+((menu.level[level_count].button_width/10)*3)-menu.level[level_count].button[button_count].button_zoom)
    && (mouse_y < (menu.level[level_count].logo.position_y-menu.level[level_count].logo.height)-((menu.level[level_count].button_spacing+menu.level[level_count].button_height)*button_count)+(menu.level[level_count].button_height/2)+menu.level[level_count].button[button_count].button_zoom)
    && (mouse_y > (menu.level[level_count].logo.position_y-menu.level[level_count].logo.height)-((menu.level[level_count].button_spacing+menu.level[level_count].button_height)*button_count)-(menu.level[level_count].button_height/2)-menu.level[level_count].button[button_count].button_zoom))
   return_value = 2;//right arrow
   return(return_value);
};

bool mouse_over_logo(int level_count, float mouse_x, float mouse_y)
{
   if ((mouse_x > menu.level[level_count].logo.position_x-(menu.level[level_count].logo.width/2))
    && (mouse_x < menu.level[level_count].logo.position_x+(menu.level[level_count].logo.width/2))
    && (mouse_y > menu.level[level_count].logo.position_y-(menu.level[level_count].logo.height/2))
    && (mouse_y < menu.level[level_count].logo.position_y+(menu.level[level_count].logo.height/2)))
   return(true);
   else return(false);
}

int menu_system_process(void)
{
    game.mouse_button_delay_count++;
    if (game.mouse_button_delay_count > game.mouse_button_delay) game.mouse_button_delay_count = game.mouse_button_delay;
    int button_count = 0;
    play_music(song.menu_001);config.audio_current_song = song.menu_001;
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
    if(menu.level[menu.current_level].type_button_fade) //if button fade type, process fade
    {
       for(int button_count = 0;button_count < menu.level[menu.current_level].no_of_buttons+1; button_count++)
       {
           if(menu.current_button == button_count)
           {
               menu.level[menu.current_level].button[button_count].button_fade += menu.button_fade_speed;
               if(menu.level[menu.current_level].button[button_count].button_fade > 1.0f) menu.level[menu.current_level].button[button_count].button_fade = 1.0f;
           }
           else
           {
               menu.level[menu.current_level].button[button_count].button_fade -= menu.button_fade_speed;
               if(menu.level[menu.current_level].button[button_count].button_fade < menu.button_fade_max) menu.level[menu.current_level].button[button_count].button_fade = menu.button_fade_max;
           }
       }
    }
    while (SDL_PollEvent(&game.event))
    {
    //-------------------- Mouse events-------------------------------
       if (game.event.type == SDL_MOUSEMOTION)
       {
           game.mouse_x      = res_to_gl(game.event.motion.x,config.mouse_resolution_x);
           game.mouse_y      = res_to_gl(game.event.motion.y,config.mouse_resolution_y);
           game.mouse_xrel   = res_to_gl(game.event.motion.xrel,config.mouse_resolution_x);
           game.mouse_yrel   = res_to_gl(game.event.motion.yrel,config.mouse_resolution_y);
           game.mouse_y *= -1;
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
                if (game.mouse_button_delay_count >= game.mouse_button_delay)
                {
                   game.mouse_button_delay_count = 0;
                   game.mouse_button_left = true;
                }
                else game.mouse_button_left = false;
              break;
              case 2:
                if (game.mouse_button_delay_count >= game.mouse_button_delay)
                {
                   game.mouse_button_delay_count = 0;
                   game.mouse_button_middle = true;
                }
                else game.mouse_button_middle = false;
              break;
              case 3:
                if (game.mouse_button_delay_count >= game.mouse_button_delay)
                {
                   game.mouse_button_delay_count = 0;
                   game.mouse_button_right = true;
                }
                else game.mouse_button_right = false;
              break;
              default:
              break;
           }
       }
    if (mouse_over_logo(menu.current_level,game.mouse_x,game.mouse_y))//drag menu? :P
    {
        if (game.mouse_button_left)
        {
           if (!menu.level[menu.current_level].logo.drag)
           {
               menu.level[menu.current_level].logo.drag_offset_x = game.mouse_x - menu.level[menu.current_level].logo.position_x;
               menu.level[menu.current_level].logo.drag_offset_y = game.mouse_y - menu.level[menu.current_level].logo.position_y;
               menu.level[menu.current_level].logo.drag = true;
           }
           else
           {
               menu.level[menu.current_level].logo.position_x = game.mouse_x - menu.level[menu.current_level].logo.drag_offset_x;
               menu.level[menu.current_level].logo.position_y = game.mouse_y - menu.level[menu.current_level].logo.drag_offset_y;
               menu.level[menu.current_level].position_x = menu.level[menu.current_level].logo.position_x;
               for(int level_count = 0;level_count < MAX_LEVELS;level_count++)
               {
                  menu.level[level_count].logo.position_x = menu.level[menu.current_level].logo.position_x;
                  menu.level[level_count].logo.position_y = menu.level[menu.current_level].logo.position_y;
                  menu.level[level_count].position_x = menu.level[menu.current_level].position_x;
               }
           }
        }
        else
        {
            menu.level[menu.current_level].logo.drag = false;
        }
    }
        for(button_count = 0;button_count<menu.level[menu.current_level].no_of_buttons+1;button_count++)
        {
           menu.level[menu.current_level].button[button_count].current_direction = mouse_over_select(menu.current_level,button_count,game.mouse_x,game.mouse_y);
        }
    if (!menu.level[menu.current_level].logo.drag)
    {
        for(button_count = 0;button_count<menu.level[menu.current_level].no_of_buttons+1;button_count++)
        {
           if ((mouse_over_button(menu.current_level,button_count,game.mouse_x,game.mouse_y)) && (menu.current_button != button_count))
           {
              menu.last_sellect = -1;
              menu.current_button = button_count;
              play_sound(sfx.menu_move);
           }
           if (menu.level[menu.current_level].button[button_count].type_normal)
           {
              if ((game.mouse_button_left) && (menu.last_sellect != button_count)) menu.option_select = true;
           }
           if ((menu.level[menu.current_level].button[button_count].type_slider) || (menu.level[menu.current_level].button[button_count].type_select))
           {
              if ((menu.level[menu.current_level].button[button_count].current_direction==1) && (game.mouse_button_left))
              {
                 menu.option_select  = false;
                 menu.option_left    = true;
              }
              if ((menu.level[menu.current_level].button[button_count].current_direction==2) && (game.mouse_button_left))
              {
                 menu.option_select  = false;
                 menu.option_right   = true;
              }
           }
        }
    }
    //-------------------------- joystick / gamepad events --------------------------------------------
       if (game.event.type == SDL_JOYHATMOTION)
       {
          if (game.event.jhat.value & SDL_HAT_UP)    menu.option_up    = true;
          if (game.event.jhat.value & SDL_HAT_DOWN)  menu.option_down  = true;
          if (game.event.jhat.value & SDL_HAT_LEFT)  menu.option_left  = true;
          if (game.event.jhat.value & SDL_HAT_RIGHT) menu.option_right = true;
       }
       if (game.event.type == SDL_JOYAXISMOTION)
       {
          if ((game.event.jaxis.value < (-1*(game.joystick_sensitivity))) || (game.event.jaxis.value > game.joystick_sensitivity))
          {
             if (game.event.jaxis.axis == 0)
             {
                if(game.event.jaxis.value < -(-1*(game.joystick_sensitivity))) menu.option_left  = true;
                if(game.event.jaxis.value > game.joystick_sensitivity)         menu.option_right = true;
             }
             if (game.event.jaxis.axis == 1)
             {
                if(game.event.jaxis.value < -(-1*(game.joystick_sensitivity))) menu.option_up    = true;
                if(game.event.jaxis.value > game.joystick_sensitivity)         menu.option_down  = true;
             }
          }
       }
       if (game.event.type == SDL_JOYBUTTONDOWN)
       {
           switch(game.event.jbutton.button)
           {
              case 0:
                game.gamepad_button_0 = false;
              break;
              case 1:
                game.gamepad_button_1 = false;
              break;
              case 2:
                game.gamepad_button_2 = false;
              break;
              case 3:
                game.gamepad_button_3 = false;
              break;
              default:
              break;
           }
       }
       if (game.event.type == SDL_JOYBUTTONUP)
       {
           switch(game.event.jbutton.button)
           {
              case 0:
                game.gamepad_button_0 = true;
              break;
              case 1:
                game.gamepad_button_1 = true;
              break;
              case 2:
                game.gamepad_button_2 = true;
              break;
              case 3:
                game.gamepad_button_3 = true;
              break;
              default:
              break;
           }
       }
       if (game.gamepad_button_0) menu.option_select = true;
       if (game.gamepad_button_3) menu.option_escape = true;

       //------------------ keybord events ------------------------------------------------------
       if (game.event.type == SDL_QUIT) game.status_quit_active = true;
       if (game.event.type == SDL_KEYDOWN)
       {
          if (game.event.key.keysym.sym == SDLK_ESCAPE) menu.option_escape = true;
          if (game.event.key.keysym.sym == SDLK_UP)     menu.option_up     = true;
          if (game.event.key.keysym.sym == SDLK_DOWN)   menu.option_down   = true;
          if (game.event.key.keysym.sym == SDLK_LEFT)   menu.option_left   = true;
          if (game.event.key.keysym.sym == SDLK_RIGHT)  menu.option_right  = true;
          if (game.event.key.keysym.sym == SDLK_RETURN) menu.option_select = true;
          if (game.event.key.keysym.sym == SDLK_SPACE)  menu.option_select = true;
       }
       if (game.event.type == SDL_KEYUP)
       {
          if (game.event.key.keysym.sym == SDLK_ESCAPE) menu.option_escape = false;
          if (game.event.key.keysym.sym == SDLK_UP)     menu.option_up     = false;
          if (game.event.key.keysym.sym == SDLK_DOWN)   menu.option_down   = false;
          if (game.event.key.keysym.sym == SDLK_LEFT)   menu.option_left   = false;
          if (game.event.key.keysym.sym == SDLK_RIGHT)  menu.option_right  = false;
          if (game.event.key.keysym.sym == SDLK_RETURN) menu.option_select = false;
          if (game.event.key.keysym.sym == SDLK_SPACE)  menu.option_select = false;
       }
    }
//--------------------------------------common menu processing code------------------------------
   if (menu.option_up)
   {
      menu.option_up = false;
      menu.current_button--;
      if (menu.current_button < 0) menu.current_button = 0;
      else play_sound(sfx.menu_move);
   };

   if (menu.option_down)
   {
      menu.option_down = false;
      menu.current_button++;
      if (menu.current_button > menu.level[menu.current_level].no_of_buttons) menu.current_button = menu.level[menu.current_level].no_of_buttons;
      else play_sound(sfx.menu_move);
   };

   if ((menu.option_left) || (menu.option_right))
   {
      menu.data_changed = true;
      play_sound(sfx.menu_move);
      if (menu.option_left)
      {
         if (menu.level[menu.current_level].button[menu.current_button].type_select) menu.level[menu.current_level].button[menu.current_button].current_value--;
         if (menu.level[menu.current_level].button[menu.current_button].type_slider) menu.level[menu.current_level].button[menu.current_button].current_value -= menu.level[menu.current_level].button[menu.current_button].mod_value;
         if (menu.level[menu.current_level].button[menu.current_button].current_value < 0) menu.level[menu.current_level].button[menu.current_button].current_value = 0;
         menu.level[menu.current_level].button[menu.current_button].current_direction = 1;
      }
      if (menu.option_right)
      {
         if (menu.level[menu.current_level].button[menu.current_button].type_select) menu.level[menu.current_level].button[menu.current_button].current_value++;
         if (menu.level[menu.current_level].button[menu.current_button].type_slider) menu.level[menu.current_level].button[menu.current_button].current_value += menu.level[menu.current_level].button[menu.current_button].mod_value;
         if (menu.level[menu.current_level].button[menu.current_button].current_value > menu.level[menu.current_level].button[menu.current_button].max_value) menu.level[menu.current_level].button[menu.current_button].current_value = menu.level[menu.current_level].button[menu.current_button].max_value;
         menu.level[menu.current_level].button[menu.current_button].current_direction = 2;
      }
      if (menu.level[menu.current_level].button[menu.current_button].type_select) menu.option_left  = false;
      if (menu.level[menu.current_level].button[menu.current_button].type_select) menu.option_right = false;
      if (menu.level[menu.current_level].button[menu.current_button].type_slider) menu.option_left  = false;
      if (menu.level[menu.current_level].button[menu.current_button].type_slider) menu.option_right = false;
      game.mouse_button_left   = false;
      game.mouse_button_middle = false;
      game.mouse_button_right  = false;
      game.gamepad_button_0    = false;
      game.gamepad_button_1    = false;
      game.gamepad_button_2    = false;
      game.gamepad_button_3    = false;
      menu.option_select       = false;
      switch (menu.current_level)
      {
         case 4: //options - audio menu
         switch (menu.current_button)
         {
            case 0: //music volume
               config.audio_music_volume = menu.level[menu.current_level].button[menu.current_button].current_value;
               Mix_VolumeMusic(config.audio_music_volume);
            break;
            case 1: //sound volume
               config.audio_sound_volume = menu.level[menu.current_level].button[menu.current_button].current_value;
               Mix_Volume(-1,config.audio_sound_volume);
            break;
            case 2: //Audio rate
               config.audio_rate_menu = menu.level[menu.current_level].button[menu.current_button].current_value;
               if (config.audio_rate_menu = 0) config.audio_rate = 22050;
               if (config.audio_rate_menu = 1) config.audio_rate = 44100;
               if (config.audio_rate_menu = 2) config.audio_rate = 44800;
            break;
            case 3: //Audio buffers
               config.audio_buffers_menu = menu.level[menu.current_level].button[menu.current_button].current_value;
               if (config.audio_buffers_menu = 0) config.audio_buffers = 1024;
               if (config.audio_buffers_menu = 1) config.audio_buffers = 2048;
               if (config.audio_buffers_menu = 2) config.audio_buffers = 4096;
               if (config.audio_buffers_menu = 3) config.audio_buffers = 8192;
            break;
            case 4: //Audio channels
               config.audio_channels_menu = menu.level[menu.current_level].button[menu.current_button].current_value;
               if (config.audio_channels_menu = 0) config.audio_channels = 4;
               if (config.audio_channels_menu = 1) config.audio_channels = 8;
               if (config.audio_channels_menu = 2) config.audio_channels = 16;
               if (config.audio_channels_menu = 3) config.audio_channels = 32;
            break;
            default:
            break;
         }
         case 5: //options - graphics menu
         switch (menu.current_button)
         {
            case 0: //toggle fullscreen
               config.screen_fullscreen_menu = menu.level[menu.current_level].button[menu.current_button].current_value;
               if (config.screen_fullscreen_menu == 0) config.screen_fullscreen = false;
               if (config.screen_fullscreen_menu == 1) config.screen_fullscreen = true;
            break;
            case 1: //
               config.screen_resolution_menu = menu.level[menu.current_level].button[menu.current_button].current_value;
               if (config.screen_resolution_menu == 0)
               {
                   config.screen_resolution_x = 640;
                   config.screen_resolution_y = 480;
               }
               if (config.screen_resolution_menu == 1)
               {
                   config.screen_resolution_x = 800;
                   config.screen_resolution_y = 600;
               }
               if (config.screen_resolution_menu == 2)
               {
                   config.screen_resolution_x = 1024;
                   config.screen_resolution_y = 768;
               }
               if (config.screen_resolution_menu == 3)
               {
                   config.screen_resolution_x = 1280;
                   config.screen_resolution_y = 1024;
               }
               if (config.screen_resolution_menu == 4)
               {
                   config.screen_resolution_x = 1366;
                   config.screen_resolution_y = 768;
               }
               if (config.screen_resolution_menu == 5)
               {
                   config.screen_resolution_x = 1440;
                   config.screen_resolution_y = 900;
               }
               if (config.screen_resolution_menu == 6)
               {
                   config.screen_resolution_x = 1680;
                   config.screen_resolution_y = 1050;
               }
               if (config.screen_resolution_menu == 7)
               {
                   config.screen_resolution_x = 1920;
                   config.screen_resolution_y = 1080;
               }
            break;
            case 2: //
            break;
            case 3: //
            break;
            case 4: //
            break;
            default:
            break;
         }
         break;
         default:
         break;
     }
   }
   if (menu.option_escape)
   {
      game.mouse_button_left   = false;
      game.mouse_button_middle = false;
      game.mouse_button_right  = false;
      game.gamepad_button_0    = false;
      game.gamepad_button_1    = false;
      game.gamepad_button_2    = false;
      game.gamepad_button_3    = false;
      menu.last_sellect        = -1;
      play_sound(sfx.menu_select);
      menu.option_escape       = false;
      switch (menu.current_level)
      {
         case 0: //main menu
            game.status_quit_active = true;
         break;
         case 1: //load game menu
            menu.current_level       = 0;
            menu.current_button      = 1;
         break;
         case 2: //save game menu
            menu.current_level       = 0;
            menu.current_button      = 2;
         break;
         case 3: //options menu
            menu.current_level       = 0;
            menu.current_button      = 4;
         break;
         case 4: //options - audio menu
            menu.current_level       = 3;
            menu.current_button      = 0;
         break;
         case 5: //options - graphics menu
            menu.current_level       = 3;
            menu.current_button      = 1;
         break;
         case 6: //options - keyboard menu
            menu.current_level       = 3;
            menu.current_button      = 2;
         break;
         case 7: //options - mouse menu
            menu.current_level       = 3;
            menu.current_button      = 3;
         break;
         case 8: //options - gamepad menu
            menu.current_level       = 3;
            menu.current_button      = 4;
         break;
      };
   };

   if (menu.option_select)
   {
      game.mouse_button_left   = false;
      game.mouse_button_middle = false;
      game.mouse_button_right  = false;
      game.gamepad_button_0    = false;
      game.gamepad_button_1    = false;
      game.gamepad_button_2    = false;
      game.gamepad_button_3    = false;
      menu.last_sellect        = -1;
      play_sound(sfx.menu_select);
      menu.option_select       = false;
      switch (menu.current_level)
      {
         case 0: //main menu
         switch (menu.current_button)
         {
            case 0: //new game selected
               enter_game_init();
               SDL_ShowCursor(SDL_DISABLE);
               game.status_game_active  = true;
               game.status_menu_active  = false;
            break;
            case 1: //load game selected
               menu.current_level       = 1;
               menu.current_button      = 0;
            break;
            case 2: //save game selected
               menu.current_level       = 2;
               menu.current_button      = 0;
            break;
            case 3: //resume game selected
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
            break;
            case 4: //options selected
               menu.current_level       = 3;
               menu.current_button      = 0;
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
               enter_game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
            break;
            case 1: //load game 1
               enter_game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
            break;
            case 2: //load game 2
               enter_game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
            break;
            case 3: //load game 3
               enter_game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
            break;
            case 4: //load game 4
               enter_game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
            break;
            case 5: //back to main menu
               menu.current_level       = 0;
               menu.current_button      = 1;
            break;
            default:
            break;
         }
         break;
         case 2: //Save game menu
         switch (menu.current_button)
         {
            case 0: //Save game 0
               enter_game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
            break;
            case 1: //Save game 1
               enter_game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
            break;
            case 2: //Save game 2
               enter_game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
            break;
            case 3: //Save game 3
               enter_game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
            break;
            case 4: //Save game 4
               enter_game_init();
               Load_Game(button_count);
               SDL_ShowCursor(SDL_DISABLE);
               game.status_menu_active  = false;
               game.status_game_active  = true;
            break;
            case 5: //back to main menu
               menu.current_level       = 0;
               menu.current_button      = 2;
            break;
            default:
            break;
         }
         break;
         case 3: //Options menu
         switch (menu.current_button)
         {
            case 0: //audio
               menu.current_level       = 4;
               menu.current_button      = 0;
            break;
            case 1: //Graphics
               menu.current_level       = 5;
               menu.current_button      = 0;
            break;
            case 2: //Keyboard
               menu.current_level       = 6;
               menu.current_button      = 0;
            break;
            case 3: //Mouse
               menu.current_level       = 7;
               menu.current_button      = 0;
            break;
            case 4: //Gamepad
               if (config.gamepad_enabled)
               {
                  menu.current_level       = 8;
                  menu.current_button      = 0;
               }
            break;
            case 5: //back to main menu
               menu.current_level       = 0;
               menu.current_button      = 4;
            break;
            default:
            break;
         }
         break;
         case 4: //Options - audio menu
         switch (menu.current_button)
         {
            case 0: //music volume

            break;
            case 1: //sound volume

            break;
            case 2: //rate
               if (menu.data_changed) re_init_audio();
               menu.data_changed = false;
               play_sound(sfx.menu_select);
            break;
            case 3: //buffers
               if (menu.data_changed) re_init_audio();
               menu.data_changed = false;
               play_sound(sfx.menu_select);
            break;
            case 4: //channels
               if (menu.data_changed) re_init_audio();
               menu.data_changed = false;
               play_sound(sfx.menu_select);
            break;
            case 5: //back to options menu
               menu.current_level       = 3;
               menu.current_button      = 0;
               if (menu.data_changed) re_init_audio();
               menu.data_changed = false;
            break;
            default:
            break;
         }
         break;
         case 5: //Options - graphics menu
         switch (menu.current_button)
         {
            case 0: //fullscreen
               if (menu.data_changed) re_init_graphics();
               menu.data_changed = false;
            break;
            case 1: //resolution
               if (menu.data_changed) re_init_graphics();
               menu.data_changed = false;
            break;
            case 2: //bbp
               if (menu.data_changed) re_init_graphics();
               menu.data_changed = false;
            break;
            case 3: //alpha blending
               if (menu.data_changed) re_init_graphics();
               menu.data_changed = false;
            break;
            case 4: //double buffering
               if (menu.data_changed) re_init_graphics();
               menu.data_changed = false;
            break;
            case 5: //back to options menu
               menu.current_level       = 3;
               menu.current_button      = 1;
               if (menu.data_changed) re_init_graphics();
               menu.data_changed = false;
            break;
            default:
            break;
         }
         break;
         case 6: //Options - keyboard menu
         switch (menu.current_button)
         {
            case 0: //audio

            break;
            case 1: //Graphics

            break;
            case 2: //Keyboard

            break;
            case 3: //Mouse

            break;
            case 4: //Gamepad

            break;
            case 5: //back to options menu
               menu.current_level       = 3;
               menu.current_button      = 2;
            break;
            default:
            break;
         }
         break;
         case 7: //Options - keyboard menu
         switch (menu.current_button)
         {
            case 0: //audio

            break;
            case 1: //Graphics

            break;
            case 2: //Keyboard

            break;
            case 3: //Mouse

            break;
            case 4: //Gamepad

            break;
            case 5: //back to options menu
               menu.current_level       = 3;
               menu.current_button      = 3;
            break;
            default:
            break;
         }
         break;
         case 8: //Options - gamepad menu
         switch (menu.current_button)
         {
            case 0: //audio

            break;
            case 1: //Graphics

            break;
            case 2: //Keyboard

            break;
            case 3: //Mouse

            break;
            case 4: //Gamepad

            break;
            case 5: //back to options menu
               menu.current_level       = 3;
               menu.current_button      = 4;
            break;
            default:
            break;
         }
         break;
         default:
         break;
     }
   }
   return(1);
}
