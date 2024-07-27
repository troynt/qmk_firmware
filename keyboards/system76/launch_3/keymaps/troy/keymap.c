#include QMK_KEYBOARD_H

static bool lctl_pressed, rctl_pressed, esc_pressed;
void system76_ec_unlock(void);


enum layers {
  DVORAK,
  QWERTY,
  FN,
  UNUSED
};


enum my_keycodes {
  SOCD_A = SAFE_RANGE,
  SOCD_D
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Layer 0, Dvorak layer
__________________________________________________________________________________________________________________________________  ________
|        |        |        |        |        |        |        |        |        |        |        |        |        |            ||        |
|  ESC   |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   |  DELETE    ||  HOME  |
|________|________|________|________|________|________|________|________|________|________|________|________|________|____________||________|
|        |        |        |        |        |        |        |        |        |        |        |   [    |   ]    |            ||        |
|  ~`    |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |   {    |   }    | BACKSPACE  ||  PGUP  |
|________|________|________|________|________|________|________|________|________|________|________|________|________|____________||________|
|            |   '    |   ,    |   .    |        |        |        |        |        |        |        |  /     |   =    |        ||        |
|     TAB    |   "    |   <    |   >    |   P    |   Y    |   F    |   G    |   C    |   R    |   L    |  ?     |   +    |  |   \ ||  PGDN  |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|________||________|
  |            |        |        |        |        |        |        |        |        |        |        |   -    |            |   |        |
  |    CTRL    |   A    |   O    |   E    |   U    |   I    |   D    |   H    |   T    |   N    |   S    |   _    |   ENTER    |   |  END   |
  |____________|________|________|________|________|________|________|________|________|________|________|________|____________|___|________|
  |                |   :    |        |        |        |        |        |        |        |        |        |            |        |
  |     SHIFT      |   ;    |   Q    |   J    |   K    |   X    |   B    |   M    |   W    |   V    |   Z    |   SHIFT    |   UP   |
  |________________|________|________|________|________|________|________|________|________|________|________|____________|________|_________
  |            |        |       |        |                 |                 |        |        |             |   |        |        |        |
  |     CAPS   |  LGUI  | FN    | LALT   |      SPACE      |        SPACE    | RALT   |  L1    |     L2      |   |  LEFT  |  DOWN  | RIGHT  |
  |____________|________|_______|________|_________________|_________________|________|________|_____________|   |________|________|________|
*/

  [DVORAK] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,       KC_HOME,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC,      KC_PGUP,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS,  KC_PGDN,
          LM(QWERTY, MOD_LCTL), KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,    KC_ENT,       KC_END,
          KC_LSFT,     KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,  KC_Z,       KC_RSFT,    KC_UP,
          KC_CAPS, LM(QWERTY, MOD_LGUI), MO(FN), LM(QWERTY, MOD_LALT), KC_SPC, KC_SPC, LM(QWERTY, MOD_RALT),   TO(QWERTY),   TO(FN),         KC_LEFT, KC_DOWN, KC_RIGHT
  ),

/* Layer 1, QWERTY layer
__________________________________________________________________________________________________________________________________  ________
|        |        |        |        |        |        |        |        |        |        |        |        |        |            ||        |
|  ESC   |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   |  DELETE    ||  HOME  |
|________|________|________|________|________|________|________|________|________|________|________|________|________|____________||________|
|        |        |        |        |        |        |        |        |        |        |        |        |        |            ||        |
|  ~`    |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |  _ -   | =  +   | BACKSPACE  ||  PGUP  |
|________|________|________|________|________|________|________|________|________|________|________|________|________|____________||________|
|            |        |        |        |        |        |        |        |        |        |        |  [     |   ]    |        ||        |
|     TAB    |   Q    |   W    |   E    |   R    |   T    |   Y    |   U    |   I    |   O    |   P    |  {     |   }    |  |   \ ||  PGDN  |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|________||________|
  |            |        |        |        |        |        |        |        |        |        |   ;    |   '    |            |   |        |
  |    CTRL    |   A    |   S    |   D    |   F    |   G    |   H    |   J    |   K    |   L    |   :    |   "    |   ENTER    |   |  END   |
  |____________|________|________|________|________|________|________|________|________|________|________|________|____________|___|________|
  |                |        |        |        |        |        |        |        |   ,    |    .   |   /    |            |        |
  |     SHIFT      |   Z    |   X    |   C    |   V    |   B    |   N    |   M    |   <    |    >   |   ?    |   SHIFT    |   UP   |
  |________________|________|________|________|________|________|________|________|________|________|________|____________|________|_________
  |            |        |       |        |                 |                 |        |        |             |   |        |        |        |
  |     FN     |  CTRL  | LALT  | LGUI   |      SPACE      |       SPACE     | RALT   |  L1    |     L3      |   |  LEFT  |  DOWN  | RIGHT  |
  |____________|________|_______|________|_________________|_________________|________|________|_____________|   |________|________|________|
*/

