#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
            {  34,     33,     32,      31,  30,   29,   28,   NO_LED, NO_LED},
            {  22,   NO_LED,   23,      24,  25,   26,   27,   NO_LED, NO_LED},
            {  21,   NO_LED,   20,      19,  18,   17,   16,   NO_LED, NO_LED},
            {NO_LED,   9,      10,      11,  12,   13,   14,     15,   NO_LED},
            {  8,      7,    NO_LED,     6,   5,    4,  NO_LED,   3,      2  },
            {NO_LED, NO_LED, NO_LED,  NO_LED, 1, NO_LED,  0,   NO_LED, NO_LED},

                                    { NO_LED, 64,   65,    66,     67,      68,    69,     70,    NO_LED},
                                    {  63,    62,   61,    60,     59,      58,    57,     56,    NO_LED },
                                    {  49,    50,   51,    52,     53,      54,  NO_LED,   55,    NO_LED },
                                    { NO_LED, 48,   47,    46,     45,      44,  NO_LED,   43,    NO_LED },
                                    { NO_LED, 37,   38,   NO_LED,  39,      40,    41,     42,    NO_LED },
                                    {  36,    35, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}
        }, 
{
     // right part
    {56, 64}, {84, 64},
    {112, 51}, {98, 51}, {70, 51}, {56, 51}, {42, 51}, {14, 51}, {0, 51},
    {14, 38}, {28, 38}, {42, 38}, {56, 38}, {70, 38}, {84, 38}, {98, 38},
    {84, 26}, {70, 26}, {56, 26}, {42, 26}, {28, 26}, {0, 26},
    {0, 13}, {28, 13}, {42, 13}, {56, 13}, {70, 13}, {84, 13},
    {84, 0}, {70, 0}, {56, 0}, {42, 0}, {28, 0}, {14, 0}, {0, 0},
    {154, 64}, 
     // left part
    {126, 64},
    {140, 51}, {154, 51}, {182, 51}, {196, 51}, {210, 51}, {224, 51},
    {224, 38}, {196, 38}, {182, 38}, {168, 38}, {154, 38}, {140, 38},
    {126, 26}, {140, 26}, {154, 26}, {168, 26}, {182, 26}, {196, 26}, {224, 26},
    {224, 13}, {210, 13}, {196, 13}, {182, 13}, {168, 13}, {154, 13}, {140, 13}, {126, 13},
    {140, 0}, {154, 0}, {168, 0}, {182, 0}, {196, 0}, {210, 0}, {224, 0}
     },
    {
          // right part
          4, 4, 4, 4, 4, 4, 4, 
          4, 4, 4, 4, 4, 4,
          4, 4, 4, 4, 4, 4, 
          4, 4, 4, 4, 4, 4, 4,
          4, 4, 4, 4, 4, 4, 4,
                         4, 4,
          // left part
          4, 4, 4, 4, 4, 4, 4, 
       4, 4, 4, 4, 4, 4, 4, 4,
          4, 4, 4, 4, 4, 4, 4,
             4, 4, 4, 4, 4, 4,
             4, 4, 4, 4, 4, 4, 
             4, 4

    }
 };

// PARTE SX
#define LED_THUMB_SX_1 0
#define LED_THUMB_SX_2 1

#define LED_LAYER_1 2
#define LED_LAYER_GUI 3
#define LED_LAYER_ALT 4
#define LED_LAYER_CTRL 5
#define LED_LAYER_COMMAND 6
#define LED_LAYER_F2 7
#define LED_LAYER_F3 8

#define LED_SHIFT 9
#define LED_Z 10
#define LED_X 11
#define LED_C 12
#define LED_V 13
#define LED_B 14
#define LED_F1 15
#define LED_G 16
#define LED_F 17
#define LED_D 18
#define LED_S 19
#define LED_A 20
#define LED_CAPSLOCK 21

#define LED_TAB 22
#define LED_Q 23
#define LED_W 24
#define LED_E 25
#define LED_R 26
#define LED_T 27

#define LED_6 28
#define LED_5 29
#define LED_4 30
#define LED_3 31
#define LED_2 32
#define LED_1 33
#define LED_ESC 34

// PARTE DX

#define LED_THUMB_DX_1 35
#define LED_THUMB_DX_2 36

#define LED_SPACE_DX 37
#define LED_FN 38
#define LED_LALT 39
#define LED_LGUI 40
#define LED_LEFT 41
#define LED_RIGHT 42

#define LED_RSFT 43
#define LED_SLSH 44
#define LED_DOT 45
#define LED_COMM 46
#define LED_M 47
#define LED_N 48

#define LED_H 49
#define LED_J 50
#define LED_K 51
#define LED_L 52
#define LED_SCLN 53
#define LED_QUOT 54
#define LED_ENTER 55

#define LED_BSLS 56
#define LED_RBRC 57
#define LED_LBRC 58
#define LED_P 59
#define LED_O 60
#define LED_I 61
#define LED_U 62
#define LED_Y 63

#define LED_7 64
#define LED_8 65
#define LED_9 66
#define LED_0 67
#define LED_MINUS 68
#define LED_EQUALS 69
#define LED_BACKSPACE 70


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // No default color, It's controlled by VIAL

    uint8_t layer = get_highest_layer(layer_state | default_layer_state);

    // Gestione dei layer (puoi aggiungere altri colori se vuoi)
    switch(layer) {
        case 1:
            rgb_matrix_set_color(LED_I, 0, 255, 0);
            rgb_matrix_set_color(LED_J, 0, 255, 0);
            rgb_matrix_set_color(LED_K, 0, 255, 0);
            rgb_matrix_set_color(LED_L, 0, 255, 0);
            break;

        case 2:
            rgb_matrix_set_color(LED_I, 0, 0, 255);
            rgb_matrix_set_color(LED_J, 0, 0, 255);
            rgb_matrix_set_color(LED_K, 0, 0, 255);
            rgb_matrix_set_color(LED_L, 0, 0, 255);
            break;
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(LED_CAPSLOCK, 255, 0, 0);  // turn on red LED
    }

    return false;
}


#endif


