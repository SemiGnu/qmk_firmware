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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LALT,         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      KC_LGUI, MO(2), KC_LSFT,          KC_SPC, MO(1), KC_ENT
                                      //`--------------------------'  `--------------------------'
    ),

    [1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______,         KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_UNDS,                 KC_PLUS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_DEL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,         KC_HASH, KC_CIRC, KC_LPRN, KC_RPRN, KC_DLR,                  KC_EQL,  KC_4,    KC_5,    KC_6,    KC_MINS, KC_GRV,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,         KC_3,    KC_E,    KC_1,    KC_Q,    KC_PIPE,                 KC_0,    KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      _______, MO(3), _______,          _______, _______, _______
                                      //`--------------------------'  `--------------------------'
    ),

    [2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______,         KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_UNDS,                 KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,         KC_HASH, KC_CIRC, KC_LPRN, KC_RPRN, KC_DLR,                  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,         KC_PERC, KC_AMPR, KC_LBRC, KC_RBRC, KC_PIPE,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      _______, _______, _______,          _______, MO(3), _______
                                      //`--------------------------'  `--------------------------'
    ),

    [3] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RM_TOGG,         RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                 KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RM_NEXT,         RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                 KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      _______, _______, _______,          _______, _______, _______
                                      //`--------------------------'  `--------------------------'
    )
};
// clang-format on

