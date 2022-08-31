#ifndef sky_utils_c
#define sky_utils_c

// Colors
#define  CL_BLACK    {  0,    0,    0    }
#define  CL_RED      {  0,    255,  255  }
#define  CL_GREEN    {  85,   255,  255  }
#define  CL_BLUE     {  170,  255,  255  }
#define  CL_CYAN     {  127,  255,  255  }
#define  CL_MAGENTA  {  212,  255,  255  }
#define  CL_WHITE    {  0,    0,    255  }
#define  CL_GOLD     {  41,   255,  255  }
#define  CL_BGREEN   {  105,  255,  255  }

// Aliases
#define ___ KC_NO
#define ____ KC_TRANSPARENT

// Layout Helpers

/* Base Layout

//     1      2      3      4      5      -
____,  ____,  ____,  ____,  ____,  ____,  ____,
____,  ____,  ____,  ____,  ____,  ____,  ____,
____,  ____,  ____,  ____,  ____,  ____,  ____,
____,  ____,  ____,  ____,  ____,  ____,  ____,
____,  ____,  ____,  ____,  ____,  ____,  ____,
//     -      -      T3     T2     T1     TU
____,  ____,  ____,  ____,  ____,  ____,  ____,

//     6      7      8      9      0      -
____,  ____,  ____,  ____,  ____,  ____,  ____,
____,  ____,  ____,  ____,  ____,  ____,  ____,
____,  ____,  ____,  ____,  ____,  ____,  ____,
____,  ____,  ____,  ____,  ____,  ____,  ____,
____,  ____,  ____,  ____,  ____,  ____,  ____,
//     T1     T2     T3     -      -      -
____,  ____,  ____,  ____,  ____,  ____,  ____,

*/
// clang-format off

// Used to mount keymaps easier
#define LAYOUT_moonlander_split( \
    l00,  l01,  l02,  l03,  l04,  l05,  l06,  \
    l07,  l08,  l09,  l10,  l11,  l12,  l13,  \
    l14,  l15,  l16,  l17,  l18,  l19,  l20,  \
    l21,  l22,  l23,  l24,  l25,  l26,  lx0,  \
    l27,  l28,  l29,  l30,  l31,  lx1,  lx2,  \
    lx3,  lx4,  lx5,  l32,  l33,  l34,  l35,  \
    r00,  r01,  r02,  r03,  r04,  r05,  r06,  \
    r07,  r08,  r09,  r10,  r11,  r12,  r13,  \
    r14,  r15,  r16,  r17,  r18,  r19,  r20,  \
    rx0,  r21,  r22,  r23,  r24,  r25,  r26,  \
    rx1,  rx2,  r27,  r28,  r29,  r30,  r31,  \
    r32,  r33,  r34,  r35,  rx3,  rx4,  rx5     \
)     \
 {  \
 {  l00,  l01,  l02,  l03,  l04,  l05,  l06  },  \
 {  l07,  l08,  l09,  l10,  l11,  l12,  l13  },  \
 {  l14,  l15,  l16,  l17,  l18,  l19,  l20  },  \
 {  l21,  l22,  l23,  l24,  l25,  l26,  ___  },  \
 {  l27,  l28,  l29,  l30,  l31,  ___,  ___  },  \
 {  l34, l33, l32,  l35,  ___,  ___,  ___  },  \
 {  r00,  r01,  r02,  r03,  r04,  r05,  r06  },  \
 {  r07,  r08,  r09,  r10,  r11,  r12,  r13  },  \
 {  r14,  r15,  r16,  r17,  r18,  r19,  r20  },  \
 {  ___,  r21,  r22,  r23,  r24,  r25,  r26  },  \
 {  ___,  ___,  r27,  r28,  r29,  r30,  r31  },  \
 {  ___,  ___,  ___,  r32,  r35,  r34,  r33  }   \
}

// Used to mount layer ledmatrix easier
#define LED_moonlander_split( \
    l00,  l05,  l10,  l15,  l20,  l25,  l29,  \
    l01,  l06,  l11,  l16,  l21,  l26,  l30,  \
    l02,  l07,  l12,  l17,  l22,  l27,  l31,  \
    l03,  l08,  l13,  l18,  l23,  l28,  x00,  \
    l04,  l09,  l14,  l19,  l24,  x01,  x02,  \
    x03,  x04,  x05,  l32,  l33,  l34,  l35,  \
    r29,  r25,  r20,  r15,  r10,  r05,  r00,  \
    r30,  r26,  r21,  r16,  r11,  r06,  r01,  \
    r31,  r27,  r22,  r17,  r12,  r07,  r02,  \
    x06,  r28,  r23,  r18,  r13,  r08,  r03,  \
    x08,  x07,  r24,  r19,  r14,  r09,  r04,  \
    x11,  x10,  x09,  r35,  r34,  r33,  r32   \
) { \
    l00, l01, l02, l03, l04, l05, l06, l07, l08, l09, \
    l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, \
    l20, l21, l22, l23, l24, l25, l26, l27, l28, l29, \
    l30, l31, l32, l33, l34, l35,                     \
    r00, r01, r02, r03, r04, r05, r06, r07, r08, r09, \
    r10, r11, r12, r13, r14, r15, r16, r17, r18, r19, \
    r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, \
    r30, r31, r32, r33, r34, r35                      \
}
// clang-format on

// Array Utils
int indexOf( const int a[], size_t size, int value ) {
    size_t index = 0;
    while ( index < size && a[index] != value ) ++index;
    return ( index == size ? -1 : index );
}
bool isBetween(int reference, int min, int max) {
    return reference <= max && reference >= min;
}

void sky_set_layer(int layer) {
    // Apply layer
    switch (layer) {
        case 0: {
            layer_off(1);
            layer_off(2);
            layer_on(0);
            break;
        }
        case 1: {
            layer_off(0);
            layer_off(2);
            layer_on(1);
            break;
        }
        case 2: {
            layer_off(0);
            layer_off(1);
            layer_on(2);
            break;
        }
        default: layer_move(layer);
    }
    // Apply per layer behaviors
    switch (layer) {
        case 0: {
            autoshift_enable();
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_SKY_MAIN_LAYER_EFFECT);
            rgb_matrix_set_speed_noeeprom(125);
            rgb_matrix_enable_noeeprom();
            break;
        }
        case 1: {
            autoshift_enable();
            rgb_matrix_mode_noeeprom(21);
            rgb_matrix_set_speed_noeeprom(255);
            rgb_matrix_enable_noeeprom();
            break;
        }
        case 2: {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_MOD_LOL_ANIM_EFFECT);
            rgb_matrix_set_speed_noeeprom(255);
            autoshift_disable();
            break;
        }
        default: {
            rgb_matrix_mode_noeeprom(0);
        }
    }
    // Emit HID event
    hid_on_change_layer(layer);
}

#endif
