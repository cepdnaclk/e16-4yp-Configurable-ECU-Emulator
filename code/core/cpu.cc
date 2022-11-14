#include "isa.h"
#include "cpu.h"
#include <iostream>

void cpu::instruction_decode(uint32_t instruction)
{
    // decode instruction
    // call execute
    std::cout << "hello world" << std::endl;
}

void cpu::execute(uint8_t opcode, u_int32_t instruction)
{

    if (opcode == INST_ABS)
    {

        int b = (instruction & 0x0000F000) >> 12; // read instruction[12:15]
        int c = (instruction & 0xF0000000) >> 28; // read instruction[28:31]
        uint32_t abs_result = (D[b] >= 0) ? D[b] : (0 - D[b]);
        D[c] = abs_result;

        // update PSW
        uint32_t overflow = (abs_result > 7FFFFFFF) || (abs_result < -80000000);
        // update the PSW.V bit
        PSW = overflow ? PSW | (1 << 30) : PSW & ~(1 << 30);
        // update the PSW.SV bit
        if (overflow)
        {
            PSW = PSW | (1 << 29);
        }

        // update the PSW.AV bit
        uint32_t advanced_overflow = (abs_result & 0x80000000) ^ (abs_result & 0x40000000); // result[31] ^ result[30];
        PSW = advanced_overflow ? PSW | (1 << 28) : PSW & ~(1 << 28);
        // update the PSW.SAV bit
        if (advanced_overflow)
        {
            PSW = PSW | (1 << 27);
        }
    }
}

int main()
{
    cpu cpu;
    cpu.instruction_decode(0);
    cpu.execute(0);
    return 0;
}