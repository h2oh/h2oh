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

#include <fstream>
#include "game.hpp"
#include "savegame.hpp"

extern game_type game;

int Save_Game(int slot)
{
  char save_slot[17];
  if (slot == 0) for(int count = 0; count < 18; count++) save_slot[count] = Slot_00[count];
  if (slot == 1) for(int count = 0; count < 18; count++) save_slot[count] = Slot_01[count];
  if (slot == 2) for(int count = 0; count < 18; count++) save_slot[count] = Slot_02[count];
  if (slot == 3) for(int count = 0; count < 18; count++) save_slot[count] = Slot_03[count];
  if (slot == 4) for(int count = 0; count < 18; count++) save_slot[count] = Slot_04[count];
  if (slot == 5) for(int count = 0; count < 18; count++) save_slot[count] = Slot_05[count];
  std::fstream savegamefile(save_slot,std::ios::out|std::ios::binary|std::ios::trunc);
  if (savegamefile.is_open())
  {
     savegamefile.write(reinterpret_cast<char*>(&game), sizeof(game_type));
     savegamefile.close();
  }
  else return(1);
  return(0);
};

int Load_Game(int slot)
{
  char save_slot[17];
  if (slot == 0) for(int count = 0; count < 18; count++) save_slot[count] = Slot_00[count];
  if (slot == 1) for(int count = 0; count < 18; count++) save_slot[count] = Slot_01[count];
  if (slot == 2) for(int count = 0; count < 18; count++) save_slot[count] = Slot_02[count];
  if (slot == 3) for(int count = 0; count < 18; count++) save_slot[count] = Slot_03[count];
  if (slot == 4) for(int count = 0; count < 18; count++) save_slot[count] = Slot_04[count];
  if (slot == 5) for(int count = 0; count < 18; count++) save_slot[count] = Slot_05[count];
  std::fstream savegamefile(save_slot,std::ios::in|std::ios::binary);
  if (savegamefile.is_open())
  {
     savegamefile.read(reinterpret_cast<char*>(&game), sizeof(game_type));
     savegamefile.close();
  }
  else return(1);
  return(0);
};
