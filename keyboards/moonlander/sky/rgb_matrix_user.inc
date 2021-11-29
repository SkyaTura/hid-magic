RGB_MATRIX_EFFECT(MOD_LOL_ANIM_EFFECT)
RGB_MATRIX_EFFECT(SKY_MAIN_LAYER_EFFECT)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

HSV sky_get_key_color(int layer, int key);

static HSV MOD_LOL_ANIM_EFFECT_math(HSV hsv, uint8_t i, uint8_t time) {
    int16_t v = hsv.v - abs(scale8(g_led_config.point[i].x, 255) - time) * 4;
    hsv.h = 0;
    hsv.v = 255 - scale8(v < 0 ? 0 : v, 255);
    return hsv;
}

bool MOD_LOL_ANIM_EFFECT(effect_params_t* params) { return effect_runner_i(params, &MOD_LOL_ANIM_EFFECT_math); }

static HSV SKY_MAIN_LAYER_EFFECT_math(HSV hsv, uint8_t i, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    //int16_t v = abs(scale8(dist, 255) - tick) * 8;
    uint16_t v = (tick - dist) * 4;
    if (v > 255) v = 255;
    v = 255 - hsv.v + scale8(v, 255);
    if (v < 0) v = 0;
    hsv.v = v;
    return hsv;

    // TODO: animate
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    // hsv.h += effect;
    hsv.v = qadd8(255 - hsv.v, effect);
    return hsv;
}

bool SKY_MAIN_LAYER_EFFECT(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t start = 0;

    uint8_t count = g_last_hit_tracker.count;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = sky_get_key_color(0, i);
        hsv.v = 255;
        for (uint8_t j = start; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], rgb_matrix_config.speed);
            hsv           = SKY_MAIN_LAYER_EFFECT_math(hsv, i, dx, dy, dist, tick);
        }
        // hsv.v   = scale8(hsv.v, rgb_matrix_config.hsv.v);
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#endif
