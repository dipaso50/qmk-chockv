/* Copyright 2021 BrickBots Labs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "keymap_spanish.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _TILDE,
    _NUMBER,
    _MULTI 
};

enum {    
    TD_ESCQ, 
};


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESCQ] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC), 
};

#define KC_CAPW LGUI(LSFT(KC_3)) // Capture whole screen 
#define KC_CPYW LGUI(LSFT(LCTL(KC_3))) // Copy whole screen 
#define KC_CAPP LGUI(LSFT(KC_4)) // Capture portion of screen   
#define KC_CPYP LGUI(LSFT(LCTL(KC_4))) // Copy portion of screen

#define TDQESC TD(TD_ESCQ)

#define KC_RENAME LSFT(KC_F6)
#define KC_IMPORTS LALT(LCTL(KC_O))
#define KC_GENERATE LGUI(KC_N)
#define KC_COMPILE LGUI(KC_F9)
#define KC_SEARCH LSG(KC_R)
#define KC_OPEN LGUI(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_QWERTY] = LAYOUT_split_3x5_3(
     TDQESC,        KC_W,          KC_E,         KC_R,         LT(_MULTI,KC_T),   KC_Y,              KC_U,          KC_I,         KC_O,           KC_P,
     LCTL_T(KC_A),  LGUI_T(KC_S),  LALT_T(KC_D), LSFT_T(KC_F), LT(_TILDE,KC_G),   LT(_NUMBER,KC_H),  RSFT_T(KC_J),  RALT_T(KC_K), RGUI_T(KC_L),   LCTL_T(KC_BSPC),
     KC_Z,          KC_X,          KC_C,         KC_V,         KC_B,              KC_N,              KC_M,          KC_COMM,      KC_DOT,         KC_SLSH,
                    MT(MOD_RGUI, KC_TAB) , LT(_RAISE, KC_SPC), KC_RGUI,  KC_TRNS,   LT(_LOWER, KC_ENT), OSM(MOD_RGUI)
    ),
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    [_LOWER] = LAYOUT_split_3x5_3(
     ES_HASH,       ES_LPRN,       ES_RPRN,      ES_LABK,      ES_RABK,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,  
     ES_AMPR,       ES_LCBR,       ES_RCBR,      ES_SLSH,      ES_BSLS,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10, 
     ES_AT,         ES_LBRC,       ES_RBRC,      ES_ASTR,      ES_EQL,       KC_F11,     KC_F12,     KC_CAPP,    KC_CPYP,    KC_TRNS,
                                          ES_PIPE, ES_PERC, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    [_RAISE] = LAYOUT_split_3x5_3(
     KC_TRNS,    KC_GENERATE,      KC_IMPORTS,   KC_RENAME,    KC_DEL,       KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_TRNS,
     KC_TRNS,    KC_TRNS,          KC_TRNS,      KC_TRNS,      KC_CAPS,      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_INS,   
     KC_TRNS,    KC_SEARCH,        KC_OPEN,      KC_COMPILE,   KC_TRNS,      KC_TRNS,    KC_RSFT,    ES_SCLN,    ES_COLN,    LCTL_T(ES_UNDS), 
                                         KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
        //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    [_TILDE] = LAYOUT_split_3x5_3(
     KC_TRNS,    KC_TRNS,          KC_TRNS,      KC_TRNS,     KC_TRNS,       ES_CIRC,    ES_TILD,    ES_DLR,     ES_IQUE,    ES_QUES,
     KC_TRNS,    KC_TRNS,          KC_TRNS,      KC_TRNS,     KC_TRNS,       ES_GRV,     ES_ACUT ,   ES_QUOT,    ES_DQUO,    KC_INS,   
     KC_TRNS,    KC_TRNS,          KC_TRNS,      KC_TRNS,     KC_TRNS,       KC_SCLN,    ES_IEXL,    ES_EXLM,    KC_INS,     KC_INS, 
                                         KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
        //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    [_MULTI] = LAYOUT_split_3x5_3(
     KC_TRNS,    KC_TRNS,          KC_TRNS,      KC_TRNS,     KC_TRNS,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS,    KC_TRNS,          KC_TRNS,      KC_TRNS,     KC_TRNS,       KC_TRNS,    KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP ,   KC_TRNS,    KC_TRNS,   
     KC_TRNS,    KC_TRNS,          KC_TRNS,      KC_TRNS,     KC_TRNS,       KC_TRNS,    KC_KB_MUTE,    KC_TRNS,    KC_TRNS,    KC_TRNS, 
                                         KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
    )
};








