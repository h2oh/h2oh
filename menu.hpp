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

struct background_scroll_type
{
   int   x_dir;
   int   y_dir;
   float x_pos;
   float y_pos;
   float scroll_rate;
};

struct menu_type
{
    background_scroll_type background_scroll[2];
    int  level;
    int  position;
    int  possition_max;
};

int menu_init(void);
int menu_display(void);
int menu_process(void);
int background_process(void);

