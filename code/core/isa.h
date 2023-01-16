#ifndef __ISA_H__
#define __ISA_H__

#define INST_AND_RC 0x8F
#define INST_AND_RR 0x0F
#define INST_AND_SC 0x16
#define INST_AND_SR 0x26

#define INST_ABS 0x0B
#define INST_ABSDIF_CONST 0x8B
#define INST_BISR 0xAD

//load store instructions
#define INST_STA1 0xA5



//opcodes ADD instructions
#define INST_ADD 0x8B
#define INST_ADDreg 0x0B
#define INST_ADD.A 0x01
#define INST_ADD.B 0x02
#define INST_ADD.H 0x03
#define INST_ADDC 0x8B
#define INST_ADDCreg 0x0B
#define INST_ADDI 0x1B
#define INST_ADDIH 0x9B
#define INST_ADDIH.A 0x11
#define INST_ADDS 0x8B
#define INST_ADDSreg 0x0B
#define INST_ADDS.H 0x0B
#define INST_ADDS.HU 0x0B
#define INST_ADDS.U 0x8B
#define INST_ADDS.Ureg 0x0B
#define INST_ADDSC.A 0x0B
#define INST_ADDSC.AT 0x01
#define INST_ADDX 0x8B
#define INST_ADDXreg 0x0B


//opcodes for instructions starting from "N"
#define INST_NAND 0x8F

//opcodes for instructions starting from "J"
#define INST_JMP 0x1D
#define INST_JA 0x9D
#define INST_JEQ 0xDF
#define INST_JEQ1 0x5F
#define INST_JEQA 0x7D
#define INST_JGE 0xFF
#define INST_JGE1 0x7F
#define INST_JGEU 0xFF

#endif