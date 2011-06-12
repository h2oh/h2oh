/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
 *
 * @author Paul Wortmann
 * @license GPL
 */
#ifndef CONFIG_H
#define CONFIG_H

#include <SDL/SDL.h>
#include <string>

struct config_type
{
   int  screen_resolution_menu;
   int  screen_resolution_x;
   int  screen_resolution_y;
   int  screen_bbp;
   int  screen_bbp_menu;
   bool screen_double_buffering;
   bool screen_double_buffering_menu;
   bool screen_alpha_blending;
   bool screen_alpha_blending_menu;
   bool screen_fullscreen;
   bool screen_fullscreen_menu;
   int  audio_rate;
   int  audio_rate_menu;
   int  audio_channels;
   int  audio_channels_menu;
   int  audio_buffers;
   int  audio_buffers_menu;
   int  audio_music_volume;
   int  audio_sound_volume;
   int  audio_current_song;
   int  keyboard_movement_menu;
   int  keyboard_run_menu;
   int  keyboard_jump_menu;
   int  keyboard_duck_menu;
   int  keyboard_select_menu;
   int  gamepad_run_menu;
   int  gamepad_jump_menu;
   int  gamepad_duck_menu;
   int  gamepad_select_menu;
   int  gamepad_invert_axes;
   int  gamepad_no_buttons;
   bool gamepad_enabled;
   int  mouse_resolution_x;
   int  mouse_resolution_y;
};

bool load_default_config(void);
bool save_config_file(const char *config_file);
bool load_config_file(const char *config_file);
bool init_log_file   (const char *log_file);
bool write_log_file  (const char *log_file, const char  log_data[]);
bool write_log_file  (const char *log_file, std::string log_data);
bool write_log_file  (const char *log_file, std::string log_data,   int         log_data_int);
bool write_log_file  (const char *log_file, std::string log_data,   float       log_data_float);
bool write_log_file  (const char *log_file, std::string log_data,   bool        log_data_bool);
bool write_log_file  (const char *log_file, int         log_data);
bool write_log_file  (const char *log_file, float       log_data);
bool write_log_file  (const char *log_file, bool        log_data);
bool write_log_file  (const char *log_file, std::string log_data_1, std::string log_data_2);
bool write_log_file  (const char *log_file, std::string log_data_1, const char  log_data_2[]);

#endif
