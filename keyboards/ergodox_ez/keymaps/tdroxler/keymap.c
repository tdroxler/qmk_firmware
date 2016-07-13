#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_german_ch.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 TODO
   - Move Cmd (windows) key since I want to be able to push dwon enter or move enter...let see
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Esc/Ctrl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|Ent/Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |Back  |      | Home |       | PgUp |        |      |
 *                                 |space |Delete|------|       |------| Enter  |Space |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
  [BASE] = KEYMAP(  // layer 0 : default
      // left hand
      KC_EQL,           KC_1,           KC_2,           KC_3,       KC_4,       KC_5,               KC_LEFT,
      KC_TAB,           KC_Q,           KC_W,           KC_E,       KC_R,       KC_T,               TG(SYMB),
      CTL_T(KC_ESC),    KC_A,           KC_S,           KC_D,       KC_F,       KC_G,               
      KC_LSFT,          CTL_T(KC_Z),    KC_X,           KC_C,       KC_V,       KC_B,               ALL_T(KC_NO),
      LT(SYMB,KC_GRV),  KC_QUOT,        LALT(KC_LSFT),  KC_LEFT,    KC_RGHT,
                                                                                  ALT_T(KC_APP),      KC_LGUI,
                                                                                                      KC_HOME,
                                                                      KC_BSPC,    KC_DEL,             KC_BSPC,
      // right hand
      KC_RGHT,          KC_6,           KC_7,           KC_8,       KC_9,       KC_0,               KC_MINS,
      TG(SYMB),         KC_Y,           KC_U,           KC_I,       KC_O,       KC_P,               KC_BSLS,
                        KC_H,           KC_J,           KC_K,       KC_L,       LT(MDIA, KC_SCLN),  GUI_T(KC_ENT),
      MEH_T(KC_NO),     KC_N,           KC_M,           KC_COMM,    KC_DOT,     CTL_T(KC_SLSH),     KC_RSFT,
                                        KC_UP,          KC_DOWN,    KC_LBRC,    KC_RBRC,            KC_FN1,
    KC_LALT,          CTL_T(KC_ESC),  
    KC_PGUP,
    KC_PGDN,          KC_ENT,           KC_SPC
  ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
  [SYMB] = KEYMAP(
      // left hand
      M(0),     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
      KC_TRNS,  CH_EXLM,  CH_AT,    CH_LCBR,  CH_RCBR,  CH_PIPE,  KC_TRNS,
      KC_TRNS,  CH_HASH,  CH_DLR,   CH_LPRN,  CH_RPRN,  CH_GRV,
      KC_TRNS,  CH_PERC,  CH_CARR,  CH_LBRC,  CH_RBRC,  CH_TILD,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                          KC_TRNS,  KC_TRNS,
                                                                    KC_TRNS,
                                                 KC_TRNS, KC_TRNS,  KC_TRNS,
      // right hand
      KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,    KC_F11,
      KC_TRNS,  KC_UP,    KC_7,     KC_8,     KC_9,    CH_PAST,   KC_F12,
                KC_DOWN,  KC_4,     KC_5,     KC_6,    CH_PLUS,   KC_TRNS,
      KC_TRNS,  CH_AMPR,  KC_1,     KC_2,     KC_3,    CH_BSLS,   KC_TRNS,
                          KC_TRNS,  CH_DOT,   KC_0,    CH_EQL,    KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
/* Keymap 2: Xmonad, media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |Cmd(1)|Cmd(2)|Cmd(3)|Cmd(4)|Cmd(5)|      |           |      |Cmd(6)|Cmd(7)|Cmd(8)|Cmd(9)|      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |Cmd(Tab)|Cmd(q)|Cmd(w)|Cmd(e)|Cmd(r)|      |      |           |      |      |      | MsUp |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |MsLeft|MsDown|MsRght|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |TEENSY|      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Cmd(  |      |      |       |      |      |      |
 *                                 | Space|      |------|       |------|      |      |
 *                                 |)     |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// XMONAD, MEDIA AND MOUSE
  [MDIA] = KEYMAP(
      KC_TRNS,      LGUI(KC_1), LGUI(KC_2),  LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), KC_TRNS,
      LGUI(KC_TAB), LGUI(KC_Q), LGUI(KC_W),  LGUI(KC_E), LGUI(KC_R), KC_TRNS,    KC_TRNS,
      KC_TRNS,      KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
      KC_TRNS,      KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
      RESET  ,      KC_TRNS,    KC_TRNS,     KC_BTN1,    KC_BTN2,
                                                                     KC_TRNS, KC_TRNS,
                                                                              KC_TRNS,
                                                       LGUI(KC_SPC), KC_TRNS, KC_TRNS,
      // right hand
      KC_TRNS,  LGUI(KC_6), LGUI(KC_7),  LGUI(KC_8), LGUI(KC_9), KC_TRNS,    KC_TRNS,
      KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_MS_U,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,    KC_MS_L,     KC_MS_D,    KC_MS_R,    KC_TRNS,    KC_MPLY,
      KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_MPRV,    KC_MNXT,    KC_TRNS,    KC_TRNS,
                            KC_VOLU,     KC_VOLD,    KC_MUTE,    KC_TRNS,    KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS,KC_TRNS 
  ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
