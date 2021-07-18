/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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
#include "rgb_matrix_map.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    /*
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
*/
	[0] = LAYOUT(
      KC_ESC,          KC_F1,      KC_F2,      KC_F3,      KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        KC_F11,  KC_F12,         KC_PAUS,          KC_SLCK,
      KC_GRV,          LT(0,KC_1), LT(1,KC_2), LT(2,KC_3), KC_4, KC_5, KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,       KC_EQL,  KC_BSPC,                          KC_HOME,
      KC_TAB,          KC_Q,       KC_W,       KC_E,       KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          KC_LBRC, KC_RBRC,        KC_BSLS,          KC_PGUP,
      LCTL_T(KC_CAPS), KC_A,       KC_S,       KC_D,       KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,       KC_QUOT,                 KC_ENT,           KC_PGDN,
      KC_LSFT,                     KC_Z,       KC_X,       KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,        KC_SLSH,                 KC_RSFT, KC_UP,   KC_END,
      KC_LALT,         KC_LGUI,    MO(2),                                  KC_SPC,                               KC_RALT, MO(1),KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
  [1] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_MUTE,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           _______,
      _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
      _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
      _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
      _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
  ),
	[2] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_SLCK,
      _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, KC_DEL,           RGB_HUI,
      _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______, _______, RESET,            RGB_MOD,
      _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,          _______,          RGB_RMOD,
      _______,          _______, _______, _______, _______, _______, _______, KC_P0,   _______, KC_PDOT, _______,          _______, _______, RGB_TOG,
      _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
  ),
};

uint8_t selected_layer = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
  switch(get_highest_layer(layer_state)){
		case 2:
			if (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)){
				if (clockwise) {
					tap_code(KC_WH_R);
				} else {
					tap_code(KC_WH_L);
				}
			}else{
				if (clockwise) {
					tap_code(KC_DOWN);
				} else {
					tap_code(KC_UP);
				}
			}
			break;
		case 1:
			if (clockwise) {
				tap_code(KC_VOLU);
			} else {
				tap_code(KC_VOLD);
			}
			break;
		default:
			if (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)){
				if (clockwise) {
					tap_code(KC_WH_D);
				} else {
					tap_code(KC_WH_U);
				}
			}else{
				if (clockwise) {
					tap_code(KC_RIGHT);
				} else {
					tap_code(KC_LEFT);
				}
			}
			break;
	}
	return true;
}

#ifdef RGB_MATRIX_ENABLE
    // Capslock, Scroll lock indicator on Left side lights.
    void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        if (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) {
            rgb_matrix_set_color(LED_L1, RGB_GREEN);
            rgb_matrix_set_color(LED_L8, RGB_GREEN);
        }
        if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
            rgb_matrix_set_color(LED_L5, RGB_WHITE);
            rgb_matrix_set_color(LED_L6, RGB_WHITE);
            rgb_matrix_set_color(LED_L4, RGB_WHITE);
						rgb_matrix_set_color(LED_CAPS, RGB_WHITE);
        }
				if(!IS_HOST_LED_ON(USB_LED_NUM_LOCK)){
					// Turn on numlock
					register_code(KC_NUMLOCK);
      		unregister_code(KC_NUMLOCK);
				}
        switch(get_highest_layer(layer_state)){  // special handling per layer
        case 2:  // on Fn layer select what the encoder does when pressed
						for (uint8_t i=0; i<sizeof(LED_LIST_NUMPAD)/sizeof(LED_LIST_NUMPAD[0]); i++) {
								rgb_matrix_set_color(LED_LIST_NUMPAD[i], RGB_MAGENTA);
						}
						rgb_matrix_set_color(LED_R2, RGB_WHITE);
            rgb_matrix_set_color(LED_R3, RGB_WHITE);
            rgb_matrix_set_color(LED_R4, RGB_WHITE);
            rgb_matrix_set_color(LED_LALT, RGB_WHITE); //FN key
            break;
        case 1:
						for (uint8_t i=0; i<sizeof(LED_LIST_WASD)/sizeof(LED_LIST_WASD[0]); i++) {
								rgb_matrix_set_color(LED_LIST_WASD[i], RGB_MAGENTA);
						}
            rgb_matrix_set_color(LED_R4, RGB_WHITE);
            rgb_matrix_set_color(LED_R5, RGB_WHITE);
            rgb_matrix_set_color(LED_R6, RGB_WHITE);
						rgb_matrix_set_color(LED_FN, RGB_WHITE);
            break;
        default:
            break;
        }
    }

    void suspend_power_down_user(void) {
        rgb_matrix_set_suspend_state(true);
    }

    void suspend_wakeup_init_user(void) {
        rgb_matrix_set_suspend_state(false);
    }
#endif

void keyboard_post_init_user(void){
	#ifdef RGB_MATRIX_ENABLE
		rgblight_sethsv(HSV_ROSEGOLD);
	#endif
}
