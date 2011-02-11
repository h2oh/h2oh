/* Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "h2oh"
 *
 * "h2oh" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * "h2oh" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "h2oh" If not, see <http://www.gnu.org/licenses/>.
 */


struct game_type
{
   bool      status_menu_active;
   bool      status_game_active;
   bool      status_quit_active;
   SDL_Event event;
};

int game_init(void);
int game_display(void);
int game_process(void);
int game_deinit(void);
