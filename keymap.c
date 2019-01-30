/*
 * BÉPO layout for Ergodox EZ keyboards.
 *
 * Author: MARTIN Damien <bepo.ergodox@martin-damien.fr>
 * License: MIT
 *
 * Note: BÉPO keycode can be retrieved in /quantum/keymap_extras/keymap_bepo.h
 */

#include QMK_KEYBOARD_H
#include "keymap_bepo.h"

extern keymap_config_t keymap_config;

/* Custom variables */

bool capsLock = false;

/* Shortcodes */

#define ___     KC_TRANSPARENT
#define XXX     KC_NO
#define _MEH    MEH_T(KC_NO)
#define _HYP    ALL_T(KC_NO)
#define _DOWN   MO(_DOWN_)
#define _UP     MO(_UP_)

/* Layers */

#define _BEPO_   0
#define _UP_     1
#define _DOWN_   2
#define _ADJUST_ 3

/* Layers */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BÉPO
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   B  |   É  |   P  |   O  |   È  |      |           |      |   ^  |   V  |   D  |   L  |   J  |   Z    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Alt    |   A  |   U  |   I  |   E  |   ,  |------|           |------|   C  |   T  |   S  |   R  |   N  |   M    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Shift  |   À  |   Y  |   X  |   .  |   K  |      |           |      |   '  |   Q  |   G  |   H  |   F  |   W    |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Ctl  | MEH  | HYP  | GUI  | DOWN |                                       |  UP  | Left | Down |  Up  | Right|
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,---------------.
     *                                        |      |      |       |      |        |
     *                                ,-------|------|------|       |------+--------+-------.
     *                                |       |      |      |       |      |        |       |
     *                                | Space |      |------|       |------|        | Enter |
     *                                |       |      |      |       |      |        |       |
     *                                `---------------------'       `-----------------------'
     */
    [_BEPO_] = LAYOUT_ergodox(

        // left hand
        XXX,     XXX,        XXX,        XXX,     XXX,       XXX,        XXX,
        KC_TAB,  BP_B,       BP_E_ACUTE, BP_P,    BP_O,      BP_E_GRAVE, XXX,
        KC_LALT, BP_A,       BP_U,       BP_I,    BP_E,      BP_COMMA,
        KC_LSFT, BP_A_GRAVE, BP_Y,       BP_X,    BP_DOT,    BP_K,       XXX,
        KC_LCTL, _MEH,       _HYP,       KC_LGUI, _DOWN,

                                                                      XXX, XXX,
                                                                           XXX,
                                                              KC_SPC, XXX, XXX,


        // right hand
        XXX, XXX,     XXX,      XXX,     XXX,     XXX,   XXX,
        XXX, BP_DCRC, BP_V,     BP_D,    BP_L,    BP_J,  BP_Z,
             BP_C,    BP_T,     BP_S,    BP_R,    BP_N,  BP_M,
        XXX, BP_APOS, BP_Q,     BP_G,    BP_H,    BP_F,  BP_W,
                      _UP,      KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,

        XXX, XXX,
        XXX,
        XXX, XXX, KC_ENTER

    ),

    /* UP
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   "    |   «  |   »  |   (  |   )  |   @  |      |           |      |   +  |   -  |   /  |   *  |   =  |   %    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Alt    |   <  |   >  |   {  |   }  |      |------|           |------|   Ç  |      |   $  |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Shift  |      |      |   [  |   ]  |      |      |           |      |      |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Ctl  | MEH  | HYP  | GUI  | DOWN |                                       |  UP  | Mute | Vol- | Vol+ | Play |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,---------------.
     *                                        |      |      |       |      |        |
     *                                ,-------|------|------|       |------+--------+-------.
     *                                |       |      |      |       |      |        |       |
     *                                |   _   |      |------|       |------|        | Enter |
     *                                |       |      |      |       |      |        |       |
     *                                `---------------------'       `-----------------------'
     */
    [_UP_] = LAYOUT_ergodox(

        // left hand
        ___,     ___,           ___,           ___,           ___,           ___,   ___,
        BP_DQOT, BP_LGIL,       BP_RGIL,       BP_LPRN,       BP_RPRN,       BP_AT, ___,
        ___,     LALT(BP_LGIL), LALT(BP_RGIL), LALT(BP_Y),    LALT(BP_X),    XXX,
        ___,     XXX,           XXX,           LALT(BP_LPRN), LALT(BP_RPRN), XXX,   ___,
        ___,     ___,           ___,           ___,           _DOWN,

                                                                               ___, ___,
                                                                                    ___,
                                                                 LALT(KC_SPC), ___, ___,


        // right hand
        ___, ___,     ___,      ___,       ___,     ___,      ___,
        ___, BP_PLUS, BP_MINUS, BP_SLASH,  BP_ASTR, BP_EQUAL, BP_PERCENT,
             BP_CCED, XXX,      BP_DOLLAR, XXX,     XXX,      XXX,
        ___, XXX,     XXX,      XXX,       XXX,     XXX,      XXX,
                      _UP,      KC_MUTE,   KC_VOLD, KC_VOLU,  KC_MPLY,

        ___, ___,
        ___,
        ___, ___, ___

    ),

    /* DOWN
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Esc    |      |      |      |      |      |      |           |      |      |  7   |  8   |  9   |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Del    |      |      |      |      |      |------|           |------|      |  4   |  5   |  6   |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | C.Lock |      |      |      |      |      |      |           |      |      |  1   |  2   |  3   |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Ctl  | MEH  | HYP  | GUI  | DOWN |                                       |  UP  |  .   |  0   |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,---------------.
     *                                        |      |      |       |      |        |
     *                                ,-------|------|------|       |------+--------+-------.
     *                                |       |      |      |       |      |        |       |
     *                                | Space |      |------|       |------|        | Enter |
     *                                |       |      |      |       |      |        |       |
     *                                `---------------------'       `-----------------------'
     */
    [_DOWN_] = LAYOUT_ergodox(

        // left hand
        ___,     ___, ___, ___,  ___,  ___, ___,
        KC_ESC,  XXX, XXX, XXX,  XXX,  XXX, ___,
        KC_BSPC, XXX, XXX, XXX,  XXX,  XXX,
        KC_CAPS, XXX, XXX, XXX,  XXX,  XXX, ___,
        ___,     ___, ___, ___, _DOWN,

                                       ___, ___,
                                            ___,
                                  ___, ___, ___,


        // right hand
        ___, ___,     ___,      ___,       ___,     ___,      ___,
        ___, XXX, LSFT(BP_PLUS), LSFT(BP_MINUS), LSFT(BP_SLASH), XXX, XXX,
             XXX, LSFT(BP_LPRN), LSFT(BP_RPRN),  LSFT(BP_AT),    XXX, XXX,
        ___, XXX, LSFT(BP_DQOT), LSFT(BP_LGIL),  LSFT(BP_RGIL),  XXX, XXX,
                  _UP,           BP_DOT,         LSFT(BP_ASTR),  XXX, XXX,

        ___, ___,
        ___,
        ___, ___, ___

    ),

    /* ADJUST
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |Reset |      |      |      | DOWN |                                       |  UP  |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,---------------.
     *                                        |      |      |       |      |        |
     *                                ,-------|------|------|       |------+--------+-------.
     *                                |       |      |      |       |      |        |       |
     *                                |       |      |------|       |------|        |       |
     *                                |       |      |      |       |      |        |       |
     *                                `---------------------'       `-----------------------'
     */
    [_ADJUST_] = LAYOUT_ergodox(

        // left hand
        XXX,   XXX,   XXX,   XXX,   XXX,   XXX,   XXX,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, XXX,
        XXX,   XXX,   XXX,   XXX,   XXX,   XXX,
        XXX,   XXX,   XXX,   XXX,   XXX,   XXX, XXX,
        RESET, XXX,   XXX,   XXX,   _DOWN,

                                             XXX, XXX,
                                                  XXX,
                                        XXX, XXX, XXX,


        // right hand
        XXX, XXX,   XXX,   XXX,   XXX,    XXX,    XXX,
        XXX, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
             XXX,   XXX,   XXX,   XXX,    XXX,    XXX,
        XXX, XXX,   XXX,   XXX,   XXX,    XXX,    XXX,
                    _UP,   XXX,   XXX,    XXX,    XXX,

        XXX, XXX,
        XXX,
        XXX, XXX, XXX

    ),

};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _UP_, _DOWN_, _ADJUST_);
}

void matrix_init_user (void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSFT:
            if (capsLock == true) {
                break;
            }
            if (record->event.pressed) {
                ergodox_right_led_1_on();
            } else {
                ergodox_right_led_1_off();
            }
            break;
        case KC_CAPS:
            if (record->event.pressed) {
                if (capsLock == true) {
                    capsLock = false;
                    ergodox_right_led_1_off();
                } else {
                    capsLock = true;
                    ergodox_right_led_1_on();
                }
            }
            break;
        case _DOWN:
            if (record->event.pressed) {
                ergodox_right_led_2_on();
            } else {
                ergodox_right_led_2_off();
            }
            break;
        case _UP:
            if (record->event.pressed) {
                ergodox_right_led_3_on();
            } else {
                ergodox_right_led_3_off();
            }
            break;
        case _MEH:
            if (record->event.pressed) {
                ergodox_right_led_1_on();
                ergodox_right_led_2_on();
                ergodox_right_led_3_on();
            } else {
                ergodox_right_led_1_off();
                ergodox_right_led_2_off();
                ergodox_right_led_3_off();
            }
            break;
    }

    return true;
}
