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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for development
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     , KC_ESC   ,                                         KC_QUOT  , KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , 
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     , KC_TAB  ,                                          KC_MINS , KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , 
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_LCTL ,                                          KC_GRV , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , 
                    SCRL_MO  , KC_LALT  ,  KC_LCTL,   LT(2, KC_SPC), KC_LSFT,                     LT(3,KC_BSPC), LT(1,KC_ENT)  ,   _______  , _______  , LT(4,KC_CAPS)
  ),

  [1] = LAYOUT_universal(
    KC_BSLS,    KC_1       , KC_2    , KC_3     , KC_4  , KC_5 ,                                               KC_F1    , KC_F2    , KC_F3   , KC_F4    , KC_F5    , KC_F6    ,
    S(KC_BSLS), KC_6    ,    KC_7    , KC_8     , KC_9  , KC_0  ,                                              KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   , KC_F12   ,
    S(KC_2),    S(KC_EQL)  , KC_MINS    , KC_SLSH  , S(KC_8), KC_EQL  ,                                        S(KC_9)  , S(KC_0)   , KC_LBRC,  KC_RBRC,  S(KC_LBRC)   , S(KC_RBRC) ,
                  KC_LBRC  , KC_RBRC  , KC_LCTL  ,   _______  , KC_LSFT  ,                   KC_BSPC   , _______  , _______       , _______  , _______
  ),
 
  [2] = LAYOUT_universal(
    _______    , _______    , KC_BTN1   , KC_BTN3    , KC_BTN2    , KC_VOLU    ,                            _______  , KC_PGUP ,  KC_HOME  , KC_UP    , KC_END  , _______  , 
    SSNP_VRT ,  _______    , _______   , _______    , _______    , KC_VOLD    ,                             _______  , KC_PGDN ,   KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , 
    SSNP_HOR ,  _______    , _______   , _______    , _______    , KC_LGUI    ,                             _______  , _______    , _______    , _______   , _______   , _______   ,
                  SSNP_FRE , KC_LALT , KC_LCTL  ,   _______  , KC_LSFT  ,                           KC_BSPC  , KC_DEL  , _______    , _______  , _______
  ),

  [3] = LAYOUT_universal(
    S(KC_LBRC)   , S(KC_RBRC)    , KC_LBRC,  KC_RBRC,  S(KC_9)  , S(KC_0)    ,                           _______  , _______    , _______    , _______   , _______   , _______   ,
    KC_GRV ,  S(KC_2)    , _______   , S(KC_MINS)   , KC_QUOT    , S(KC_QUOT)    ,                            _______  , _______ ,  _______  , _______    , _______  , _______  , 
    S(KC_GRV) ,  S(KC_EQL)  , KC_MINS    , KC_SLSH  , S(KC_8), KC_EQL  ,                            _______  , _______ ,   _______  , _______  , _______  , _______  ,
                  _______ , KC_LALT , KC_LCTL  ,   KC_SPC  , KC_LSFT  ,                           _______  , _______  , _______    , _______  , _______
  ),

  [4] = LAYOUT_universal(
    RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                                        RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,                                        RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , SCRL_DVD ,                                       CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
                    QK_BOOT  , KBC_RST  , KBC_SAVE  ,      _______  , _______     ,               _______  , _______  ,      _______  , KBC_RST  , QK_BOOT
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
