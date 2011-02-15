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

#include <time.h>
#include <stdlib.h>
#include "misc.hpp"

int seed_rand(void)
{
   srand(time(0));
}

double random_double(void)
{
  double temp_d = 0;

       do
       {
       temp_d = rand()%100;
       temp_d = 0.95 - (temp_d /50.9);
       }
       while ((temp_d > 2) and (temp_d < -2));
       return temp_d;
}

int random_int(void)
{
   return(rand()%65535);
}

int    random(int range)
{
   return(rand()%range);
}

int random_dec(void)
{
   return(rand()%10);
}

int random_cen(void)
{
   return(rand()%100);
}

float   random_GLcoord(void)
{
  double temp_f = 0;

       do
       {
       temp_f = rand()%100;
       temp_f = (0.95 - (temp_f /50.9))/2;
       }
       while ((temp_f > 1) and (temp_f < -1));
       return temp_f;
}


int convert_res_to_gl (int pos_x,int pos_y,int res_x,int res_y)
{
   float gl_x = ((pos_x / res_x) * 2) - 1;
   float gl_y = ((pos_y / res_y) * 2) - 1;
}
