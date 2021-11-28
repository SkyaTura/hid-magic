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

static HSV SKY_MAIN_LAYER_EFFECT_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    // TODO: animate
    return hsv;
}

bool SKY_MAIN_LAYER_EFFECT(effect_params_t* params) { return effect_runner_reactive_splash(0, params, &SKY_MAIN_LAYER_EFFECT_math); }

#endif
