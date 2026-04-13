/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <stdint.h>

enum oled_glyph {
    GLYPH_NONE  = 0x20,
    GLYPH_ESC   = 0x01,
    GLYPH_SHIFT = 0x02,
    GLYPH_RAISE = 0x03,
    GLYPH_LOWER = 0x04,
    GLYPH_ADJ   = 0x05,
    GLYPH_ALT   = 0x06,
    GLYPH_ENTER = 0x08,
    GLYPH_SPACE = 0x09,
    GLYPH_SUPER = 0x0B,
    GLYPH_TAB   = 0x0C,
    GLYPH_UP    = 0x18,
    GLYPH_DOWN  = 0x19,
    GLYPH_RIGHT = 0x1A,
    GLYPH_LEFT  = 0x1B,
};

char semignu_keycode_to_oled_char(uint16_t keycode);
