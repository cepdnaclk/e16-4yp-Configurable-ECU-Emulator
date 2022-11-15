#include "rtl_func.h"

uint32_t rtl_functions::sign_ext(uint32_t x)
{
    uint32_t sign = (x & 0x00100000) >> 20;
    if (sign == 1)
    {
        x = x | 0xFFF00000;
    }
    else
    {
        x = x & 0x000FFFFF;
    }
    return x;
}

uint32_t rtl_functions::ssov(uint32_t x, uint32_t y)
{
    uint32_t max_pos = (1 << (y - 1)) - 1;
    uint32_t max_neg = -(1 << (y - 1));
    return ((x > max_pos) ? max_pos : ((x < max_neg) ? max_neg : x));
}