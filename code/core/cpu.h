#ifndef __CPU_H__
#define __CPU_H__

#include <stdint.h>
#include <vector>

class cpu
{

public:
    // status registers
    uint32_t PC;   // program counter
    uint32_t PSW;  // program status word
    uint32_t PCXI; // previous context information

    // general purpose registers
    uint32_t D[16]; // data registers
    uint32_t A[16]; // address registers

    uint8_t opcode = 10;
    void instruction_decode(uint32_t instruction);
    void execute(uint8_t opcode);
};

#endif
