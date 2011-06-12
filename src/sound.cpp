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

#include "sound.hpp"
#include "config.hpp"

const char       App_LogF[] = "Outcast Island.log";
      sound_type sound;

int load_sounds(void)
{
    int sfx_count = 0;
    sound.menu_move.load  ("data/sound/menu_move.wav");  sfx_count++;
    sound.menu_select.load("data/sound/menu_select.wav");sfx_count++;
    write_log_file(App_LogF,"Sound files loaded -> ",sfx_count);
    return(1);
};

sound_class::sound_class()
{
    sound_channel = -1;
};

sound_class::~sound_class()
{
    Mix_HaltChannel(-1);
    Mix_FreeChunk(sound_data);
};

void sound_class::load(std::string file_name)
{
    sound_data = Mix_LoadWAV(file_name.c_str());
};

void sound_class::play(void)
{
    sound_channel = Mix_PlayChannel(-1, sound_data, 0);
};

