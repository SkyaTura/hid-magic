char* mac_get_spotlight_app(uint16_t keycode) {
    switch (keycode) {
      case ST_LAUNCH_BLITZ     : return "blitz";
      case ST_LAUNCH_LOL       : return "league of legends";
      case ST_LAUNCH_DISCORD   : return "discord";
      case ST_LAUNCH_CHROME    : return "chrome";
      case ST_LAUNCH_TERMINAL  : return "wezterm";
      case ST_LAUNCH_ROBO3T    : return "robo 3t";
      case ST_LAUNCH_VIVALDI   : return "vivaldi";
      case ST_LAUNCH_WHATSAPP  : return "whatsapp";
      case ST_LAUNCH_DOCKER    : return "docker";
      case ST_LAUNCH_FINDER    : return "finder";
      case ST_LAUNCH_TELEGRAM  : return "telegram";
      case ST_LAUNCH_SLACK     : return "slack";
      case ST_LAUNCH_SPOTIFY   : return "spotify";
      case ST_LAUNCH_SEQUELP   : return "sequel";
      case ST_LAUNCH_SYSTEM_P  : return "preferencias do sistema";
      case ST_LAUNCH_IINA      : return "iina";
      default: return "";
    }
};

void mac_exec_spotlight(uint16_t keycode) {
    char* str = mac_get_spotlight_app(keycode);
    if (!str) return;
    SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)) SS_DELAY(100));
    SEND_STRING(str);
    SEND_STRING(SS_DELAY(100) SS_TAP(X_ENTER));
}

void mac_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ST_TMUX_W: {
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL(SS_TAP(X_BSLASH)) SS_DELAY(100) SS_TAP(X_W));
            }
            break;
        }
        case ST_LAUNCH_LOL_COMBO_3: {
            if (record->event.pressed) {
                mac_exec_spotlight(ST_LAUNCH_DISCORD);
            }
        }
        case ST_LAUNCH_LOL_COMBO_2: {
            if (record->event.pressed) {
                mac_exec_spotlight(ST_LAUNCH_BLITZ);
            }
        }
        case ST_LAUNCH_LOL: {
            if (record->event.pressed) {
                mac_exec_spotlight(ST_LAUNCH_LOL);
            }
            break;
        }
        case ST_LAUNCH_SYSTEM_P:
        case ST_LAUNCH_BLITZ:
        case ST_LAUNCH_DISCORD:
        case ST_LAUNCH_CHROME:
        case ST_LAUNCH_IINA:
        case ST_LAUNCH_TERMINAL:
        case ST_LAUNCH_ROBO3T:
        case ST_LAUNCH_VIVALDI:
        case ST_LAUNCH_WHATSAPP:
        case ST_LAUNCH_DOCKER:
        case ST_LAUNCH_FINDER:
        case ST_LAUNCH_TELEGRAM:
        case ST_LAUNCH_SEQUELP:
        case ST_LAUNCH_SLACK:
        case ST_LAUNCH_SPOTIFY: {
            if (record->event.pressed) {
                mac_exec_spotlight(keycode);
            }
            break;
        }
    }
}
