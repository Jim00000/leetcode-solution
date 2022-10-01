#include "solution.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define IS_INT32_NEGATIVE(VAL) ((VAL & 0x80000000) >> 31)

uint32_t division_hardware_simulation(int32_t dividend, int32_t divisor)
{
    // handle special case
    if(dividend == -2147483648 && divisor == -1)
        return 2147483647;

    union {
        struct
        {
            uint32_t quotient;
            uint32_t remainder;
        };
        uint64_t Int64;
    } division = {.Int64 = llabs(dividend) << 1};

    uint8_t count = 32;
    const bool negative = IS_INT32_NEGATIVE(dividend) ^ IS_INT32_NEGATIVE(divisor);

    if(IS_INT32_NEGATIVE(divisor))
        divisor = llabs(divisor);

    while (count > 0)
    {
        const int32_t diff = division.remainder - divisor;
        if (IS_INT32_NEGATIVE(diff))
            division.Int64 <<= 1;
        else
        {
            division.remainder = diff;
            division.Int64 <<= 1;
            division.quotient |= 1;
        }
        count--;
    }

    return negative ? -division.quotient : division.quotient;
}

int32_t divide(int32_t dividend, int32_t divisor)
{
    return division_hardware_simulation(dividend, divisor);
}