const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander_split(
    /*          1,               2,               3,            4,            5,            */
    KC_GRAVE,   KC_1,            KC_2,            KC_3,         KC_4,         KC_5,         ST_TMUX_W,
    KC_TAB,     KC_Q,            KC_W,            KC_F,         KC_P,         KC_G,         KC_ASON,
    KC_RCTRL,   KC_A,            KC_R,            KC_S,         KC_T,         KC_D,         OSL(3),
    KC_LSHIFT,  KC_Z,            KC_X,            KC_C,         KC_V,         KC_B,         ____,
    MO(7),      ST_MACRO_0,      KC_EQUAL,        KC_LALT,      KC_SPACE,     ____,         ____,
    ____,       ____,            ____,            MAC_SPACE_L,  KC_LGUI,      KC_BSPACE,    TD(DANCE_0),

    /*          6,               7,               8,            9,            0,            */
    ST_LOL,     KC_6,            KC_7,            KC_8,         KC_9,         KC_0,         KC_MINUS,
    KC_ASOFF,   KC_J,            KC_L,            KC_U,         KC_Y,         KC_SCOLON,    KC_BSLASH,
    OSL(5),     KC_H,            KC_N,            KC_E,         KC_I,         KC_O,         KC_QUOTE,
    ____,       KC_K,            KC_M,            KC_COMMA,     KC_DOT,       KC_SLASH,     KC_RSHIFT,
    ____,       ____,            LT(6,KC_SPACE),  KC_RALT,      KC_LBRACKET,  KC_RBRACKET,  MO(4),
    KC_ESCAPE,  LT(3,KC_ENTER),  KC_RGUI,         MAC_SPACE_R,  ____,         ____,         ____
  ),
  [1] = LAYOUT_moonlander_split(
    ____,  ____,  ____,  ____,      ____,    ____,       ____,
    ____,  KC_Q,  KC_W,  KC_E,      KC_R,    KC_T,       ____,
    ____,  KC_A,  KC_S,  KC_D,      KC_F,    KC_G,       ____,
    ____,  KC_Z,  KC_X,  KC_C,      KC_V,    KC_B,       ____,
    ____,  ____,  ____,  ____,      ____,    ____,       ____,
    ____,  ____,  ____,  ____,      ____,    ____,       ____,

    ____,  ____,  ____,  ____,      ____,    ____,       ____,
    ____,  KC_Y,  KC_U,  KC_I,      KC_O,    KC_P,       ____,
    ____,  KC_H,  KC_J,  KC_K,      KC_L,    KC_SCOLON,  ____,
    ____,  KC_N,  KC_M,  KC_COMMA,  KC_DOT,  KC_SLASH,   ____,
    ____,  ____,  ____,  ____,      ____,    ____,       ____,
    ____,  ____,  ____,  ____,      ____,    ____,       ____
  ),
  [2] = LAYOUT_moonlander_split(
    ____,  ____,            ____,            ____,        ____,  ____,  ____,
    ____,  ____,            ____,            ____,        ____,  ____,  ____,
    ____,  ____,            ____,            ____,        ____,  ____,  ____,
    ____,  ____,            ____,            ____,        ____,  ____,  ____,
    ____,  ____,            ____,            ____,        ____,  ____,  ____,
    ____,  ____,            ____,            ST_MACRO_2,  ____,  ____,  ST_MACRO_1,
    ____,  ____,            ____,            ____,        ____,  ____,  ____,
    ____,  ____,            ____,            ____,        ____,  ____,  ____,
    ____,  ____,            ____,            ____,        ____,  ____,  ____,
    ____,  ____,            ____,            ____,        ____,  ____,  ____,
    ____,  ____,            ____,            ____,        ____,  ____,  ____,
    ____,  LT(3,KC_ENTER),  RSFT(KC_ENTER),  ST_MACRO_3,  ____,  ____,  ____
  ),
  [3] = LAYOUT_moonlander_split(
    KC_ESCAPE,  KC_F1,     KC_F2,    KC_F3,        KC_F4,        KC_F5,       KC_F6,
    ____,       KC_EXLM,   KC_AT,    KC_LCBR,      KC_RCBR,      KC_PIPE,     ____,
    ____,       KC_HASH,   KC_DLR,   KC_LPRN,      KC_RPRN,      KC_GRAVE,    ____,
    ____,       KC_PERC,   KC_CIRC,  KC_LBRACKET,  KC_RBRACKET,  KC_TILD,     ____,
    ____,       KC_COMMA,  ____,     ____,         ____,         ____,        ____,
    ____,       ____,      ____,     ____,         KC_DELETE,    KC_ESCAPE,   ____,
    KC_F7,      KC_F8,     KC_F9,    KC_F10,       KC_F11,       KC_F12,      KC_EQUAL,
    KC_LEFT,    KC_UP,     KC_7,     KC_8,         KC_9,         KC_ASTR,     ____,
    KC_BSLASH,  KC_AMPR,   KC_4,     KC_5,         KC_6,         KC_KP_PLUS,  KC_DQUO,
    ____,       KC_0,      KC_1,     KC_2,         KC_3,         KC_RIGHT,    ____,
    ____,       ____,      ____,     KC_DOT,       KC_DOWN,      KC_EQUAL,    ____,
    ____,       ____,      ____,     ____,         ____,         ____,        ____
  ),
  [4] = LAYOUT_moonlander_split(
    ____,  ____,          ____,             KC_MS_BTN3,           ____,                 ____,                 ____,
    ____,  KC_MS_ACCEL0,  KC_MS_BTN1,       KC_MS_UP,             KC_MS_BTN2,           ____,                 ____,
    ____,  KC_MS_ACCEL1,  KC_MS_LEFT,       KC_MS_DOWN,           KC_MS_RIGHT,          KC_MS_WH_UP,          ____,
    ____,  KC_MS_ACCEL2,  ____,             KC_MS_WH_LEFT,        KC_MS_WH_RIGHT,       KC_MS_WH_DOWN,        ____,
    ____,  ____,          ____,             ____,                 ____,                 ____,                 ____,
    ____,  ____,          ____,             ____,                 ____,                 ____,                 ____,
    ____,  ____,          ____,             ____,                 ____,                 ____,                 ____,
    ____,  ____,          ____,             ____,                 ____,                 ____,                 ____,
    ____,  ____,          ____,             ____,                 ____,                 ____,                 ____,
    ____,  ____,          KC_F14,           KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  KC_F15,               ____,
    ____,  ____,          KC_AUDIO_VOL_UP,  KC_AUDIO_VOL_DOWN,    KC_AUDIO_MUTE,        KC_MEDIA_PLAY_PAUSE,  ____,
    ____,  ____,          ____,             ____,                 ____,                 ____,                 ____
  ),
  [5] = LAYOUT_moonlander_split(
    ST_MACRO_5,    WEBUSB_PAIR,      TO(0),               TO(2),           MOON_LED_LEVEL,   ____,             ____,
    AU_TOG,  RGB_SAI,          TOGGLE_LAYER_COLOR,  RGB_HUI,         RGB_VAI,          RGB_SPI,          RGB_MOD,
    MU_TOG,  RGB_SAD,          RGB_TOG,             RGB_HUD,         RGB_VAD,          RGB_SPD,          RGB_SLD,
    MU_MOD,  HSV_172_255_255,  HSV_86_255_128,      HSV_27_255_255,  HSV_215_255_128,  HSV_0_255_255,    ____,
    ST_MACRO_6,    KC_ASRP,          KC_ASDN,             KC_ASUP,         KC_ASTG,          ____,             ____,
    ____,    ____,             ____,                DYN_REC_STOP,    DYN_REC_START1,   DYN_MACRO_PLAY1,  ____,
    ____,    ____,             ____,                ____,            ____,             ____,             RESET,
    ____,    ____,             ____,                ____,            ____,             ____,             KC_SYSTEM_SLEEP,
    ____,    ____,             ____,                ____,            ____,             ____,             ____,
    ____,    ____,             ____,                ____,            ____,             ____,             ____,
    ____,    ____,             ____,                ____,            ____,             ____,             ____,
    ____,    DYN_MACRO_PLAY2,  DYN_REC_START2,      DYN_REC_STOP,    ____,             ____,             DEBUG
  ),
  [6] = LAYOUT_moonlander_split(
    /*     1,                   2,                      3,                      4,                  5,                   */
    ____,  ____,                ST_LAUNCH_LOL_COMBO_2,  ST_LAUNCH_LOL_COMBO_3,  ____,               ____,                ____,
    ____,  ST_LAUNCH_SEQUELP,   ST_LAUNCH_WHATSAPP,     ST_LAUNCH_FINDER,       ST_LAUNCH_ROBO3T,   ST_LAUNCH_TELEGRAM,  ____,
    ____,  ST_LAUNCH_TERMINAL,  ST_LAUNCH_SLACK,        ST_LAUNCH_DISCORD,      ____,               ST_LAUNCH_LOL,       ____,
    ____,  ST_LAUNCH_DOCKER,    ____,                   ST_LAUNCH_CHROME,       ST_LAUNCH_VIVALDI,  ST_LAUNCH_BLITZ,     ____,
    ____,  ____,                ____,                   ____,                   LGUI(KC_SPACE),     ____,                ____,
    /*     -,                   -,                      T1,                     T2,                 T3,                  T4     */
    ____,  ____,                ____,                   ____,                   ____,               ____,                ____,
    /*     6,                   7,                      8,                      9,                  0,                   */
    ____,  ____,                ____,                   ____,                   ____,               ____,                ____,
    ____,  ST_LAUNCH_SPOTIFY,   ____,                   ST_LAUNCH_IINA,         ____,               ST_LAUNCH_SYSTEM_P,  ____,
    ____,  KC_LEFT,             KC_DOWN,                KC_UP,                  KC_RIGHT,           KC_RSHIFT,           ____,
    ____,  ____,                ____,                   ____,                   ____,               ____,                ____,
    ____,  ____,                ____,                   ____,                   ____,               ____,                ____,
    /*
    T5,    T6,                  T7,                     T8,                     -,                  -,                   */
    ____,  ____,                ____,                   ____,                   ____,               ____,                ____
  ),
  [7] = LAYOUT_moonlander_split(
    ____,  ____,           ____,            KC_MS_BTN3,     ____,            ____,           ____,
    ____,  KC_MS_ACCEL0,   KC_MS_BTN1,      KC_MS_UP,       KC_MS_BTN2,      ____,           ____,
    ____,  KC_MS_ACCEL1,   KC_MS_LEFT,      KC_MS_DOWN,     KC_MS_RIGHT,     KC_MS_WH_UP,    ____,
    ____,  KC_MS_ACCEL2,   ____,            KC_MS_WH_LEFT,  KC_MS_WH_RIGHT,  KC_MS_WH_DOWN,  ____,
    ____,  ____,           ____,            ____,           ____,            ____,           ____,
    ____,  ____,           ____,            ____,           ____,            ____,           ____,
    ____,  ____,           ____,            KC_MS_BTN3,     ____,            ____,           ____,
    ____,  ____,           KC_MS_BTN1,      KC_MS_UP,       KC_MS_BTN2,      KC_MS_ACCEL0,   ____,
    ____,  KC_MS_WH_UP,    KC_MS_LEFT,      KC_MS_DOWN,     KC_MS_RIGHT,     KC_MS_ACCEL1,   ____,
    ____,  KC_MS_WH_LEFT,  KC_MS_WH_RIGHT,  ____,           KC_MS_ACCEL2,    ____,           ____,
    ____,  ____,           ____,            ____,           ____,            ____,           ____,
    ____,  ____,           ____,            ____,           ____,            ____,           ____
  ),
};

int default_layer = 0;

