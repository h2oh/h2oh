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

#include "sound.hpp"

sound_type sound[MAX_SOUNDS];

int init_sounds(void)
{
   for(int count = 0; count < MAX_SOUNDS; count++)
   {
      sound[count].active  = false;
      sound[count].channel = -1;
      sound[count].sound = NULL;
   }
    return(1);
};

int load_sounds(void)
{
//    sound[0].active =  true; sound[0].sound =  Mix_LoadWAV("data/sound/menu_move.wav");
    return(1);
};

int kill_sounds(void)
{
   Mix_HaltChannel(-1);
   for(int count = 0; count < MAX_SOUNDS; count++)
   {
      if (sound[count].active == true) Mix_FreeChunk(sound[count].sound);
      sound[count].active = false;
   }
   return(1);
};

int play_sound (int sound_num)
{
   sound[sound_num].channel = Mix_PlayChannel(-1, sound[sound_num].sound, 0);
   return(1);
};
