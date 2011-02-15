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
#include "music.hpp"

music_type music[MAX_MUSIC];
int current_track;

int init_music(void)
{
   current_track = -1;
   for(int count = 0; count < MAX_MUSIC; count++)
   {
      music[count].music = NULL;
   }
    return(0);
};

int load_music(void)
{
//    music[ 0].music = Mix_LoadMUS("data/music/level_00.s3m");
    return(0);
};

int kill_music(void)
{
   Mix_HaltMusic();
   for(int count = 0; count < MAX_MUSIC; count++)
   {
      Mix_FreeMusic(music[count].music);
   }
   return(0);
};

int play_music(int music_num)
{
   if (music_num != current_track)
   {
      current_track = music_num;
      Mix_PlayMusic(music[music_num].music,-1);
   }
   return(0);
};
