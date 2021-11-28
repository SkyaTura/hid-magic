void sky_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ST_TMUX_W: {
            if (record->event.pressed) {
              char str[5];
              itoa(rgb_matrix_get_mode(), str, 10);
              SEND_STRING(str);
              SEND_STRING(" ");
              itoa(rgb_matrix_get_speed(), str, 10);
              SEND_STRING(str);
              SEND_STRING(" ");
  //              SEND_STRING(SS_LCTRL(SS_TAP(X_BSLASH)) SS_DELAY(100) SS_TAP(X_W));
            }
            break;
        }
        case ST_MACRO_0:
            if (record->event.pressed) {
                switch (get_highest_layer(layer_state)) {
                    case 0: sky_set_layer(1); break; // switch to QWERTY
                    default: sky_set_layer(0); break; // switch to Colemak
                }
                break;
            }
            break;
        case ST_MACRO_1:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(100) SS_TAP(X_SLASH) SS_DELAY(100) SS_TAP(X_F) SS_DELAY(100) SS_TAP(X_F)  SS_DELAY(100) SS_TAP(X_ENTER));

            }
            break;
        case ST_MACRO_2:
            if (record->event.pressed) {
                SEND_STRING(SS_RSFT(SS_TAP(X_ENTER)) SS_DELAY(100) SS_TAP(X_G) SS_DELAY(100) SS_TAP(X_G)  SS_DELAY(100) SS_TAP(X_ENTER));

            }
            break;
        case ST_MACRO_3:
            if (record->event.pressed) {
                SEND_STRING(SS_RSFT(SS_TAP(X_ENTER)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_P)  SS_DELAY(100) SS_TAP(X_ENTER));

            }
            break;
        case ST_MACRO_4:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_A) SS_DELAY(100) SS_TAP(X_L)  SS_DELAY(100) SS_TAP(X_ENTER));

            }
            break;
    }
}
