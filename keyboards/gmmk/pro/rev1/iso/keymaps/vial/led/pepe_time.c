/* Copyright 2022 DonDi94  <https://github.com/DonDi94>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

bool PEPE_TIME(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    hsv_t hsv = rgb_matrix_config.hsv;
    rgb_t rgb = hsv_to_rgb(hsv);

    uint16_t green_leds[] = {
        23, // {61,    0} , F4, k33
        28, // {79,    0} , F5, k07
        34, // {94,    0} , F6, k63
        44, // {123,   0} , F8, k76
        50, // {141,   0} , F9, ka6
        56, // {155,   0} , F10, ka7

        19, // {43,    15} , 3, k37
        24, // {58,    15} , 4, k47
        29, // {72,    15} , 5, k46
        35, // {87,    15} , 6, k56
        40, // {101,   15} , 7, k57
        45, // {116,   15} , 8, k67
        51, // {130,   15} , 9, k77
        57, // {145,   15} , 0, k87
        62, // {159,   15} , -, k86

        14, // {36,    26} , W, k20
        20, // {51,    26} , E, k30
        41, // {108,   26} , U, k50
        63, // {166,   26} , [, k81

        9,  // {25,    38} , A, k12
        15, // {40,    38} , S, k22
        26, // {69,    38} , F, k42
        31, // {83,    38} , G, k43
        37, // {98,    38} , H, k53
        42, // {112,   38} , J, k52
        47, // {126,   38} , K, k62
        53, // {141,   38} , L, k72
        59, // {155,   38} , ;, k82
        64, // {170,   38} , ", k83

        10, // {33,    49} , Z, k14
        16, // {47,    49} , X, k24

        17, // {38,    61} , Alt_L, k93
        33, // {92,    61} , SPACE, k94
        49, // {145,   61} , Alt_R, k95
        55, // {159,   61} , FN, k92

        94, // {206,   52} , Up, k35
        80, // {220,   64} , Right, k05
        96, // {191,   64} , Left, k03
        98  // {206,   64} , Down, k73
    };

    uint16_t white_leds[] = {
        25, // {65, 26}, R, k40
        36, // {94, 26}, Y, k51
        46, // {123, 26}, I, k60
        58 // {152, 26}, P, k80
    };

    uint16_t red_leds[] = {
        21, //{54, 38}, D, k32
        22, //{61, 49}, C, k34
        27, //{76, 49}, V, k44
        32, //{90, 49}, B, k45
        38, //{105, 49}, N, k55
        43, //{119, 49}, M, k54
        48, //{134, 49}, ,, k64
        54, //{148, 49}, ., k74
        60 //{163, 49}, /, k85
    };

    uint16_t leds_off[] = {
        0, // {0, 0}, ESC, k13
        1, // {0, 15}, `, k16
        2, // {4, 26}, Tab, k11
        4, // {2, 49}, Sh_L, k00
        5, // {2, 61}, Ct_L, k06
        6, // {18, 0}, F1, k26
        7, // {14, 15}, 1, k17
        8, // {22, 26}, Q, k10
        11, // {20, 61}, Win_L, k90
        12, // {33, 0}, F2, k36
        13, // {29, 15}, 2, k27
        18, // {47, 0}, F3, k31
        30, // {79, 26}, T, k41
        61, // {170, 0}, F11, ka3
        64, // {170, 38}, ", k83
        65, // {173, 61}, Ct_R, k04
        66, // {184, 0}, F12, ka5
        67, // {18, 49}, \, k23
        52, // {137, 26}, O, k70
        70, // {202, 0}, Prt, k97
        73, // {224, 15}, Del, k65
        76, // {224, 26}, PgUp, k15
        79, // {173, 15}, =, k66
        83, // {224, 49}, End, k75
        86, // {195, 15}, BSpc, ka1
        87, // {224, 38}, PgDn, k25
        91, // {182, 49}, Sh_R, k91
        95, // {184, 38}, #, k84
        90, // {181, 26}, ], k61
        // Disable side leds
        68, 69, 71, 72, 74, 75, 77, 78, 81, 82, 84, 85, 88, 89, 92, 93
    };

    // Light bleedthrough, disable for now
    // uint16_t side_leds[] = {
    //     68, 69, 71, 72, 74, 75, 77, 78, 81, 82, 84, 85, 88, 89, 92, 93
    // };

    for (int i = 0; i < sizeof(leds_off) / sizeof(leds_off[0]); i++) {
        rgb_matrix_set_color(leds_off[i], 0x00, 0x00, 0x00);
    }
    for (int i = 0; i < sizeof(green_leds) / sizeof(green_leds[0]); i++) {
        rgb_matrix_set_color(green_leds[i], RGB_GREEN);
    }
    for (int i = 0; i < sizeof(white_leds) / sizeof(white_leds[0]); i++) {
        rgb_matrix_set_color(white_leds[i], RGB_WHITE);
    }
    for (int i = 0; i < sizeof(red_leds) / sizeof(red_leds[0]); i++) {
        rgb_matrix_set_color(red_leds[i], RGB_RED);
    }
    // for (int i = 0; i < sizeof(side_leds) / sizeof(side_leds[0]); i++) {
    //     rgb_matrix_set_color(side_leds[i], rgb.r, rgb.g, rgb.b);
    // }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(3, rgb.r, rgb.g, rgb.b);
    } else {
        rgb_matrix_set_color(3, 0x00, 0x00, 0x00);
    }

    return led_max < RGB_MATRIX_LED_COUNT;
}
