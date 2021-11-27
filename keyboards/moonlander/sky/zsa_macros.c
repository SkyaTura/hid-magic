#ifndef zsa_macros_h
#define zsa_macros_h

void zsa_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            break;
        case HSV_172_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(172,255,255);
            }
            break;
        case HSV_86_255_128:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(86,255,128);
            }
            break;
        case HSV_27_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(27,255,255);
            }
            break;
        case HSV_215_255_128:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(215,255,128);
            }
            break;
        case HSV_0_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(0,255,255);
            }
            break;
    }
}

#endif
