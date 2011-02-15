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

#include <fstream>
#include "config.hpp"

config_type config;

bool load_default_config(void)
{
   config.screen_resolution_menu  = 0;
   config.screen_resolution_x     = 640;
   config.screen_resolution_y     = 480;
   config.screen_bbp              = 32;
   config.screen_double_buffering = true;
   config.screen_alpha_blending   = true;
   config.screen_fullscreen       = false;
   config.audio_rate              = 44100;
   config.audio_channels          = 16;
   config.audio_buffers           = 2048;
   config.audio_music_volume      = 32;
   config.audio_sound_volume      = 64;
   return(1);
}

bool save_config_file(const char *config_file)
{
  std::fstream configfile(config_file,std::ios::out|std::ios::binary|std::ios::trunc);
  if (configfile.is_open())
  {
     configfile.write(reinterpret_cast<char*>(&config), sizeof(config_type));
     configfile.close();
  }
  else return(1);
  return(0);
};

bool load_config_file(const char *config_file)
{
  std::fstream configfile(config_file,std::ios::in|std::ios::binary);
  if (configfile.is_open())
  {
     configfile.read(reinterpret_cast<char*>(&config), sizeof(config_type));
     configfile.close();
  }
  else return(1);
  return(0);
};

bool init_log_file(const char *log_file)
{
  std::fstream logfile(log_file,std::ios::out|std::ios::binary|std::ios::trunc);
  if (logfile.is_open()) logfile.close();
  else return(1);
  return(0);
};

bool write_log_file(const char *log_file, char error_string[])
{
  std::fstream logfile(log_file,std::ios::out|std::ios::app);
  if (logfile.is_open())
  {
     logfile << error_string;
     logfile << "\n";
     logfile.close();
  }
  else return(1);
  return(0);
};
