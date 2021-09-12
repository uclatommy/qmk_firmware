/* Copyright 2020 uclatommy
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_65_ansi(
      KC_ESC,           KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_PGUP, KC_PGDN, KC_7,    KC_8,    KC_9,    KC_EQL,
      LCTL_T(KC_CAPS),  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSPC, KC_HOME, KC_END,  KC_4,    KC_5,    KC_6,    KC_MINS,
      KC_LSFT,          KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, KC_ENT,                    KC_1,    KC_2,    KC_3,
      KC_LALT,          MO(1),                      KC_SPC,                             KC_LALT, KC_MENU, MO(1),                     KC_SLCK,          KC_0,             KC_DOT,  KC_ENT
    ),
    [_FN] = LAYOUT_65_ansi(
      KC_ESC,           KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_PGUP, KC_PGDN, KC_7,    KC_8,    KC_9,    KC_EQL,
      LCTL_T(KC_CAPS),  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSPC, KC_HOME, KC_END,  KC_4,    KC_5,    KC_6,    KC_MINS,
      KC_LSFT,          KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, KC_ENT,                    KC_1,    KC_2,    KC_3,
      KC_LALT,          MO(1),                      KC_SPC,                             KC_LALT, KC_MENU, MO(1),                     KC_SLCK,          KC_0,             KC_DOT,  KC_ENT
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

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
