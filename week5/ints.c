// int -> 4 bytes (could actually be something like 2 bytes)
// char -> 1 byte
// long long -> 8 bytes
//
// unsinged int -> 4 bytes (Vs signed int which is just int)
//
//
// 1 hex digit = 4 binary digits

#include <stdio.h>
#include <stdint.h>

// 11 -> decimal
// 0b11 -> binary
// 0x11 -> hexadecimal
// 011 -> octal


// 0b00010000
// 0x10
// 
// b | 0x10
// b | 0b00010000
// b | (1 << 4)
// Set the 4th bit of b
//
// check if the 4th of bit of b is 0 or 1
// (b >> 4) & 1

#define N_BITS 32

uint32_t reverse_bits(uint32_t w) {
    uint32_t res = 0;
    // loop over i from N_BITS - 1 to 0
    // set NBITS - 1 - i to be the same number
    for (int32_t i = N_BITS - 1; i >= 0; i--) {
        uint32_t dest_i = N_BITS - 1 - i;
        // calculate the ith bit in w

        // i goes from 7 to 0
        // 11000000 >> i
        // 11000000 >> 7 == 00000001 & 1 == 00000001 == 1
        uint32_t bit = (w >> i) & 1u; // bit == 0 if ith bit is 0, 1 if ith bit is 1

        // set the dest_ith bit in the res to be the same thing
        res = res | (bit << dest_i); // set dest_ith bit
    }

    return res;
}

// 0x000000ff 32 bit number
// 0xff000000
//
// 0b00000000000000000000000011111111
// 0b11111111000000000000000000000000

int main(void) {
    printf("%08x\n%08x\n", 0xff, reverse_bits(0xff));
    printf("%d\n", (int16_t)0b1111111111111111);
}
