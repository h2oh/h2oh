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

#include "physics.hpp"
#include <math.h>

bool  cube_collision       (float x1, float y1, float z1, float w1, float h1, float d1, float x2, float y2, float z2, float w2, float h2, float d2)
{
if (((x1-(w1/2) < x2+(w2/2)) && (x2+(w2/2) > x1-(w1/2))) && ((x2-(w2/2) < x1+(w1/2)) && (x1+(w1/2) > x2-(w2/2)))
 && ((y1-(h1/2) < y2+(h2/2)) && (y2+(h2/2) > y1-(h1/2))) && ((y2-(h2/2) < y1+(h1/2)) && (y1+(h1/2) > y2-(h2/2)))
 && ((z1-(d1/2) < z2+(d2/2)) && (z2+(d2/2) > z1-(d1/2))) && ((z2-(d2/2) < z1+(d1/2)) && (z1+(d1/2) > z2-(d2/2)))) return(true);
else return(false);
}

bool quadrangle_collision   (float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
if (((x1-(w1/2) < x2+(w2/2)) && (x2+(w2/2) > x1-(w1/2))) && ((x2-(w2/2) < x1+(w1/2)) && (x1+(w1/2) > x2-(w2/2)))
 && ((y1-(h1/2) < y2+(h2/2)) && (y2+(h2/2) > y1-(h1/2))) && ((y2-(h2/2) < y1+(h1/2)) && (y1+(h1/2) > y2-(h2/2)))) return(true);
else return(false);
}

bool circle_collision(float x1, float y1, float r1, float x2, float y2, float r2)
{
   if (((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)) < ((r1+r2)+(r1+r2))) return(true);
   else return(false);
}

bool shere_collision(float x1, float y1, float z1, float r1, float x2, float y2, float z2, float r2)
{
   if ((((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1))+((z2-z1)*(z2-z1))) < ((r1+r2)+(r1+r2))) return(true);
   else return(false);
}

float distance_2D(float x1, float y1, float x2, float y2)
{
   return(sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))));
}

float distance_3D(float x1, float y1, float z1, float x2, float y2, float z2)
{
   return(sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))+((z1-z2)*(z1-z2))));
}

bool  point_in_quadrangle  (float qx, float qw, float qy, float qh, float px, float py)
{
    if ((px > (qx-(qw/2))) && (px < (qx+(qw/2))) && (py > (qy-(qh/2))) && (py < (qy+(qh/2)))) return(true);
    else return(false);
};
