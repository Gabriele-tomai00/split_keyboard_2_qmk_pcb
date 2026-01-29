#include QMK_KEYBOARD_H
#include "quantum.h"
#include "oled_images.h"
#include "oled_driver.h" // assicurati che sia incluso il driver corretto

enum custom_keycodes {
    KC_LSTRT = QK_KB_0, // we use QK_KB_0 instead of SAFE_RANGE, to see the right name in VIAL interface (KC_LSTRT is start of line)
    KC_LEND, // go to: end of line
    KC_DLINE, // del word
    BRIGHTNESS_CICLE,
    RGB_COL_TOGGLE,
    KC_E_GRAVE, // write é
    MOVE_RIGHT_MACOS,
    MOVE_LEFT_MACOS,
    KC_MARKDOWN_CODE_BLOCK
};

/*                                                MY TARGET

    GPIO:  0     1    2   3     4    5    6                       7   8     9   10   11  12 (13)  14
         ┌────┬────┬────┬────┬────┬────┬────┐                  ┌────┬────┬────┬────┬────┬────┬─────────┐
    15   │Esc │ 1  │  2 │  3 │  4 │  5 │  6 │                  │ 7  │  8 │  9 │  0 │  - │  + │  Backsp │
         ├────┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┐               └──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬──────┤
    16   │ Tab   │ Q  │  W │  E │  R │  T │  Y │                  │ U  │  I │ O  │ P  │ [  │  ] │  \|  │
         ├───────┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┘              ┌───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴──────│
    17   │ Caps   │ A  │ S  │ D  │ F  │ G  │                  │ H  │ J  │  K │  L │ ;  │ '  │  Enter   │
         ├──────┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬────┐          └──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──────────┤
    18   │Shf   │ <  │  Z │  X │  C │  V │  B │ F1 │             │  N │  M │ ,  │  . │  ? │    Shf     │
         ├─────┬┴────┼────┴┬───┴─┬──┴────┴──┬─┴──┬─┴──┐        ┌─┴────┴┬───┴─┬──┴────┼────┴┬─────┬─────┤
    19   │ FN  │ Ctrl│ Win │ Alt │  Space   │ ent│bspc│        │ Space │ FN  │  Alt  │ Gui │  <  │  >  │
         └─────┴─────┴─────┴───┬─┴─────┬────┼────┴────┘        ├─────┬─┴─────┴┬──────┴─────┴─────┴─────┘
    20                         │   F4  │ F5 │                  │  F6 │   F7   │
                               └───────┴────┘                  └─────┴────────┘
*/ 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                                               KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                                 KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,          KC_MUTE,
      KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,                                                 KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DEL,                                         KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
      MO(1), KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_ENT, KC_BSPC,                            KC_SPC, KC_RCTL, KC_RGUI, _______, KC_RCTL, KC_RIGHT,
                                MO(2), MO(1),                                              MO(1), MO(2)
    ),

    [1] = LAYOUT(
      KC_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                          KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, 
      _______, _______, _______, KC_E_GRAVE, _______, _______,                                    KC_VOLD, KC_VOLU, KC_UP, _______, _______, _______, _______, _______,         _______,
      _______, _______, _______, KC_BSPC, _______, _______,                                           _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, 
      _______, _______, _______, _______, _______, _______, _______,                                     MOVE_LEFT_MACOS, MOVE_RIGHT_MACOS, _______, _______, _______, _______, 
      KC_MARKDOWN_CODE_BLOCK, RGB_TOG, _______, _______, _______, _______, _______,                    RGB_TOG, BRIGHTNESS_CICLE, RGB_COL_TOGGLE, _______, MOVE_LEFT_MACOS, MOVE_RIGHT_MACOS,
                                _______, _______,                                                    _______, _______
    ),

    [2] = LAYOUT(
QK_MAGIC_SWAP_LCTL_LGUI, QK_MAGIC_UNSWAP_LCTL_LGUI, KC_F2, KC_F3, KC_F4, KC_F5, QK_BOOTLOADER,                            QK_BOOTLOADER, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DLINE, 
      _______, _______, KC_UP, _______, _______, _______,                                    _______, _______, KC_MS_U, _______, _______, _______, _______, _______,         _______,
      _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,                                    KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, _______, _______, 
      _______, _______, _______, _______, _______, _______, _______,                                KC_WH_U, _______, _______, _______, _______, _______, 
      _______, _______, _______, _______, _______, _______, _______,                        KC_WH_U, _______, _______, _______, _______, _______,
                                       _______, _______,                                    _______, _______
    ),
};

/* ENCODER */
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),   },
    [1] =   { ENCODER_CCW_CW(KC_BRID, KC_BRIU),   },
    [2] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),   },
};
#endif



void matrix_scan_user(void) {
    static uint32_t last_toggle = 0;
    static bool led_on = false;

    if (timer_elapsed32(last_toggle) > 500) {
        last_toggle = timer_read32();
        setPinOutput(GP25);
        if (led_on) {
            writePinLow(GP25);
        } else {
            writePinHigh(GP25);
        }
        led_on = !led_on;   
    }    
}


