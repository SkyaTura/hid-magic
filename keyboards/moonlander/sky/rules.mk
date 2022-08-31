# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUTO_SHIFT_ENABLE = yes
AUTO_SHIFT_MODIFIERS = yes
WEBUSB_ENABLE = no
ORYX_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes
TAP_DANCE_ENABLE = yes
RGB_MATRIX_CUSTOM_USER = yes
SRC = matrix.c

SRC += mod_qmk_rc.c
RAW_ENABLE = yes
