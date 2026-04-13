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

#include QMK_KEYBOARD_H

#include "oled_symbols.h"

char semignu_keycode_to_oled_char(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            return 'A' + (char)(keycode - KC_A);
        case KC_1 ... KC_9:
            return '1' + (char)(keycode - KC_1);
        case KC_0:
            return '0';
        case KC_EXLM:
            return '!';
        case KC_AT:
            return '@';
        case KC_HASH:
            return '#';
        case KC_DLR:
            return '$';
        case KC_PERC:
            return '%';
        case KC_CIRC:
            return '^';
        case KC_AMPR:
            return '&';
        case KC_ASTR:
        case KC_KP_ASTERISK:
            return '*';
        case KC_LPRN:
            return '(';
        case KC_RPRN:
            return ')';
        case KC_MINS:
            return '-';
        case KC_UNDS:
            return '_';
        case KC_EQL:
            return '=';
        case KC_PLUS:
            return '+';
        case KC_LBRC:
            return '[';
        case KC_LCBR:
            return '{';
        case KC_RBRC:
            return ']';
        case KC_RCBR:
            return '}';
        case KC_BSLS:
            return '\\';
        case KC_PIPE:
            return '|';
        case KC_SCLN:
            return ';';
        case KC_QUOT:
            return '\'';
        case KC_COMM:
            return ',';
        case KC_DOT:
            return '.';
        case KC_SLSH:
            return '/';
        case KC_GRV:
            return '`';
        case KC_TILD:
            return '~';
        case KC_LEFT:
            return (char)GLYPH_LEFT;
        case KC_DOWN:
            return (char)GLYPH_DOWN;
        case KC_UP:
            return (char)GLYPH_UP;
        case KC_RGHT:
            return (char)GLYPH_RIGHT;
        case KC_TAB:
            return (char)GLYPH_TAB;
        case KC_ESC:
            return (char)GLYPH_ESC;
        case KC_BSPC:
            return '<';
        case KC_DEL:
            return '>';
        case KC_ENT:
            return (char)GLYPH_ENTER;
        case KC_SPC:
            return (char)GLYPH_SPACE;
        case KC_LSFT:
        case KC_RSFT:
            return (char)GLYPH_SHIFT;
        case KC_LCTL:
        case KC_RCTL:
            return 'c';
        case KC_LALT:
        case KC_RALT:
            return (char)GLYPH_ALT;
        case KC_LGUI:
        case KC_RGUI:
            return (char)GLYPH_SUPER;
        case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            uint8_t l = QK_MOMENTARY_GET_LAYER(keycode);
            if (l == 1) return (char)GLYPH_LOWER;
            if (l == 2) return (char)GLYPH_RAISE;
            if (l == 3) return (char)GLYPH_ADJ;
            return 'r';
        case QK_TO ... QK_TO_MAX:
        case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
        case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            return 'l';
        case KC_TRNS:
            return ' ';
        case KC_NO:
            return ' ';
        default:
            break;
    }

    if (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) {
        return semignu_keycode_to_oled_char(QK_MOD_TAP_GET_TAP_KEYCODE(keycode));
    }

    if (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) {
        return semignu_keycode_to_oled_char(QK_LAYER_TAP_GET_TAP_KEYCODE(keycode));
    }

    return '?';
}
