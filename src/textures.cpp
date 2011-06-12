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

#include <GL/gl.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "textures.hpp"
#include "game.hpp"
#include "config.hpp"

#define GL_BGR  0x80E0
#define GL_BGRA 0x80E1
image_type   image;
texture_type texture[MAX_TEXTURES];
const char App_LogF[] = "H2oH.log";

int load_textures(void)
{
   int texture_count = 0;
   load_texture(texture_count,"data/textures/menu/main_logo.png");image.main_logo = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/new_game.png");image.new_game = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/new_game_highlighted.png");image.new_game_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/save_game.png");image.save_game = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/save_game_highlighted.png");image.save_game_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/load_game.png");image.load_game = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/load_game_highlighted.png");image.load_game_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/resume_game.png");image.resume_game = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/resume_game_highlighted.png");image.resume_game_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/quit_game.png");image.quit_game = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/quit_game_highlighted.png");image.quit_game_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/options.png");image.options = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/options_highlighted.png");image.options_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/main_menu.png");image.main_menu = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/main_menu_highlighted.png");image.main_menu_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_0.png");image.game_0 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_0_highlighted.png");image.game_0_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_1.png");image.game_1 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_1_highlighted.png");image.game_1_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_2.png");image.game_2 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_2_highlighted.png");image.game_2_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_3.png");image.game_3 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_3_highlighted.png");image.game_3_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_4.png");image.game_4 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_4_highlighted.png");image.game_4_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_5.png");image.game_5 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/game_5_highlighted.png");image.game_5_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/options_menu.png");image.options_menu = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/options_menu_highlighted.png");image.options_menu_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/audio.png");image.audio = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/audio_highlighted.png");image.audio_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/graphics.png");image.graphics = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/graphics_highlighted.png");image.graphics_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/keyboard.png");image.keyboard = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/keyboard_highlighted.png");image.keyboard_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/mouse.png");image.mouse = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/mouse_highlighted.png");image.mouse_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/gamepad.png");image.gamepad = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/gamepad_highlighted.png");image.gamepad_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/arrow_left.png");image.arrow_left = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/arrow_left_highlighted.png");image.arrow_left_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/arrow_right.png");image.arrow_right = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/arrow_right_highlighted.png");image.arrow_right_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/bar.png");image.bar = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/bar_highlighted.png");image.bar_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/slider_bar_top.png");image.slider_bar_top = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/slider_bar_bottom.png");image.slider_bar_bottom = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/0.png");image._0 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/0_highlighted.png");image._0_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1.png");image._1 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/10.png");image._1_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1024.png");image._1024 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1024x768.png");image._1024x768 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1024x768_highlighted.png");image._1024x768_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1024_highlighted.png");image._1024_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/10_highlighted.png");image._10_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/11.png");image._11 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/11_highlighted.png");image._11_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/12.png");image._12 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1280x1024.png");image._1280x1024 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1280x1024_highlighted.png");image._1280x1024_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/12_highlighted.png");image._12_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1366x768.png");image._1366x768 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1366x768_highlighted.png");image._1366x768_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1440x900.png");image._1440x900 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1440x900_highlighted.png");image._1440x900_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/16.png");image._16 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1680x1050.png");image._1680x1050 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1680x1050_highlighted.png");image._1680x1050_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/16_highlighted.png");image._16_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1920x1080.png");image._1920x1080 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1920x1080_highlighted.png");image._1920x1080_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/1_highlighted.png");image._1_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/2.png");image._2 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/2048.png");image._2048 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/2048_highlighted.png");image._2048_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/22050.png");image._22050 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/22050_highlighted.png");image._22050_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/2_highlighted.png");image._2_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/3.png");image._3 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/32.png");image._32 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/32_highlighted.png");image._32_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/3_highlighted.png");image._3_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/4.png");image._4 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/4096.png");image._4096 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/4096_highlighted.png");image._4096_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/44100.png");image._44100 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/44100_highlighted.png");image._44100_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/44800.png");image._44800 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/44800_highlighted.png");image._44800_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/4_highlighted.png");image._4_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/5.png");image._5 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/5_highlighted.png");image._5_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/6.png");image._6 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/600x800.png");image._600x800 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/600x800_highlighted.png");image._600x800_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/64.png");image._64 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/640x480.png");image._640x480 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/640x480_highlighted.png");image._640x480_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/64_highlighted.png");image._64_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/6_highlighted.png");image._6_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/7.png");image._7 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/7_highlighted.png");image._7_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/8.png");image._8 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/8192.png");image._8192 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/8192_highlighted.png");image._8192_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/8_highlighted.png");image._8_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/9.png");image._9 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/9_highlighted.png");image._9_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/a.png");image.a = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/alpha_blending.png");image.alpha_blending = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/alpha_blending_highlighted.png");image.alpha_blending_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/arrows.png");image.arrows = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/arrows_highlighted.png");image.arrows_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/audio_buffer.png");image.audio_buffer = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/audio_buffer_highlighted.png");image.audio_buffer_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/audio_rate.png");image.audio_rate = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/audio_rate_highlighted.png");image.audio_rate_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/a_highlighted.png");image.a_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/b.png");image.b = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/bbp.png");image.bbp = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/bbp_highlighted.png");image.bbp_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/button_duck.png");image.button_duck = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/button_duck_highlighted.png");image.button_duck_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/button_jump.png");image.button_jump = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/button_jump_highlighted.png");image.button_jump_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/button_run.png");image.button_run = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/button_run_highlighted.png");image.button_run_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/button_select.png");image.button_select = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/button_select_highlighted.png");image.button_select_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/b_highlighted.png");image.b_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/c.png");image.c = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/channels.png");image.channels = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/channels_highlighted.png");image.channels_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/c_highlighted.png");image.c_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/d.png");image.d = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/disabled.png");image.disabled = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/disabled_highlighted.png");image.disabled_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/double_buffering.png");image.double_buffering = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/double_buffering_highlighted.png");image.double_buffering_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/d_highlighted.png");image.d_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/e.png");image.e = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/enabled.png");image.enabled = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/enabled_highlighted.png");image.enabled_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/e_highlighted.png");image.e_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/f.png");image.f = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/fullscreen.png");image.fullscreen = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/fullscreen_highlighted.png");image.fullscreen_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/f_highlighted.png");image.f_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/g.png");image.g = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/g_highlighted.png");image.g_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/h.png");image.h = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/h_highlighted.png");image.h_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/i.png");image.i = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/invert_axes.png");image.invert_axes = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/invert_axes_highlighted.png");image.invert_axes_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/invert_mouse.png");image.invert_mouse = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/invert_mouse_highlighted.png");image.invert_mouse_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/i_highlighted.png");image.i_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/j.png");image.j = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/j_highlighted.png");image.j_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/k.png");image.k = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/key_duck.png");image.key_duck = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/key_duck_highlighted.png");image.key_duck_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/key_jump.png");image.key_jump = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/key_jump_highlighted.png");image.key_jump_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/key_run.png");image.key_run = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/key_run_highlighted.png");image.key_run_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/key_select.png");image.key_select = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/key_select_highlighted.png");image.key_select_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/k_highlighted.png");image.k_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/l.png");image.l = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/l_highlighted.png");image.l_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/m.png");image.m = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/movement.png");image.movement = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/movement_highlighted.png");image.movement_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/music_volume.png");image.music_volume = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/music_volume_highlighted.png");image.music_volume_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/m_highlighted.png");image.m_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/n.png");image.n = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/n_highlighted.png");image.n_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/o.png");image.o = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/o_highlighted.png");image.o_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/p.png");image.p = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/p_highlighted.png");image.p_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/q.png");image.q = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/q_highlighted.png");image.q_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/r.png");image.r = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/resolution.png");image.resolution = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/resolution_highlighted.png");image.resolution_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/r_highlighted.png");image.r_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/s.png");image.s = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/sensitivity.png");image.sensitivity = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/sensitivity_highlighted.png");image.sensitivity_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/sound_volume.png");image.sound_volume = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/sound_volume_highlighted.png");image.sound_volume_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/swap_buttons.png");image.swap_buttons = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/swap_buttons_highlighted.png");image.swap_buttons_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/s_highlighted.png");image.s_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/t.png");image.t = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/t_highlighted.png");image.t_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/u.png");image.u = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/u_highlighted.png");image.u_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/v.png");image.v = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/v_highlighted.png");image.v_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/w.png");image.w = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/wasd.png");image.wasd = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/wasd_highlighted.png");image.wasd_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/w_highlighted.png");image.w_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/x.png");image.x = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/x_highlighted.png");image.x_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/y.png");image.y = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/y_highlighted.png");image.y_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/z.png");image.z = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/z_highlighted.png");image.z_highlighted = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/backgrounds/background_00.png");image.background_00 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/backgrounds/background_01.png");image.background_01 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/backgrounds/background_02.png");image.background_02 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/backgrounds/background_03.png");image.background_03 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/menu/menu_background_00.png");image.menu_background_00 = texture_count;texture_count++;
   load_texture(texture_count,"data/textures/particles/flake.png");image.particle_flake = texture_count;texture_count++;
   return(1);
};

