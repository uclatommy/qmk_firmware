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
    _FN1,
    _FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
      KC_ESC,           KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_PGDN, KC_END,  KC_7,    KC_8,     KC_9,   KC_EQL,
      LCTL_T(KC_CAPS),  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSPC, KC_PGUP, KC_HOME, KC_4,    KC_5,     KC_6,   KC_MINS,
      KC_LSFT,          KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, KC_ENT,                    KC_1,    KC_2,     KC_3,
      KC_LALT,          MO(_FN2),                   KC_SPC,                             KC_LALT, KC_MENU, MO(_FN1),                  KC_SLCK,          KC_0,    KC_DOT,           KC_ENT
    ),
    [_FN1] = LAYOUT(
      KC_GRAVE,         _______,  KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,    KC_F9,  KC_F11,
      _______,          KC_LEFT,  KC_DOWN, KC_RIGHT,_______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, KC_BRK,  _______, _______, KC_F4,   KC_F5,    KC_F6,  KC_F12,
      _______,          _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_F1,   KC_F2,    KC_F3,
      _______,          _______,                    _______,                            _______, _______, _______,                   KC_MUTE,          KC_F10,  _______,          _______
    ),
    [_FN2] = LAYOUT(
      KC_GRAVE,         _______,  KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, KC_9,    KC_0,    _______, _______, _______, _______, _______, _______,
      _______,          KC_LEFT,  KC_DOWN, KC_RIGHT,_______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, KC_BSLS, _______, _______, _______, KC_UP,   _______, _______,
      _______,          _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_RIGHT,
      _______,          _______,                    _______,                            _______, _______, _______,                   _______,          _______,  _______,         _______
    ),
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {

    case KC_ESC:
        // Detect the activation of only Left Alt
        if ((mod_state & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
            if (record->event.pressed) {
                // No need to register KC_LALT because it's already active.
                // The Alt modifier will apply on this KC_TAB.
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            // Do not let QMK process the keycode further
            return false;
        }
        // Else, let QMK process the KC_ESC keycode as usual
        return true;

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
      }

    }
    return true;
};

uint8_t selected_layer = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
  switch(get_highest_layer(layer_state)){
		case _FN2:
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
		case _FN1:
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
