/**
 * Simplic Compiler 2023, Nachat Kaewmeesang
 * aofs-assembler.h is the implementation file for the simplic assembler. It contains parsers that
 * converts simplic assembly instructions (in string) into binary code (in uint16_t). 
 * All functions of simplic assembler is prefixed with aof_ for clarity.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../aofs-assembler.h"

void aof_asm_fmterror(char *mnem, char *message){
    snprintf(g_aofs_errormsg, 256, "Simplic Assembly Error: '%s'\n%s", mnem, message);
}

bool aof_HEX_tobinary(char *hexliteral, uint8_t size, uint16_t* bincode){

    // just handle only 2 digits hex literal, for simplicity
    if (hexliteral[2] != '\0') {
        aof_asm_fmterror(hexliteral, "Only support 2 digits hex literal, with no prefix");
        return false;
    }

    // convert to int, while also handling invalid (bad hex) characters
    char *badhex;
    *bincode = (uint16_t)strtol(hexliteral, &badhex, 16);
    if (*badhex != '\0'){
        aof_asm_fmterror(hexliteral, "Invalid hex literal.");
        return false;
    }

    // making sure that the input value is not too big
    if (*bincode > size) {
        aof_asm_fmterror(hexliteral, "Hex literal value too large.");
        return false;
    }

    return true;
}

bool aof_CND_tobinary(char *asmline, uint16_t *bincode)
{
    // firstly, read the instruction
    // CND Instructions handle MOV and CNA instructions
    if (strncmp(asmline, "MOV", 3) == 0) *bincode = 0x0000;
    else if (strncmp(asmline, "CNA", 3) == 0) *bincode = 0x1000;
    else {
        aof_asm_fmterror(asmline, "CND parser expected either a MOV or INS instruction");
        return false;
    }

    return true;
}
