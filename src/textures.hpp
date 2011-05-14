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

#include <GL/gl.h>

const int MAX_TEXTURES = 320;
struct texture_type
{
   GLuint texture;
};

struct image_type
{
   int main_logo;
   int new_game;
   int new_game_highlighted;
   int save_game;
   int save_game_highlighted;
   int load_game;
   int load_game_highlighted;
   int resume_game;
   int resume_game_highlighted;
   int quit_game;
   int quit_game_highlighted;
   int options;
   int options_highlighted;
   int main_menu;
   int main_menu_highlighted;
   int game_0;
   int game_0_highlighted;
   int game_1;
   int game_1_highlighted;
   int game_2;
   int game_2_highlighted;
   int game_3;
   int game_3_highlighted;
   int game_4;
   int game_4_highlighted;
   int game_5;
   int game_5_highlighted;
   int options_menu;
   int options_menu_highlighted;
   int audio;
   int audio_highlighted;
   int graphics;
   int graphics_highlighted;
   int keyboard;
   int keyboard_highlighted;
   int mouse;
   int mouse_highlighted;
   int gamepad;
   int gamepad_highlighted;
   int arrow_left;
   int arrow_left_highlighted;
   int arrow_right;
   int arrow_right_highlighted;
   int bar;
   int bar_highlighted;
   int slider_bar_top;
   int slider_bar_bottom;
   int _0;
   int _0_highlighted;
   int _1;
   int _1_highlighted;
   int _10;
   int _10_highlighted;
   int _1024;
   int _1024_highlighted;
   int _1024x768;
   int _1024x768_highlighted;
   int _11;
   int _11_highlighted;
   int _12;
   int _12_highlighted;
   int _1280x1024;
   int _1280x1024_highlighted;
   int _1366x768;
   int _1366x768_highlighted;
   int _1440x900;
   int _1440x900_highlighted;
   int _16;
   int _16_highlighted;
   int _1680x1050;
   int _1680x1050_highlighted;
   int _1920x1080;
   int _1920x1080_highlighted;
   int _2;
   int _2_highlighted;
   int _2048;
   int _2048_highlighted;
   int _22050;
   int _22050_highlighted;
   int _3;
   int _3_highlighted;
   int _32;
   int _32_highlighted;
   int _4;
   int _4_highlighted;
   int _4096;
   int _4096_highlighted;
   int _44100;
   int _44100_highlighted;
   int _44800;
   int _44800_highlighted;
   int _5;
   int _5_highlighted;
   int _6;
   int _6_highlighted;
   int _600x800;
   int _600x800_highlighted;
   int _64;
   int _64_highlighted;
   int _640x480;
   int _640x480_highlighted;
   int _7;
   int _7_highlighted;
   int _8;
   int _8_highlighted;
   int _8192;
   int _8192_highlighted;
   int _9;
   int _9_highlighted;
   int a;
   int a_highlighted;
   int alpha_blending;
   int alpha_blending_highlighted;
   int arrows;
   int arrows_highlighted;
   int audio_buffer;
   int audio_buffer_highlighted;
   int audio_rate;
   int audio_rate_highlighted;
   int b;
   int b_highlighted;
   int bbp;
   int bbp_highlighted;
   int button_duck;
   int button_duck_highlighted;
   int button_jump;
   int button_jump_highlighted;
   int button_run;
   int button_run_highlighted;
   int button_select;
   int button_select_highlighted;
   int c;
   int c_highlighted;
   int channels;
   int channels_highlighted;
   int d;
   int d_highlighted;
   int disabled;
   int disabled_highlighted;
   int double_buffering;
   int double_buffering_highlighted;
   int e;
   int e_highlighted;
   int enabled;
   int enabled_highlighted;
   int f;
   int f_highlighted;
   int fullscreen;
   int fullscreen_highlighted;
   int g;
   int g_highlighted;
   int h;
   int h_highlighted;
   int i;
   int i_highlighted;
   int invert_axes;
   int invert_axes_highlighted;
   int invert_mouse;
   int invert_mouse_highlighted;
   int j;
   int j_highlighted;
   int k;
   int k_highlighted;
   int key_duck;
   int key_duck_highlighted;
   int key_jump;
   int key_jump_highlighted;
   int key_run;
   int key_run_highlighted;
   int key_select;
   int key_select_highlighted;
   int l;
   int l_highlighted;
   int m;
   int m_highlighted;
   int movement;
   int movement_highlighted;
   int music_volume;
   int music_volume_highlighted;
   int n;
   int n_highlighted;
   int o;
   int o_highlighted;
   int p;
   int p_highlighted;
   int q;
   int q_highlighted;
   int r;
   int r_highlighted;
   int resolution;
   int resolution_highlighted;
   int s;
   int s_highlighted;
   int sensitivity;
   int sensitivity_highlighted;
   int sound_volume;
   int sound_volume_highlighted;
   int swap_buttons;
   int swap_buttons_highlighted;
   int t;
   int t_highlighted;
   int u;
   int u_highlighted;
   int v;
   int v_highlighted;
   int w;
   int w_highlighted;
   int wasd;
   int wasd_highlighted;
   int x;
   int x_highlighted;
   int y;
   int y_highlighted;
   int z;
   int z_highlighted;

   int background_00;
   int background_01;
   int background_02;
   int background_03;
   int menu_background_00;
   int particle_flake;
};

int init_textures(void);
int load_texture (int texture_number, const char File_Name[]);
int load_textures(void);
int kill_textures(void);

