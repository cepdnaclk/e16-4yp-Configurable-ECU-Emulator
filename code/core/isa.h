#ifndef __ISA_H__
#define __ISA_H__

#define INST_AND_RC 0x8F
#define INST_AND_RR 0x0F
#define INST_AND_SC 0x16
#define INST_AND_SR 0x26

#define INST_ABS 0x0B
#define INST_ABSDIF_CONST 0x8B
#define INST_BISR 0xAD

// load store instructions
#define INST_STA1 0xA5

// opcodes for instructions starting from "N"
#define INST_NAND 0x8F

// opcodes for instructions starting from "J"
#define INST_JMP 0x1D
#define INST_JA 0x9D
#define INST_JEQ 0xDF
#define INST_JEQ1 0x5F
#define INST_JEQA 0x7D
#define INST_JGE 0xFF
#define INST_JGE1 0x7F
#define INST_JGEU 0xFF

// opcodes for instructions starting from "M"
#define INST_MUL 0x73
#define INST_MOV 0x3B
#define INST_MOV2 0x0B

// opcodes for instructions starting from "S"
#define INST_SUB 0x0B

#endif