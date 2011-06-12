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
#ifndef SAVEGAME_H
#define SAVEGAME_H

const char Slot_00[] = "save/slot_00.sav";
const char Slot_01[] = "save/slot_01.sav";
const char Slot_02[] = "save/slot_02.sav";
const char Slot_03[] = "save/slot_03.sav";
const char Slot_04[] = "save/slot_04.sav";
const char Slot_05[] = "save/slot_05.sav";

int Save_Game(int slot);
int Load_Game(int slot);

#endif
