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


bool  cube_collision       (float x1, float y1, float z1, float w1, float h1, float d1, float x2, float y2, float z2, float w2, float h2, float d2);
bool  quadrangle_collision (float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
bool  circle_collision     (float a_x, float a_y, float a_r, float b_x, float b_y, float b_r);
bool  shere_collision      (float x1, float y1, float z1, float r1, float x2, float y2, float z2, float r2);
float distance_2D          (float x1, float y1, float x2, float y2);
float distance_3D          (float x1, float y1, float z1, float x2, float y2, float z2);
bool  point_in_quadrangle  (float qx, float qw, float qy, float qh, float px, float py);
