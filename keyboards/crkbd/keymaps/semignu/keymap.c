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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RALT,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, MO(2), KC_LSFT, KC_SPC, MO(1), KC_ENT
                                                                  //`--------------------------'  `--------------------------'

                                                                  ),

                                                              [1] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_4, KC_5, KC_6, KC_KP_ASTERISK, KC_BACKSLASH,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0, KC_1, KC_2, KC_3, _______, _______,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, MO(3), KC_SPC, KC_ENT, _______, KC_RALT
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [2] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, _______, KC_SPC, KC_ENT, MO(3), KC_RALT
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [3] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RALT
                                                                  //`--------------------------'  `--------------------------'
                                                                  )};

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

enum oled_glyph {
    GLYPH_NONE  = 0x20, // regular space
    GLYPH_ESC   = 0x01,
    GLYPH_SHIFT = 0x02,
    GLYPH_RAISE = 0x03,
    GLYPH_LOWER = 0x04,
    GLYPH_ALT   = 0x06,
    GLYPH_ENTER = 0x08,
    GLYPH_SPACE = 0x09,
    GLYPH_SUPER = 0x0B,
    GLYPH_TAB   = 0x0C,
};

static char keycode_to_oled_char(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            return 'A' + (char)(keycode - KC_A);
        case KC_1 ... KC_9:
            return '1' + (char)(keycode - KC_1);
        case KC_0:
            return '0';
        case KC_MINS:
            return '-';
        case KC_EQL:
            return '=';
        case KC_LBRC:
            return '[';
        case KC_RBRC:
            return ']';
        case KC_BSLS:
            return '\\';
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
        return keycode_to_oled_char(QK_MOD_TAP_GET_TAP_KEYCODE(keycode));
    }

    if (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) {
        return keycode_to_oled_char(QK_LAYER_TAP_GET_TAP_KEYCODE(keycode));
    }

    return '?';
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
                    line[c] = keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = r, .col = c}));
                }
            } else {
                line[3] = keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = 3, .col = 3}));
                line[4] = keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = 3, .col = 4}));
                line[5] = keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = 3, .col = 5}));
            }
        } else {
            if (r < 3) {
                const uint8_t row = 4 + r;
                for (uint8_t c = 0; c < 6; c++) {
                    line[c] = keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = row, .col = 5 - c}));
                }
            } else {
                line[0] = keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = 7, .col = 5}));
                line[1] = keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = 7, .col = 4}));
                line[2] = keycode_to_oled_char(get_effective_keycode(layer, (keypos_t){.row = 7, .col = 3}));
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
    }
    else {
        oled_render_bongocat();
    }

    render_layer_bind_lines();
    return false;
}
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
    [1] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
    [2] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
    [3] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
};
#endif
