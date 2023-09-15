// Simplic Compiler 2022, Nachat Kaewmeesang
// aofs-assenbler.h is the header file for the simplic assembler, which converts 
// simplic assembly instructions (in string) into binary code (in uint16_t). 
// All functions of simplic assembler is prefixed with aofs_ for clarity
#include <stdint.h>

// Parses a single line of any assembly instruction to binary
uint16_t aofs_ANY_tobinary(char *asmLine);

// Parses a hexadecimal literal to binary code with size restriction (caller must do appropriate shift left)
uint16_t aofs_HEX_tobinary(char *hexliteral, uint8_t size);

// Parses a register mnemonic to binary code (caller must do appropriate shift left)
uint16_t aofs_REG_tobinary(char *mnem);

// Parses an entire line of MOV or MVS assembly instruction to binary code
// These two instructions are collectively called "conditional" instructions, or CND
uint16_t aofs_CND_tobinary(char *asmline);

// Parses an entire line of MOV or MVS assembly instruction to binary code
// These two instructions are collectively called "memory" instructions, or MEM
uint16_t aofs_MEM_tobinary(char *asmline);

// Parses an entire line of SFT assembly instruction to binary code
// This instruction has a peculiar syntax, so it gets its own function
uint16_t aofs_SFT_tobinary(char *asmline);

// Parses an entire line of ALU assembly instruction to binary code
// The ALU instructions includes ADD, SUB, MUL, LML, DIV, MOD, AND, ORR, XOR, NOR
uint16_t aofs_ALU_tobinary(char *asmline);
