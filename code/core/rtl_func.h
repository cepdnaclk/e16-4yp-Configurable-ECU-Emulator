#ifndef __RTL_FUNCTIONS_H
#define __RTL_FUNCTIONS_H

#include <stdint.h>

class rtl_functions
{
public:
    uint32_t sign_ext(uint32_t x);
    uint32_t ssov(uint32_t x, uint32_t y);
};

#endif