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

const int MAX_BUTTONS = 16;
const int MAX_LEVELS  = 16;

struct background_scroll_type
{
   int   x_dir;
   int   y_dir;
   float x_pos;
   float y_pos;
   float scroll_rate;
};

struct button_type
{
   bool  type_normal;
   bool  type_toggle;
   bool  type_horizontal_sellect;
   float button_zoom;
   int   image;
   int   image_highlighted;
   int   image_toggle_true;
   int   image_toggle_true_highlighted;
   int   image_toggle_false;
   int   image_toggle_false_highlighted;
   int   image_horizontal_sellect_data;
   int   image_horizontal_sellect_left;
   int   image_horizontal_sellect_left_highlighted;
   int   image_horizontal_sellect_right;
   int   image_horizontal_sellect_right_highlighted;
};

struct logo_type
{
   bool        drag;
   int         image;
   float       possition_x;
   float       possition_y;
   float       drag_offset_x;
   float       drag_offset_y;
   float       height;
   float       width;
};

struct level_type
{
   logo_type   logo;
   bool        type_normal;
   bool        type_button_zoom;
   float       possition_x;
   float       possition_y;
   float       button_height;
   float       button_width;
   float       button_spacing;
   int         no_of_buttons;
   button_type button[MAX_BUTTONS];
};

struct menu_type
{
   level_type             level[MAX_LEVELS];
   int                    current_button;
   int                    current_level;
   int                    last_sellect;
   float                  button_zoom_speed;
   float                  button_zoom_max;
   background_scroll_type background_scroll[2];
};

int  background_process (void);
int  menu_system_init   (void);
int  menu_system_display(void);
int  menu_system_process(void);
bool mouse_over_button  (int level_count, int button_count, float mouse_x, float mouse_y);