static uint8_t brightness_level = 0;  // 0 = low, 1 = medium, 2 = hight
// --- OS image switch overlay ---
static uint32_t os_img_timer = 0;
static uint8_t os_img_to_show = 0;
static uint8_t color_index = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;  // ignoriamo il rilascio per semplicità

    switch (keycode) {
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD + ← su macOS (tasti scambiati)
                    register_mods(MOD_BIT(KC_LCTL));
                    register_code(KC_LEFT);
                } else {
                    // HOME su Windows/Linux
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_code(KC_LEFT);
                    unregister_mods(MOD_BIT(KC_LCTL));
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;

    case KC_LEND:
        if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
                // CMD + → su macOS
                register_mods(MOD_BIT(KC_LCTL));
                register_code(KC_RIGHT);
            } else {
                // END su Windows/Linux
                register_code(KC_END);
            }
        } else {
            if (keymap_config.swap_lctl_lgui) {
                unregister_code(KC_RIGHT);
                unregister_mods(MOD_BIT(KC_LCTL));
            } else {
                unregister_code(KC_END);
            }
        }
        break;
        case KC_DLINE:
            if (record->event.pressed) {
                tap_code16(C(KC_BSPC));  // euqal to Ctrl/Command + Backspace
            }
            return false;
            break;
        case BRIGHTNESS_CICLE:
            if (record->event.pressed) {
                brightness_level = (brightness_level + 1) % 3; // 3 is the number of brightness levels
                uint8_t brightness_values[3] = {50, 150, RGB_MATRIX_MAXIMUM_BRIGHTNESS};
                // set LED brightness without modifying EEPROM (so Vial retains its color)
                rgb_matrix_sethsv_noeeprom(rgb_matrix_get_hue(), rgb_matrix_get_sat(), brightness_values[brightness_level]);
            }
            return false;
            break;
        case RGB_COL_TOGGLE:
            if (record->event.pressed) {
                color_index = (color_index + 1) % 3;          // blue(0), green(1), yellow(2)
                uint8_t current_val = rgb_matrix_get_val();   // It uses the same brightness
                uint8_t hues[3] = {170, 85, 43};
                rgb_matrix_sethsv_noeeprom(hues[color_index], 255, current_val);
            }
            return false;
            break;
        case KC_E_GRAVE:
            if (record->event.pressed) {
                register_code(KC_LEFT_ALT);
                tap_code(KC_E);
                unregister_code(KC_LEFT_ALT);
                tap_code(KC_E);
            }
            return false;
            break;
        case MOVE_RIGHT_MACOS: 
            if (record->event.pressed) {
                register_code(KC_LEFT_CTRL);
                tap_code(KC_RIGHT);
                unregister_code(KC_LEFT_CTRL);
            }
            return false;
            break;
        case MOVE_LEFT_MACOS:
            if (record->event.pressed) {
                register_code(KC_LEFT_CTRL);
                tap_code(KC_LEFT);
                unregister_code(KC_LEFT_CTRL);
            }
            return false;
            break;
        case KC_MARKDOWN_CODE_BLOCK:
        if (record->event.pressed) {
            // Apre il blocco di codice
            tap_code16(KC_GRAVE);
            tap_code16(KC_GRAVE);
            tap_code16(KC_GRAVE);

            // Vai a capo con Enter normale
            tap_code(KC_ENTER);

            // Riga vuota (opzionale)
            tap_code(KC_ENTER);

            // Chiude il blocco di codice
            tap_code16(KC_GRAVE);
            tap_code16(KC_GRAVE);
            tap_code16(KC_GRAVE);

            // Posiziona il cursore dentro il blocco
            tap_code(KC_UP);
        }            
        return false;
            break;
        case QK_MAGIC_SWAP_LCTL_LGUI:
            if (record->event.pressed) {
                os_img_to_show = 1;                 // macOS image
                os_img_timer = timer_read32();      // start timer
            }
            return true; // fai comunque eseguire lo swap a QMK

        case QK_MAGIC_UNSWAP_LCTL_LGUI:
            if (record->event.pressed) {
                os_img_to_show = 2;                 // win/linux image
                os_img_timer = timer_read32();      // start timer
            }
            return true;

        default:
            return true;

        // case MY_ALT_GRAVE:
        //     if (record->event.pressed) {
        //         register_code(KC_LALT);
        //         register_code(KC_GRAVE);
        //         unregister_code(KC_GRAVE);
        //         unregister_code(KC_LALT);
        //     }
        //     return false;
        //     break;
    }
    return true;
}


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (os_img_to_show != 0) {
        if (timer_elapsed32(os_img_timer) < 1000) { // 1 sec
            oled_clear();
            if (os_img_to_show == 1) {
                oled_write_raw_P(macos_img, sizeof(macos_img));
            } else {
                oled_write_raw_P(linux_windows_img, sizeof(linux_windows_img));
            }
            return false;  // non mostrare il resto
        } else {
            os_img_to_show = 0;  // timeout scaduto → torna alla visualizzazione normale
        }
    }

    uint8_t layer = get_highest_layer(layer_state);
    led_t led_state = host_keyboard_led_state();

    oled_clear();

    if (led_state.caps_lock) {
        switch (layer) {
            case 0: oled_write_raw_P(caps_lock_img, sizeof(caps_lock_img)); break;
            case 1: oled_write_raw_P(layer1_with_caps_lock_img, sizeof(layer1_with_caps_lock_img)); break;
            case 2: oled_write_raw_P(layer2_with_caps_lock_img, sizeof(layer2_with_caps_lock_img)); break;
            case 3: oled_write_raw_P(layer3_with_caps_lock_img, sizeof(layer3_with_caps_lock_img)); break;
            default: oled_write_raw_P(other_layer_with_caps_lock_img, sizeof(other_layer_with_caps_lock_img)); break;
        }
    } else {
        switch (layer) {
            case 0: break;
            case 1: oled_write_raw_P(layer1_img, sizeof(layer1_img)); break;
            case 2: oled_write_raw_P(layer2_img, sizeof(layer2_img)); break;
            case 3: oled_write_raw_P(layer3_img, sizeof(layer3_img)); break;
            default: oled_write_raw_P(layer1_img, sizeof(layer1_img)); break;
        }
    }

    return false;
}
#endif
