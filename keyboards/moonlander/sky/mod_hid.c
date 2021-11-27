#include "raw_hid.h"
#include "mod_qmk_rc.h"

#define QMK_RC_BUFFER_MAX 64

// Define QMK_RC Inbound codes
#define RCC_IN_SONG 128
#define RCC_IN_SET_LAYER 129
#define RCC_IN_LOL_INFO 130

// Define QMK_RC Outbound codes
#define RCC_OUT_SET_LAYER 131
#define RCC_OUT_LOL_INFO 132


uint8_t qmk_rc_buffer[QMK_RC_BUFFER_MAX] = {};

float my_song[][2] = SONG(ROCK_A_BYE_BABY);

void qmk_rc_process_command_user(qmk_rc_command_t* command) {
  switch (command->id) {
    case RCC_IN_SONG: PLAY_SONG(my_song); break;
    case RCC_IN_SET_LAYER: sky_set_layer(command->data[0]); break;
    case RCC_IN_LOL_INFO: lol_set_state(command->data); break;
  }
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
  qmk_rc_receive(qmk_rc_buffer, QMK_RC_BUFFER_MAX, data, length);
}

void hid_on_change_layer(int layer) {
    uint8_t send_data[32] = {0, 0};
    send_data[0] = RCC_OUT_SET_LAYER;
    send_data[1] = layer + 1;
    raw_hid_send(send_data, sizeof(send_data));
}
