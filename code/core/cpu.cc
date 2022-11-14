#include "isa.h"
#include "cpu.h"
#include <iostream>

void cpu::instruction_decode(uint32_t instruction)
{
    // decode instruction
    // call execute
    std::cout << "hello world" << std::endl;
}

void cpu::execute(uint8_t opcode)
{
    if (opcode == INST_ABS)
    {
        std::cout << "instruction abs";
    }

    std::cout << "instruction abs";
}

int main()
{
    cpu cpu;
    cpu.instruction_decode(0);
    cpu.execute(0);
    return 0;
}