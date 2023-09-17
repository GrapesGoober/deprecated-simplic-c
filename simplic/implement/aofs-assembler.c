/**
 * Simplic Compiler 2023, Nachat Kaewmeesang
 * aofs-assembler.h is the implementation file for the simplic assembler. It contains parsers that
 * converts simplic assembly instructions (in string) into binary code (in uint16_t). 
 * All functions of simplic assembler is prefixed with aof_ for clarity.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../aofs-assembler.h"

void aof_asm_fmterror(char *mnem, char *message){
    snprintf(g_aofs_errormsg, 256, "Simplic Assembly Error: '%s'\n%s", mnem, message);
}

bool aof_literal_tobinary(char *literal, uint8_t size, uint16_t* bincode){

    // convert to int, while also handling invalid characters
    char *invalid_char;
    int converted_value = strtol(literal, &invalid_char, 0);
    if (*invalid_char != '\0'){
        aof_asm_fmterror(literal, "Invalid literal.");
        return false;
    }

    // making sure that the input value is not too big
    if (abs(converted_value) > size) {
        char fmt_errmsg[40];
        snprintf(fmt_errmsg, 40, "Literal value too large for size = %i", size);
        aof_asm_fmterror(literal, fmt_errmsg);
        return false;
    }

    // do appropriate shift-right if this is a negative value
    *bincode = (uint16_t)converted_value;
    
    // do appropriate shift-right shinanigans if this is a negative value
    // i.e. trying to replace left-side bits to zero
    // this essentially reduce down the 16 bit int onto the size appropriate for the "size"
    if (converted_value < 0) {
        for (int i = 1; *bincode > size; i++)
        {
            *bincode <<= i;
            *bincode >>= i;
        }
    }
    return true;
}

bool aof_REG_tobinary(char *reg_mnemonic, uint16_t* bincode){

}

bool aof_CND_tobinary(char *asmline, uint16_t *bincode)
{
    // make a copy of asm line so that we can tokenize safely
    char asmline_copy[strlen(asmline)];
    strcpy(asmline_copy, asmline);

    // firstly, read the instruction
    // CND Instructions handle MOV and CNA instructions
    char *instr = strtok(asmline_copy, " ");
    if (strncmp(instr, "MOV", 3) == 0) *bincode = 0x0000;
    else if (strncmp(instr, "CNA", 3) == 0) *bincode = 0x1000;
    else {
        aof_asm_fmterror(asmline, "CND parser expected either a MOV or CNA instruction");
        return false;
    }

    return true;
}
