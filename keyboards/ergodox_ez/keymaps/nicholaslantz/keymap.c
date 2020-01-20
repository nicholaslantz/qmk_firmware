#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYM 1 // symbols
#define CUR 2 // cursor keys
#define MDIA 3 // media keys

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_NO,           KC_F1,       KC_F2,         KC_F3,   KC_F4,   KC_F5,   KC_F6,
  KC_ESC,          KC_Q,        KC_F,          KC_U,    KC_Y,    KC_Z,    KC_NO,
  LT(SYM, KC_TAB), KC_O,        KC_H,          KC_E,    KC_A,    KC_I,
  KC_LSFT,         KC_COMM,     KC_M,          KC_DOT,  KC_J,    KC_SCLN, KC_NO,
  KC_NO,           KC_NO,       KC_NO,         KC_NO,   KC_NO,
  KC_NO, KC_NO,
  KC_NO,
  KC_SPC, KC_LCTRL, KC_LGUI,
  
  // right hand
  KC_F7,        KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,         KC_NO,      
  KC_NO,        KC_X,    KC_K,    KC_C,    KC_W,     KC_B,           KC_NO,
                KC_D,    KC_R,    KC_T,    KC_N,     LT(MDIA, KC_S), MO(SYM),
  KC_NO,        KC_G,    KC_L,    KC_P,    KC_V,     MO(CUR),        KC_RSFT,
  KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_NO,
  KC_NO,
  KC_NO, KC_LALT, KC_ENT
),

[SYM] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_DQUO, KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC, KC_TRNS,
  KC_TRNS, KC_SLSH, KC_MINS, KC_LCBR, KC_RCBR, KC_ASTR,
  KC_NO,   KC_HASH, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV,  KC_TRNS,
  EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_AMPR, KC_TRNS,
           KC_QUES, KC_LPRN, KC_RPRN, KC_QUOT, KC_COLN, KC_TRNS,
  KC_TRNS, KC_PLUS, KC_PERC, KC_BSLS, KC_AT,   KC_TRNS, KC_NO,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

[CUR] = LAYOUT_ergodox(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, KC_TRNS,
  KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,

  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_NO,   KC_1,    KC_2,    KC_3,    KC_NO,   KC_NO,
           KC_NO,   KC_4,    KC_5,    KC_6,    KC_NO,   KC_TRNS,
  KC_TRNS, KC_0,    KC_7,    KC_8,    KC_9,    KC_TRNS, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

[MDIA] = LAYOUT_ergodox(
  // left hand
  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_NO, KC_WH_U, KC_MS_U, KC_WH_D, KC_BTN3, KC_NO,
  KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,
  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_NO,
  KC_NO,
  KC_BTN1, KC_BTN2, KC_NO,
  // right hand
  KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_MPLY,
  KC_NO, KC_NO,   KC_NO, KC_MPRV, KC_MNXT, KC_NO,   KC_NO,
         KC_VOLU, KC_VOLD, KC_MUTE, KC_NO, KC_NO,
  KC_NO, KC_NO,
  KC_NO,
  KC_NO, KC_NO, KC_WBAK
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
