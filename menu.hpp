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

const int MAX_BUTTONS        = 16;
const int MAX_LEVELS         = 16;
const int MAX_SELECT_OPTIONS = 32;

struct select_option_type
{
   int image;
   int image_highlighted;
};

struct button_type
{
   bool                             type_normal;
   bool                             type_select;
   bool                             type_slider;
   float                            button_zoom;
   int                              max_value;
   int                              current_value;
   select_option_type               select_option[MAX_SELECT_OPTIONS];
   int                              image;
   int                              image_highlighted;
   int                              image_left;
   int                              image_left_highlighted;
   int                              image_right;
   int                              image_right_highlighted;
   int                              image_bar_value;
   int                              image_bar_under;
   int                              image_help; //help messages? under logo / quit button? breif description of button / default setting? or a popup bubble?
};

struct logo_type
{
   bool        drag;
   int         image;
   float       position_x;
   float       position_y;
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
   float       position_x;
   float       position_y;
   float       button_height;
   float       button_width;
   float       button_spacing;
   int         no_of_buttons;
   button_type button[MAX_BUTTONS];
};

struct menu_type
{
   level_type             level[MAX_LEVELS];
   int                    background_image;
   int                    current_button;
   int                    current_level;
   int                    last_sellect;
   float                  button_zoom_speed;
   float                  button_zoom_max;
   bool                   option_select;
   bool                   option_escape;
   bool                   option_up;
   bool                   option_down;
   bool                   option_left;
   bool                   option_right;
};

int  menu_system_init   (void);
int  menu_system_display(void);
int  menu_system_process(void);
bool mouse_over_button  (int level_count, int button_count, float mouse_x, float mouse_y);
