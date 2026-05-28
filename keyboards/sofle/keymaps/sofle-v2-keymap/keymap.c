#include QMK_KEYBOARD_H
#include "dragon_sprites.h"
#include "bunny_sprites.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_0;
}

// Animation state
// static uint32_t anim_timer = 0;
// static uint8_t current_frame = 0;

// Sprite selection
typedef enum {
    SPRITE_DRAGON = 0,
    SPRITE_BUNNY  = 1
} sprite_mode_t;

// static sprite_mode_t current_sprite = SPRITE_DRAGON;

// Frame pointers — note: const on both the pointer and the data
static const char * const PROGMEM dragon_frames[] = {
    dragon_frame_0, dragon_frame_1, dragon_frame_2, dragon_frame_3,
    dragon_frame_4, dragon_frame_5, dragon_frame_6, dragon_frame_7
};

static const char * const PROGMEM bunny_frames[] = {
    bunny_frame_0, bunny_frame_1, bunny_frame_2, bunny_frame_3,
    bunny_frame_4, bunny_frame_5, bunny_frame_6, bunny_frame_7
};

#define FRAME_COUNT  8
#define FRAME_DELAY  200
#define ANIM_SIZE    512

// Required by QMK even when using VIA
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_clear();
        oled_set_cursor(0, 0);
        oled_write_P(PSTR("MASTER"), false);
        oled_set_cursor(0, 2);
        oled_write_P(PSTR("LEFT SIDE"), false);
    } else {
        oled_clear();
        oled_set_cursor(0, 0);
        oled_write_P(PSTR("SLAVE"), false);
        oled_set_cursor(0, 2);
        oled_write_P(PSTR("RIGHT SIDE"), false);
    }

    return false;
}
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}
