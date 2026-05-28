#pragma once

#include <stdint.h>
#include <avr/pgmspace.h>

#define SPRITE_WIDTH 128
#define SPRITE_HEIGHT 32
#define SPRITE_SIZE (SPRITE_WIDTH * SPRITE_HEIGHT / 8)

// Each frame must be a byte array (PROGMEM)
static const unsigned char PROGMEM dragon_frame_0[] = { /* frame 0 data */ };
static const unsigned char PROGMEM dragon_frame_1[] = { /* frame 1 data */ };
static const unsigned char PROGMEM dragon_frame_2[] = { /* frame 2 data */ };
static const unsigned char PROGMEM dragon_frame_3[] = { /* frame 3 data */ };
static const unsigned char PROGMEM dragon_frame_4[] = { /* frame 4 data */ };
static const unsigned char PROGMEM dragon_frame_5[] = { /* frame 5 data */ };
static const unsigned char PROGMEM dragon_frame_6[] = { /* frame 6 data */ };
static const unsigned char PROGMEM dragon_frame_7[] = { /* frame 7 data */ };
