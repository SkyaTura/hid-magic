
#define SOUND_RICK_ROLL  \
Q__NOTE(_F4),   \
Q__NOTE(_G4),   \
Q__NOTE(_BF4),  \
Q__NOTE(_G4), \
HD_NOTE(_D5), \
HD_NOTE(_D5),  \
W__NOTE(_C5),  \
S__NOTE(_REST),   \
Q__NOTE(_F4),  \
Q__NOTE(_G4), \
Q__NOTE(_BF4), \
Q__NOTE(_G4),  \
HD_NOTE(_C5),  \
HD_NOTE(_C5), \
W__NOTE(_BF4),  \
S__NOTE(_REST),   \
Q__NOTE(_F4),  \
Q__NOTE(_G4),  \
Q__NOTE(_BF4), \
Q__NOTE(_G4),  \
W__NOTE(_BF4),  \
H__NOTE(_C5),  \
H__NOTE(_A4), \
H__NOTE(_A4),  \
H__NOTE(_G4), \
H__NOTE(_F4),  \
H__NOTE(_F4), \
W__NOTE(_C5),  \
W__NOTE(_BF4),

#define SOUND_ALL_STAR \
    H__NOTE(_AS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), H__NOTE(_FS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), \
    H__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_FS4), QD_NOTE(_AS4), \
    H__NOTE(_AS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), H__NOTE(_FS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), \
    H__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_AS4), H__NOTE(_REST),\
    W__NOTE(_AS4), W__NOTE(_CS5), H__NOTE(_B4),  H__NOTE(_CS5), H__NOTE(_DS5), W__NOTE(_FS5), \
    H__NOTE(_GS5), W__NOTE(_GS5), H__NOTE(_FS4), H__NOTE(_FS4), H__NOTE(_GS4), H__NOTE(_FS4), \
    H__NOTE(_AS4), W__NOTE(_GS4), W__NOTE(_GS4), W__NOTE(_FS4), W__NOTE(_GS4), \
    H__NOTE(_AS4), WD_NOTE(_DS4)

float song[][2] = SONG(SOUND_RICK_ROLL);
float allStar[][2] = SONG(SOUND_ALL_STAR);

void sky_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ST_TMUX_W: {
            if (record->event.pressed) {
              char str[5];
              itoa(g_last_hit_tracker.count, str, 10);
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
        case ST_MACRO_5:
            if (record->event.pressed) {
              PLAY_SONG(song);

            }
            break;
        case ST_MACRO_6:
            if (record->event.pressed) {
              PLAY_SONG(allStar);

            }
            break;
    }
}
