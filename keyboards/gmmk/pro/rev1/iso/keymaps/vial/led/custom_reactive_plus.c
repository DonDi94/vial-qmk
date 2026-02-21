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

const uint16_t keys_leds[] = {
     0,  1,  2,      4,  5,  6,  7,  8,  9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
    60, 61, 62, 63, 64, 65, 66, 67,
    70,         73,         76,         79,
    80,         83,         86, 87,
    90, 91,         94, 95, 96, 97, 98
};
const uint16_t keys_leds_n = 83;


const uint16_t side_leds[] = {
    // 68, 69
    // 71, 72
    // 74, 75
    77, //, 78
    81, 82,
    84, 85,
    88, 89,
    92, 93
}; // TODO bottom 8 leds not working???
   // Keep only 77 as indicator that the keeb is on profile
   // Also need to fix light bleed with tape
const uint16_t side_leds_n = 9;

static hsv_t CUSTOM_REACTIVE_PLUS_math(hsv_t hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    if (dist == 0) {
        if (tick > 255) tick = 255;
        hsv.v = qadd8(hsv.v, 255 - tick);
    }
    return hsv;
}

bool CUSTOM_REACTIVE_PLUS(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    hsv_t hsv = rgb_matrix_config.hsv;
    rgb_t rgb = hsv_to_rgb(hsv);

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(3,rgb.r, rgb.g, rgb.b);
    } else {
        rgb_matrix_set_color(3, 0x00, 0x00, 0x00);
    }
    for (int i = 0; i < side_leds_n; i++) {
        rgb_matrix_set_color(side_leds[i], RGB_GREEN);//rgb.r, rgb.g, rgb.b);
    }

    return effect_runner_reactive_splash(qsub8(g_last_hit_tracker.count, 10), params, &CUSTOM_REACTIVE_PLUS_math);
}

