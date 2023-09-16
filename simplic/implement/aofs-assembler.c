// Simplic Compiler 2022, Nachat Kaewmeesang
// sasm.c is the implementation file for the simplic assembler, which converts 
// simplic assembly instructions (in string) into binary code (in uint16_t). 
// All functions of simplic assembler is prefixed with sasm_ for clarity
#include <stdio.h>
#include "../aofs-assembler.h"

uint16_t sasm_ANY_tobinary(char *asmLine);

uint16_t sasm_HEX_tobinary(char *hexliteral, uint8_t size);

uint16_t sasm_REG_tobinary(char *mnem);

uint16_t sasm_CND_tobinary(char *asmline);

uint16_t sasm_MEM_tobinary(char *asmline);

uint16_t sasm_SFT_tobinary(char *asmline);

uint16_t sasm_ALU_tobinary(char *asmline);