int init_textures(void)
{
   for(int count = 0; count < MAX_TEXTURES; count++)
   {
      texture[count].texture = texture[count].texture;
   }
   return(1);
};

int kill_textures(void)
{
   for(int count = 0; count < MAX_TEXTURES; count++)
   {
      glDeleteTextures(1, &texture[count].texture);
   }
   return(1);
};

int load_texture (int texture_number, const char File_Name[])
{
   SDL_Surface *surface;
   GLenum       texture_format = GL_RGBA;
   GLint        no_of_colors;

   if ((surface = IMG_Load(File_Name)))
   {
      if ((surface->w & (surface->w - 1)) != 0 );
      if ((surface->h & (surface->h - 1)) != 0 );
      no_of_colors = surface->format->BytesPerPixel;
      if (no_of_colors == 4)
      {
         if (surface->format->Rmask == 0x000000ff) texture_format = GL_RGBA;
         else texture_format = GL_BGRA;
      }
      else if (no_of_colors == 3)
      {
         if (surface->format->Rmask == 0x000000ff) texture_format = GL_RGB;
         else texture_format = GL_BGR;
      }
      else write_log_file(App_LogF,"The image is not 24bit...");
      glGenTextures( 1, &texture[texture_number].texture);
      glBindTexture( GL_TEXTURE_2D, texture[texture_number].texture);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
      glTexImage2D( GL_TEXTURE_2D, 0, no_of_colors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels );
   }
   else
   {
      write_log_file(App_LogF,"SDL could not load image.");
      SDL_Quit();
      return(0);
   }
   if (surface) SDL_FreeSurface(surface);
   return(1);
}
