#include QMK_KEYBOARD_H
#include "dragon_sprites.h"
#include "bunny_sprites.h"

static uint8_t frame = 0;
static uint32_t timer = 0;

#define FRAME_DELAY 200
#define FRAME_COUNT 8
#define SPRITE_SIZE 128

static const char * const PROGMEM dragon_frames[] = {
    dragon_frame_0, dragon_frame_1, dragon_frame_2, dragon_frame_3,
    dragon_frame_4, dragon_frame_5, dragon_frame_6, dragon_frame_7
};

static const char * const PROGMEM bunny_frames[] = {
    bunny_frame_0, bunny_frame_1, bunny_frame_2, bunny_frame_3,
    bunny_frame_4, bunny_frame_5, bunny_frame_6, bunny_frame_7
};

bool oled_task_user(void) {
    if (timer_elapsed32(timer) > FRAME_DELAY) {
        timer = timer_read32();
        frame = (frame + 1) % FRAME_COUNT;
    }

    oled_set_cursor(0, 0);

    if (is_keyboard_left()) {
        oled_write_raw_P(dragon_frames[frame], SPRITE_SIZE);
    } else {
        oled_write_raw_P(bunny_frames[frame], SPRITE_SIZE);
    }

    return false;
}
