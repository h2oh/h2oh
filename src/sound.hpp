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
#ifndef SOUND_H
#define SOUND_H

#include <SDL/SDL_mixer.h>
#include <string>

int load_sounds(void);

class sound_class
{
    int        sound_channel;
    Mix_Chunk *sound_data;
    public:
    sound_class();
   ~sound_class();
    void play(void);
    void load(std::string file_name);
};

struct sound_type
{
    sound_class menu_move;
    sound_class menu_select;
};

#endif
