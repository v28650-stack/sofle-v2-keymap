#include QMK_KEYBOARD_H
#include <string.h>

#include "dragon_sprites.h"
#include "bunny_sprites.h"

// -----------------------------
// Animation state
// -----------------------------
static uint32_t anim_timer = 0;
static uint8_t current_frame = 0;

#define FRAME_COUNT 8
#define FRAME_DELAY 120
#define ANIM_SIZE 128  // adjust if your OLED is 128x32 (common Sofle)

// -----------------------------
// Sprite mode
// -----------------------------
typedef enum {
    SPRITE_DRAGON = 0,
    SPRITE_BUNNY
} sprite_mode_t;

static sprite_mode_t current_sprite = SPRITE_DRAGON;

// -----------------------------
// Frame pointers
// IMPORTANT: must match sprite header format
// -----------------------------
static const char * const PROGMEM dragon_frames[] = {
    dragon_frame_0, dragon_frame_1, dragon_frame_2, dragon_frame_3,
    dragon_frame_4, dragon_frame_5, dragon_frame_6, dragon_frame_7
};

static const char * const PROGMEM bunny_frames[] = {
    bunny_frame_0, bunny_frame_1, bunny_frame_2, bunny_frame_3,
    bunny_frame_4, bunny_frame_5, bunny_frame_6, bunny_frame_7
};

// -----------------------------
// OPTIONAL: keymap (VIA-safe stub)
// -----------------------------
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

// -----------------------------
// Render sprite
// -----------------------------
static void render_sprite(void) {
    if (timer_elapsed32(anim_timer) > FRAME_DELAY) {
        anim_timer = timer_read32();
        current_frame = (current_frame + 1) % FRAME_COUNT;
    }

    oled_set_cursor(0, 0);

    if (current_sprite == SPRITE_DRAGON) {
        oled_write_raw_P(dragon_frames[current_frame], ANIM_SIZE);
    } else {
        oled_write_raw_P(bunny_frames[current_frame], ANIM_SIZE);
    }
}

// -----------------------------
// OLED task (ONLY ONCE — important)
// -----------------------------
bool oled_task_user(void) {
    render_sprite();
    return false;
}

// -----------------------------
// Optional encoder (safe stub)
// -----------------------------
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}
