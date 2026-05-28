#pragma once

#include <avr/pgmspace.h>

#define SPRITE_SIZE 512

static const unsigned char PROGMEM bunny_frame_0[] = {
    [0 ... 511] = 0x00
};

static const unsigned char PROGMEM bunny_frame_1[] = {
    [0 ... 511] = 0xFF
};

static const unsigned char PROGMEM bunny_frame_2[] = {
    [0 ... 511] = 0xCC
};

static const unsigned char PROGMEM bunny_frame_3[] = {
    [0 ... 511] = 0x33
};

static const unsigned char PROGMEM bunny_frame_4[] = {
    [0 ... 511] = 0xAA
};

static const unsigned char PROGMEM bunny_frame_5[] = {
    [0 ... 511] = 0x55
};

static const unsigned char PROGMEM bunny_frame_6[] = {
    [0 ... 511] = 0x0F
};

static const unsigned char PROGMEM bunny_frame_7[] = {
    [0 ... 511] = 0xF0
};
