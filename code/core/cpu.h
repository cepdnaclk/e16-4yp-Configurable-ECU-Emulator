#ifndef __CPU_H__
#define __CPU_H__

#include <stdint.h>
#include <vector>
#include "rtl_func.h"
#include "memory.h"

class cpu
{

public:
    // status registers
    uint32_t PC = 0; // program counter
    uint32_t PSW;    // program status word
    rtl_functions rtl;

    /*
        Field Bits Type Description
        C       31  rw  Carry
        V       30  rw  Overflow
        SV      29  rw  Sticky Overflow
        AV      28  rw  Advance Overflow
        SAV     27  rw  Sticky Advance Overflow
        RES[26:24]      -Reserved

    */
    uint32_t PCXI; // previous context information

    // general purpose registers
    uint32_t D[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // data registers
    uint32_t A[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // address registers

    void instruction_decode(uint32_t instruction);
    void execute(uint8_t opcode, uint32_t instruction);
    void execute_memory_instructions(uint8_t opcode, uint32_t instruction);

    // memory
    memory mem;
};

#endif
