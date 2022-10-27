#include <stdio.h>
#include <stdint.h>

uint32_t middle_six(uint32_t x) {
    uint32_t mask = 0b111111;
    mask = 0x3f;
    mask = (1u << 6u) - 1u;

    return (x & (mask << 13)) >> 13;
}
