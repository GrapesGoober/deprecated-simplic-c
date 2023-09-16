/**
 * Simplic Compiler 2023, Nachat Kaewmeesang
 * aofs-assembler.h is the implementation file for the simplic assembler. It contains parsers that
 * converts simplic assembly instructions (in string) into binary code (in uint16_t). 
 * All functions of simplic assembler is prefixed with aofs_ for clarity.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../aofs-assembler.h"

void aofs_asm_error(char *mnem, char *message){
    snprintf(g_aofs_error_msg, 256, "Simplic Assembly Error: '%s'\n%s", mnem, message);
}

bool aofs_HEX_tobinary(char *hexliteral, uint8_t size, uint16_t* bincode){

    if (hexliteral[2] != '\0') {
        aofs_asm_error(hexliteral, "Only support 2 digits hex literal, with no prefix");
        return false;
    }

    char *badhex;
    *bincode = (uint16_t)strtol(hexliteral, &badhex, 16);
    if (*badhex != '\0'){
        aofs_asm_error(hexliteral, "Invalid hex literal.");
        return false;
    }

    if (*bincode > size) {
        aofs_asm_error(hexliteral, "Hex literal value too big.");
        return false;
    }

    return true;
}

bool aofs_CND_tobinary(char *asmline, uint16_t *bincode)
{
    // firstly, read the instruction
    // CND Instructions handle MOV and INS instructions
    if (strncmp(asmline, "MOV", 3) == 0) *bincode = 0x0000;
    else if (strncmp(asmline, "INS", 3) == 0) *bincode = 0x1000;
    else aofs_asm_error(asmline, "CND parser expected either a MOV or INS instruction");

    return true;
}
