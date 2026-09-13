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
#if __has_include("keymap.h")                                                                                                                                               
    #include "keymap.h"                                                                                                                                                     
#endif                                                                                                                                                                      

enum custom_keycodes {
    AB_ENE = SAFE_RANGE,
};

bool isMac = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AB_ENE: //Keycode für ñ
            if (record->event.pressed) {
                if (!isMac) {
                    register_code(KC_LALT);
                    tap_code(KC_KP_1);
                    tap_code(KC_KP_6);
                    tap_code(KC_KP_4);
                    unregister_code(KC_LALT);
                } else {
                    register_code(KC_LALT);
                    tap_code(KC_N);
                    unregister_code(KC_LALT);
                    tap_code(KC_N);
                }
            }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
//        L01_R01_C01, L01_R01_C02, L01_R01_C03, L01_R01_C04, L01_R01_C05, L01_R01_C06,   L01_R01_C07, L01_R01_C08, L01_R01_C09, L01_R01_C10, L01_R01_C11, L01_R01_C12,  
//        L01_R02_C01, L01_R02_C02, L01_R02_C03, L01_R02_C04, L01_R02_C05, L01_R02_C06,   L01_R02_C07, L01_R02_C08, L01_R02_C09, L01_R02_C10, L01_R02_C11, L01_R02_C12,
//        L01_R03_C01, L01_R03_C02, L01_R03_C03, L01_R03_C04, L01_R03_C05, L01_R03_C06,   L01_R03_C07, L01_R03_C08, L01_R03_C09, L01_R03_C10, L01_R03_C11, L01_R03_C12,
//                                               L01_R04_C01, L01_R04_C02, L01_R04_C03,   L01_R04_C04, L01_R04_C05, L01_R04_C06


        KC_ESC,          KC_Q,         KC_W,         KC_E,         KC_R,   KC_T,         KC_Z,         KC_U,         KC_I,         KC_O,            KC_P, KC_BSPC, 
        KC_TAB,  LSFT_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F),   KC_G,         KC_H, RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RSFT_T(KC_SCLN), KC_QUOT, 
        KC_MINS, LCTL_T(KC_Y),         KC_X,         KC_C,         KC_V,   KC_B,         KC_N,         KC_M,      KC_COMM,       KC_DOT, RCTL_T(KC_SLSH), KC_LBRC, 
                                                   MO(1),       KC_SPC,  MO(2),         MO(3),      KC_ENT,        MO(1)
    ),
    [1] = LAYOUT_split_3x6_3(
//        L02_R01_C01, L02_R01_C02, L02_R01_C03, L02_R01_C04, L02_R01_C05, L02_R01_C06,   L02_R01_C07, L02_R01_C08, L02_R01_C09, L02_R01_C10, L02_R01_C11, L02_R01_C12,  
//        L02_R02_C01, L02_R02_C02, L02_R02_C03, L02_R02_C04, L02_R02_C05, L02_R02_C06,   L02_R02_C07, L02_R02_C08, L02_R02_C09, L02_R02_C10, L02_R02_C11, L02_R02_C12,
//        L02_R03_C01, L02_R03_C02, L02_R03_C03, L02_R03_C04, L02_R03_C05, L02_R03_C06,   L02_R03_C07, L02_R03_C08, L02_R03_C09, L02_R03_C10, L02_R03_C11, L02_R03_C12,
//                                               L02_R04_C01, L02_R04_C02, L02_R04_C03,   L02_R04_C04, L02_R04_C05, L02_R04_C06
        KC_TRNS,         KC_PAST,         KC_7,         KC_8,         KC_9,   KC_PPLS,       KC_PGUP,   KC_HOME,        KC_UP,       KC_END,          KC_NO,  KC_TRNS, 
        KC_TRNS, LSFT_T(KC_PSLS), LGUI_T(KC_4), LALT_T(KC_5), LCTL_T(KC_6),   KC_PMNS,       KC_PGDN,   KC_LEFT,      KC_DOWN,      KC_RGHT,        KC_LSFT,  KC_CAPS, 
        KC_COMM,  LCTL_T(KC_DOT),         KC_1,         KC_2,         KC_3,      KC_0,        KC_APP,     KC_NO,        KC_NO,        KC_NO,          KC_NO,   KC_DEL, 
                                                     KC_TRNS,      KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_TRNS,      KC_TRNS
    ),
    [2] = LAYOUT_split_3x6_3(
//        L03_R01_C01, L03_R01_C02, L03_R01_C03, L03_R01_C04, L03_R01_C05, L03_R01_C06,   L03_R01_C07, L03_R01_C08, L03_R01_C09, L03_R01_C10, L03_R01_C11, L03_R01_C12,  
//        L03_R02_C01, L03_R02_C02, L03_R02_C03, L03_R02_C04, L03_R02_C05, L03_R02_C06,   L03_R02_C07, L03_R02_C08, L03_R02_C09, L03_R02_C10, L03_R02_C11, L03_R02_C12,
//        L03_R03_C01, L03_R03_C02, L03_R03_C03, L03_R03_C04, L03_R03_C05, L03_R03_C06,   L03_R03_C07, L03_R03_C08, L03_R03_C09, L03_R03_C10, L03_R03_C11, L03_R03_C12,
//                                               L03_R04_C01, L03_R04_C02, L03_R04_C03,   L03_R04_C04, L03_R04_C05, L03_R04_C06

        KC_TRNS,     KC_GRV,       KC_PSLS, RALT(KC_NUBS), RALT(KC_MINS),    KC_PPLS,       RSFT(KC_2),    RSFT(KC_8), RSFT(KC_9),        KC_EQL,        KC_NO,        KC_TRNS, 
        KC_TRNS, LSFT(KC_1),    LSFT(KC_6),       KC_BSLS,    RALT(KC_Q),    KC_PMNS,       RSFT(KC_BSLS), RALT(KC_7), RALT(KC_0),       KC_NUBS, LSFT(KC_NUBS), RALT(KC_RBRC), 
        KC_LSFT, LSFT(KC_MINS), LSFT(KC_4),       KC_PAST,    LSFT(KC_5), RALT(KC_E),       AB_ENE,        RALT(KC_8), RALT(KC_9), LSFT(KC_COMM), LSFT(KC_DOT),         KC_DEL, 
                                                  KC_TRNS,       KC_TRNS,    KC_TRNS,       KC_TRNS,          KC_TRNS,    KC_TRNS
    ),

    //SWITCH LAYER
    [3] = LAYOUT_split_3x6_3(
//        L05_R01_C01, L05_R01_C02, L05_R01_C03, L05_R01_C04, L05_R01_C05, L05_R01_C06,   L05_R01_C07, L05_R01_C08, L05_R01_C09, L05_R01_C10, L05_R01_C11, L05_R01_C12,  
//        L05_R02_C01, L05_R02_C02, L05_R02_C03, L05_R02_C04, L05_R02_C05, L05_R02_C06,   L05_R02_C07, L05_R02_C08, L05_R02_C09, L05_R02_C10, L05_R02_C11, L05_R02_C12,
//        L05_R03_C01, L05_R03_C02, L05_R03_C03, L05_R03_C04, L05_R03_C05, L05_R03_C06,   L05_R03_C07, L05_R03_C08, L05_R03_C09, L05_R03_C10, L05_R03_C11, L05_R03_C12,
//                                               L05_R04_C01, L05_R04_C02, L05_R04_C03,   L05_R04_C04, L05_R04_C05, L05_R04_C06
            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,           KC_F7,      KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12, 
            DF(4), DF(0), KC_NO, KC_NO, KC_NO, KC_NO,           RGB_MOD,  RGB_HUI, RGB_VAI,  KC_NO,  KC_NO,  KC_NO, 
            TO(4), TO(0), KC_NO, KC_NO, KC_NO, KC_NO,           RGB_RMOD, RGB_HUD, RGB_VAD,  KC_NO,  KC_NO,  KC_NO, 
                           KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [4] = LAYOUT_split_3x6_3(
//        L04_R01_C01, L04_R01_C02, L04_R01_C03, L04_R01_C04, L04_R01_C05, L04_R01_C06,   L04_R01_C07, L04_R01_C08, L04_R01_C09, L04_R01_C10, L04_R01_C11, L04_R01_C12,  
//        L04_R02_C01, L04_R02_C02, L04_R02_C03, L04_R02_C04, L04_R02_C05, L04_R02_C06,   L04_R02_C07, L04_R02_C08, L04_R02_C09, L04_R02_C10, L04_R02_C11, L04_R02_C12,
//        L04_R03_C01, L04_R03_C02, L04_R03_C03, L04_R03_C04, L04_R03_C05, L04_R03_C06,   L04_R03_C07, L04_R03_C08, L04_R03_C09, L04_R03_C10, L04_R03_C11, L04_R03_C12,
//                                               L04_R04_C01, L04_R04_C02, L04_R04_C03,   L04_R04_C04, L04_R04_C05, L04_R04_C06
        KC_ESC,          KC_Q,         KC_W,         KC_E,         KC_R,   KC_T,         KC_Z,         KC_U,         KC_I,         KC_O,            KC_P, KC_BSPC, 
        KC_TAB,  LSFT_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F),   KC_G,         KC_H, RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN), KC_QUOT, 
        KC_MINS, LGUI_T(KC_Y),         KC_X,         KC_C,         KC_V,   KC_B,         KC_N,         KC_M,      KC_COMM,       KC_DOT, RGUI_T(KC_SLSH), KC_LBRC, 
                                                   MO(5),       KC_SPC,  MO(6),         MO(7),      KC_ENT,        MO(5)
    ),
    [5] = LAYOUT_split_3x6_3(
//        L04_R01_C01, L04_R01_C02, L04_R01_C03, L04_R01_C04, L04_R01_C05, L04_R01_C06,   L04_R01_C07, L04_R01_C08, L04_R01_C09, L04_R01_C10, L04_R01_C11, L04_R01_C12,  
//        L04_R02_C01, L04_R02_C02, L04_R02_C03, L04_R02_C04, L04_R02_C05, L04_R02_C06,   L04_R02_C07, L04_R02_C08, L04_R02_C09, L04_R02_C10, L04_R02_C11, L04_R02_C12,
//        L04_R03_C01, L04_R03_C02, L04_R03_C03, L04_R03_C04, L04_R03_C05, L04_R03_C06,   L04_R03_C07, L04_R03_C08, L04_R03_C09, L04_R03_C10, L04_R03_C11, L04_R03_C12,
//                                               L04_R04_C01, L04_R04_C02, L04_R04_C03,   L04_R04_C04, L04_R04_C05, L04_R04_C06
        KC_TRNS,         KC_PAST,         KC_7,         KC_8,         KC_9,   KC_PPLS,       KC_PGUP,   KC_HOME,        KC_UP,       KC_END,          KC_NO,  KC_TRNS, 
        KC_TRNS, LSFT_T(KC_PSLS), LCTL_T(KC_4), LALT_T(KC_5), LGUI_T(KC_6),   KC_PMNS,       KC_PGDN,   KC_LEFT,      KC_DOWN,      KC_RGHT,        KC_LSFT,  KC_CAPS, 
        KC_COMM,  LGUI_T(KC_DOT),         KC_1,         KC_2,         KC_3,      KC_0,        KC_APP,     KC_NO,        KC_NO,        KC_NO,          KC_NO,   KC_DEL, 
                                                     KC_TRNS,      KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_TRNS,      KC_TRNS
    ),
    [6] = LAYOUT_split_3x6_3(
//        L03_R01_C01, L03_R01_C02, L03_R01_C03, L03_R01_C04, L03_R01_C05, L03_R01_C06,   L03_R01_C07, L03_R01_C08, L03_R01_C09, L03_R01_C10, L03_R01_C11, L03_R01_C12,  
//        L03_R02_C01, L03_R02_C02, L03_R02_C03, L03_R02_C04, L03_R02_C05, L03_R02_C06,   L03_R02_C07, L03_R02_C08, L03_R02_C09, L03_R02_C10, L03_R02_C11, L03_R02_C12,
//        L03_R03_C01, L03_R03_C02, L03_R03_C03, L03_R03_C04, L03_R03_C05, L03_R03_C06,   L03_R03_C07, L03_R03_C08, L03_R03_C09, L03_R03_C10, L03_R03_C11, L03_R03_C12,
//                                               L03_R04_C01, L03_R04_C02, L03_R04_C03,   L03_R04_C04, L03_R04_C05, L03_R04_C06

        KC_TRNS,     KC_GRV,       KC_PSLS, RALT(KC_NUBS), RALT(KC_MINS),    KC_PPLS,       RSFT(KC_2),    RSFT(KC_8), RSFT(KC_9),        KC_EQL,        KC_NO,        KC_TRNS, 
        KC_TRNS, LSFT(KC_1),    LSFT(KC_6),       KC_BSLS,    RALT(KC_Q),    KC_PMNS,       RSFT(KC_BSLS), RALT(KC_7), RALT(KC_0),       KC_NUBS, LSFT(KC_NUBS), RALT(KC_RBRC), 
        KC_LSFT, LSFT(KC_MINS), LSFT(KC_4),       KC_PAST,    LSFT(KC_5), RALT(KC_E),       AB_ENE,        RALT(KC_8), RALT(KC_9), LSFT(KC_COMM), LSFT(KC_DOT),         KC_DEL, 
                                                  KC_TRNS,       KC_TRNS,    KC_TRNS,       KC_TRNS,          KC_TRNS,    KC_TRNS
    ),
        //SWITCH LAYER
    [7] = LAYOUT_split_3x6_3(
//        L05_R01_C01, L05_R01_C02, L05_R01_C03, L05_R01_C04, L05_R01_C05, L05_R01_C06,   L05_R01_C07, L05_R01_C08, L05_R01_C09, L05_R01_C10, L05_R01_C11, L05_R01_C12,  
//        L05_R02_C01, L05_R02_C02, L05_R02_C03, L05_R02_C04, L05_R02_C05, L05_R02_C06,   L05_R02_C07, L05_R02_C08, L05_R02_C09, L05_R02_C10, L05_R02_C11, L05_R02_C12,
//        L05_R03_C01, L05_R03_C02, L05_R03_C03, L05_R03_C04, L05_R03_C05, L05_R03_C06,   L05_R03_C07, L05_R03_C08, L05_R03_C09, L05_R03_C10, L05_R03_C11, L05_R03_C12,
//                                               L05_R04_C01, L05_R04_C02, L05_R04_C03,   L05_R04_C04, L05_R04_C05, L05_R04_C06
            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,           KC_F7,      KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12, 
            DF(4), DF(0), KC_NO, KC_NO, KC_NO, KC_NO,           RGB_MOD,  RGB_HUI, RGB_VAI,  KC_NO,  KC_NO,  KC_NO, 
            TO(4), TO(0), KC_NO, KC_NO, KC_NO, KC_NO,           RGB_RMOD, RGB_HUD, RGB_VAD,  KC_NO,  KC_NO,  KC_NO, 
                           KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    
    isMac = detected_os == OS_MACOS;

    if (isMac) {
        layer_move(4);
    }

    return true;
}

                                                                                                                                                                   
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        rgb_matrix_set_color(get_highest_layer(layer_state), RGB_GREEN);
    }

    return false;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGUI_T(KC_L):
        case LGUI_T(KC_S):
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}