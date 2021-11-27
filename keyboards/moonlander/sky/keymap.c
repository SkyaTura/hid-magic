#include QMK_KEYBOARD_H
#include "debug.h"
#include "version.h"

#include "sky.h"

#include "mod_hid.c"

#include "sky_utils.c"

#include "sky_keycodes.h"
#include "sky_keymap.c"
#include "sky_rgb.c"

#include "sky_macros.c"
#include "zsa_macros.c"

#include "mod_lol.c"
#include "mod_spotlight.c"
#include "mod_mac_utils.c"

#include "keymap_us_international.h"
/*
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
*/

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  sky_process_record_user(keycode, record);
  mac_process_record_user(keycode, record);
  lol_process_record_user(keycode, record);
  zsa_process_record_user(keycode, record);
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(LGUI(LSFT(KC_4))));
        tap_code16(LCTL(LGUI(LSFT(KC_4))));
        tap_code16(LCTL(LGUI(LSFT(KC_4))));
    }
    if(state->count > 3) {
        tap_code16(LCTL(LGUI(LSFT(KC_4))));
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LCTL(LGUI(LSFT(KC_4)))); break;
        case SINGLE_HOLD: register_code16(LGUI(LSFT(KC_5))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_4))); break;
        case DOUBLE_HOLD: register_code16(LCTL(LGUI(LSFT(KC_3)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(LGUI(LSFT(KC_4)))); register_code16(LCTL(LGUI(LSFT(KC_4))));
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LCTL(LGUI(LSFT(KC_4)))); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_5))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_4))); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(LGUI(LSFT(KC_3)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(LGUI(LSFT(KC_4)))); break;
    }
    dance_state[0].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};

