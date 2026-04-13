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

#ifdef OLED_ENABLE
static uint16_t get_effective_keycode(uint8_t layer, keypos_t key) {
    for (int8_t l = (int8_t)layer; l >= 0; l--) {
        uint16_t keycode = keymap_key_to_keycode((uint8_t)l, key);
        if (keycode != KC_TRNS) {
            return keycode;
        }
    }

    return KC_NO;
}

static void render_layer_bind_lines(void) {
    const uint8_t layer = get_highest_layer(layer_state);
    char          line[7];

    for (uint8_t r = 0; r < 4; r++) {
        for (uint8_t i = 0; i < 6; i++) {
            line[i] = ' ';
        }

        if (is_keyboard_left()) {
            if (r < 3) {
                for (uint8_t c = 0; c < 6; c++) {
                    line[c] = semignu_keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = r, .col = c}));
                }
            } else {
                line[3] = semignu_keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = 3, .col = 3}));
                line[4] = semignu_keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = 3, .col = 4}));
                line[5] = semignu_keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = 3, .col = 5}));
            }
        } else {
            if (r < 3) {
                const uint8_t row = 4 + r;
                for (uint8_t c = 0; c < 6; c++) {
                    line[c] = semignu_keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = row, .col = 5 - c}));
                }
            } else {
                line[0] = semignu_keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = 7, .col = 5}));
                line[1] = semignu_keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = 7, .col = 4}));
                line[2] = semignu_keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = 7, .col = 3}));
            }
        }

        line[6] = '\0';
        oled_set_cursor(0, 12 + r);
        oled_write(line, false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_render_bongocat(void) {
    uint8_t logo[2][6] = {
        {0x80, 0x81, 0x82, 0x83, 0x84, 0x85},
        {0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B},
    };
    bool left_pressed  = false;
    bool right_pressed = false;

    for (uint8_t row = 0; row < (MATRIX_ROWS / 2); row++) {
        if (matrix_get_row(row) != 0) {
            left_pressed = true;
            break;
        }
    }

    for (uint8_t row = (MATRIX_ROWS / 2); row < MATRIX_ROWS; row++) {
        if (matrix_get_row(row) != 0) {
            right_pressed = true;
            break;
        }
    }

    if (left_pressed) {
        logo[0][1] = 0x8C;
        logo[1][1] = 0x8D;
    }

    if (right_pressed) {
        logo[1][3] = 0x8E;
        logo[1][4] = 0x8F;
    }

    oled_set_cursor(0, 4);
    for (uint8_t i = 0; i < 2; i++) {
        for (uint8_t j = 0; j < 6; j++) {
            oled_write_char(logo[i][j], false);
        }
    }
}

void oled_render_semignu(void) {
    uint8_t logo[3][6] = {
        {0x20, 0x94, 0x95, 0x96, 0x97, 0x20},
        {0x20, 0x98, 0x99, 0x9a, 0x9b, 0x20},
        {0x20, 0x9c, 0x9d, 0x9e, 0x9f, 0x20},
    };

    oled_set_cursor(0, 4);
    for (uint8_t i = 0; i < 3; i++) {
        for (uint8_t j = 0; j < 6; j++) {
            oled_write_char(logo[i][j], false);
        }
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_semignu();
    } else {
        oled_render_bongocat();
    }

    render_layer_bind_lines();
    return false;
}
#endif
