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
#include <bongo.h>

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
      KC_ESC,           KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_HOME, KC_PGUP, KC_7,    KC_8,     KC_9,    KC_EQL,
      LCTL_T(KC_CAPS),  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSPC, KC_END,  KC_PGDN, KC_4,    KC_5,     KC_6,    KC_MINS,
      KC_LSFT,          KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, KC_ENT,                    KC_1,    KC_2,     KC_3,
      KC_LALT,          TT(_FN2),                   KC_SPC,                             KC_RGUI, KC_RCTL, TT(_FN1),                  KC_SLCK,          KC_0,              KC_DOT,  KC_ENT
    ),
    [_FN1] = LAYOUT(
      KC_GRAVE,         _______,  KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,    KC_F9,   KC_F11,
      _______,          KC_LEFT,  KC_DOWN, KC_RIGHT,_______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______, KC_BRK,  KC_F4,   KC_F5,    KC_F6,   KC_F12,
      _______,          _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_F1,   KC_F2,    KC_F3,
      _______,          _______,                    KC_TAB,                             _______, _______, _______,                   KC_MUTE,          KC_F10,            _______, _______
    ),
    [_FN2] = LAYOUT(
      KC_TAB,           _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_9,    KC_0,    _______,  _______, _______, _______, _______, _______,
      _______,          _______,  _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, KC_BSLS, _______,  _______, _______, KC_UP,   _______, _______,
      _______,          _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    KC_LEFT, KC_DOWN, KC_RIGHT,
      _______,          _______,                    KC_TAB,                             _______, _______, _______,                   KC_NLCK,           KC_TAB,           _______, _______
    ),
};
uint16_t oled_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed){
        oled_timer = timer_read();
    }
    switch (keycode) {

    case KC_1:
        {
        // Initialize a boolean variable that keeps track
        // of the key status: registered or not?
        static bool kc1_registered;
        if (record->event.pressed) {
            // Detect the activation of scroll lock
            if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
                register_code(KC_LEFT);
                // Update the boolean variable to reflect the status of KC_1
                kc1_registered = true;
                return false;
            }
        } else { // on release of KC_1
            // In case KC_LEFT is still being sent even after the release of KC_1
            if (kc1_registered) {
                unregister_code(KC_LEFT);
                kc1_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_1 keycode as usual outside of scroll lock
        return true;
      }

      case KC_3:
          {
          // Initialize a boolean variable that keeps track
          // of the key status: registered or not?
          static bool kc3_registered;
          if (record->event.pressed) {
              // Detect the activation of scroll lock
              if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
                  register_code(KC_RIGHT);
                  // Update the boolean variable to reflect the status of KC_3
                  kc3_registered = true;
                  return false;
              }
          } else { // on release of KC_3
              // In case KC_RIGHT is still being sent even after the release of KC_3
              if (kc3_registered) {
                  unregister_code(KC_RIGHT);
                  kc3_registered = false;
                  return false;
              }
          }
          // Let QMK process the KC_3 keycode as usual outside of scroll lock
          return true;
        }

        case KC_5:
            {
            static bool kc5_registered;
            if (record->event.pressed) {
                // Detect the activation of scroll lock
                if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
                    register_code(KC_UP);
                    kc5_registered = true;
                    return false;
                }
            } else {
                if (kc5_registered) {
                    unregister_code(KC_UP);
                    kc5_registered = false;
                    return false;
                }
            }
            return true;
          }

          case KC_2:
              {
              static bool kc2_registered;
              if (record->event.pressed) {
                  // Detect the activation of scroll lock
                  if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
                      register_code(KC_DOWN);
                      kc2_registered = true;
                      return false;
                  }
              } else {
                  if (kc2_registered) {
                      unregister_code(KC_DOWN);
                      kc2_registered = false;
                      return false;
                  }
              }
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
					tap_code(KC_RIGHT);
				} else {
					tap_code(KC_LEFT);
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
					tap_code(KC_DOWN);
				} else {
					tap_code(KC_UP);
				}
			}
			break;
	}
	return true;
}

#ifdef OLED_ENABLE
bool oled_task_user(void)
{
    if (timer_elapsed(oled_timer) > OLED_TIMEOUT)
    {
      oled_off();
      return false;
    }
  /*
    static bool finished_timer = false;
    if (!finished_timer && (timer_elapsed(startup_timer) < 3000)) {
        render_logo();
    } else {
        if (!finished_timer) {
            oled_clear();
            finished_timer = true;
        }*/
        oled_set_cursor(3, 0);
        render_cat();
        oled_set_cursor(0, 0);
        char string[10];
        uint16_t m = get_current_wpm();
        string[3] = '\0';
        string[2] = '0' + m % 10;
        string[1] = ( m /= 10) % 10 ? '0' + (m) % 10 : (m / 10) % 10 ? '0' : ' ';
        string[0] =  m / 10 ? '0' + m / 10 : ' ';
        oled_write_P(PSTR("WPM:"), false);
        oled_write(string, false);

        oled_set_cursor(0, 1);
        // Host Keyboard LED Status
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR(""), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR(""), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCR") : PSTR(""), false);

        oled_set_cursor(0, 2);
        // Host Keyboard Layer Status
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                if (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)){
                  oled_write_P(PSTR("Scr U/D"), false);
                } else {
                  oled_write_P(PSTR("Dir U/D"), false);
                }
                break;
            case _FN1:
                oled_write_P(PSTR("Vol U/D"), false);
                break;
            case _FN2:
                if (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)){
                  oled_write_P(PSTR("Scr L/R"), false);
                } else {
                  oled_write_P(PSTR("Dir L/R"), false);
                }
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undef"), false);
        }

        oled_set_cursor(0, 3);
        // Host Keyboard Layer Status
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_P(PSTR("Base"), false);
                break;
            case _FN1:
                oled_write_P(PSTR("FN 1"), false);
                break;
            case _FN2:
                oled_write_P(PSTR("FN 2"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undef"), false);
        }
    //}
    return false;
}
#endif

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
