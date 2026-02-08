/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

// Key override: Swap quote behavior
// Normal press = " (shift+quote), Shift+press = ' (quote)
const key_override_t quote_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_QUOT);
const key_override_t dquote_override = ko_make_with_layers_and_negmods(0, KC_QUOT, S(KC_QUOT), ~0, MOD_MASK_SHIFT);

const key_override_t *key_overrides[] = {
    &quote_override,
    &dquote_override,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Layer 0: Default QWERTY
  [0] = LAYOUT_right_ball(
    KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_DEL   ,
    _______   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_EQL  ,
               KC_LALT  , KC_LCTL  , KC_LGUI  , LT(1,KC_SPC), LT(3,KC_TAB),          KC_BSPC , LT(2,KC_ENT),                                          KC_RSFT
  ),

  // Layer 1: Navigation and Function keys
  [1] = LAYOUT_right_ball(
    KC_GRV   , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                            KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , _______  , _______  , KC_UP    , KC_ENT   , KC_DEL   ,                            KC_PGUP  , MS_BTN1  , KC_UP    , MS_BTN2  , MS_BTN3  , KC_F12   ,
    _______  , _______  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_BSPC  ,                            KC_PGDN  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,
               _______  , _______  , _______  , _______  , _______  ,                 _______  , _______  ,                                            _______
  ),

  // Layer 2: Numbers and Symbols
  [2] = LAYOUT_right_ball(
    KC_GRV   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                            KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_NUBS  , KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC  ,                            KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_LPRN  , KC_RPRN  , KC_UNDS  ,
    S(KC_NUBS), KC_EQL  , KC_PLUS  , KC_LBRC  , KC_RBRC  , KC_BSLS  ,                            KC_LCBR  , KC_RCBR  , KC_PIPE  , _______  , _______  , _______  ,
               _______  , _______  , _______  , _______  , _______  ,                 KC_DEL   , _______  ,                                            _______
  ),

  // Layer 3: Trackball settings, System, and Media
  [3] = LAYOUT_right_ball(
    _______  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                            KC_MPRV  , KC_MPLY  , KC_MNXT  , KC_MUTE  , KC_VOLD  , KC_VOLU  ,
    _______  , _______  , _______  , _______  , _______  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
               QK_BOOT  , KBC_RST  , _______  , _______  , _______  ,                 _______  , _______  ,                                            QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