  [QWERTY] = LAYOUT(
    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,
    KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MINS, KC_EQL,  KC_TRNS,      KC_TRNS,
        KC_TRNS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_TRNS,
          KC_LCTL, SOCD_A,    KC_S,    SOCD_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_TRNS,       KC_TRNS,
          KC_TRNS,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT,    KC_TRNS,
          KC_TRNS, KC_LGUI, KC_LALT,   KC_LALT,     KC_TRNS,            KC_TRNS,     KC_RALT,   TO(DVORAK),   KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
  ),

    /* Layer 2, function layer
__________________________________________________________________________________________________________________________________  ________
|        |        |        |        |        |        |        |        |        |        |        |        |        |            ||        |
|        |        |        |        |        |        |        |        |        |        |        |        |        |            ||PlayPaus|
|________|________|________|________|________|________|________|________|________|________|________|________|________|____________||________|
|        |        |        |        |        |        |        |        |        |        |  LED   |  LED   |  LED   |            ||        |
|        |        |        |        |        |        |        |        |        |        | TOGGLE |  DOWN  |  UP    |            ||        |
|________|________|________|________|________|________|________|________|________|________|________|________|________|____________||________|
|            |        |        |        |        |        |        |        |        |        |        |        |        |        ||        |
|            |  L1    |        |        |        |        |        |        |        |        |        |        |        | PrtScr ||        |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|________||________|
  |            |        |        |        |        |        |        |        |        |        |        |        |            |   |        |
  |            |        |        | L0     |        |        |        |        |        |        |        |        |            |   |        |
  |____________|________|________|________|________|________|________|________|________|________|________|________|____________|___|________|
  |                |        |        |        |        |        |        |        |        |        |        |            |        |
  |                |PlayPaus|  Prev  |  Next  | VolDn  | VolUp  | VolMute|        |        |        |        |            | VolUp  |
  |________________|________|________|________|________|________|________|________|________|________|________|____________|________|_________
  |            |        |       |        |                 |                 |        |        |             |   |        |        |        |
  |            |        |       |        |                 |                 |        |        |             |   |   Prev | VolDn  |  Next  |
  |____________|________|_______|________|_________________|_________________|________|________|_____________|   |________|________|________|

* 'QK_BOOT' resets the controller and puts the board into firmware flashing mode. If this key is hit accidentally, just unplug the board
*        and plug it back in.
*/

  [FN] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_MPLY,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_VAD, RGB_VAI, KC_TRNS,     KC_TRNS,
        KC_TRNS, TO(1), KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_PSCR, KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,
          KC_TRNS,   KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,    KC_VOLU,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,       KC_MPRV,  KC_VOLD, KC_MNXT
  ),

  [UNUSED] = LAYOUT(
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS
  ),
};

bool a_down = false;
bool d_down = false;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SOCD_A:
            if (record->event.pressed) {
                if (d_down) {
                    unregister_code(KC_D);
                }
                register_code(KC_A);
                a_down = true;
            } else {
                unregister_code(KC_A);
                a_down = false;

                if (d_down) {
                    register_code(KC_D);
                }

            }
            return false;
            break;
        case SOCD_D:
            if (record->event.pressed) {
                if (a_down) {
                    unregister_code(KC_A);
                }
                register_code(KC_D);
                d_down = true;
            } else {
                unregister_code(KC_D);
                d_down = false;

                if (a_down) {
                    register_code(KC_A);
                }
            }
            return false;
            break;
    case KC_LCTL:
        lctl_pressed = record->event.pressed;
        break;
    case KC_RCTL:
        rctl_pressed = record->event.pressed;
        break;
    case KC_ESC:
        esc_pressed = record ->event.pressed;
        break;
    };
    return true;
}

void matrix_scan_user(void) {
    if (lctl_pressed && rctl_pressed && esc_pressed) {
        system76_ec_unlock();
    }
}
