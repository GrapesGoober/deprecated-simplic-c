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

const char REG_TOKENS[16][3] = {
    "ZR", "R1", "R2", "R3", "R4", "R5", // General Purpose Registers
    "R6", "R7", "R8", "R9", "RA", "RB", 
    "SP", // Stack Pointer (points to current top of stack)
    "BR", // Buffer Register (for jumps, memory address, literal assignments etc)
    "LR", // Link Register (PC's last location to return to, after finished a call)
    "PC"  // Program Counter (points to the current instruction to read)
};

void aof_asm_fmterror(char *mnem, char *message){
    snprintf(g_aofs_errormsg, 256, "Assembly Syntax Error: '%s' - %s", mnem, message);
}

uint16_t aof_literal_tobinary(char *literal_tok, uint8_t size){

    // convert to int, while also handling invalid characters
    char *invalid_char;
    int converted_value = strtol(literal_tok, &invalid_char, 0);
    if (*invalid_char != '\0'){
        aof_asm_fmterror(literal_tok, "Invalid literal.");
        return 0xFFFF;
    }

    // making sure that the input value is not too big
    if (abs(converted_value) > size) {
        char fmt_errmsg[40];
        snprintf(fmt_errmsg, 40, "Literal value too large for size = %i", size);
        aof_asm_fmterror(literal_tok, fmt_errmsg);
        return 0xFFFF;
    }

    // assign, but need to check for negative value
    uint16_t bincode = (uint16_t)converted_value;
    
    // do appropriate shift-right shinanigans if this is a negative value
    // i.e. trying to replace left-side bits to zero
    // this essentially reducing down the 16 bit int onto the size appropriate for the "size"
    if (converted_value < 0) {
        for (int i = 1; *bincode > size; i++)
        {
            bincode <<= i;
            bincode >>= i;
        }
    }
    return bincode;
}

uint16_t aof_asmline_tobinary(char *asmline)
{
    // tokenize string

    // get instr token & bincode
    // get rd

    // switch case on each instr type, parse each token
    //          if (aof_asmtok_tobinary( ... )) {
    //              mybincode += bincode << ... ;
    //          }
    //          else aof_asm_fmterror(tok, ... );

    return 0xFFFF;
}

uint16_t aof_asmtok_tobinary(char *asmtok, uint8_t shift){
    // this works by iteratively comparing string to an array of registers
    // to see if any of them match
    
    // first, get a capitalized copy of the input token
    // note: copy the null termination char too (hence + 1 size)
    char reg_tok_toupper[strlen(reg_tok) + 1];
    for (int char_i = 0; char_i < sizeof(reg_tok_toupper); char_i++) {
        reg_tok_toupper[char_i] = toupper(reg_tok[char_i]);
    }

    // start looping to find match
    for (int reg_i = 0; reg_i < 16; reg_i++) {
        if (strcmp(reg_tok_toupper, REG_TOKENS[reg_i]) == 0) {
            // match found, return hex value with proper shift left
            return (uint16_t)reg_i << shift;
        }
    }

    // is not found
    aof_asm_fmterror(reg_tok, "Unrecognized token");
    return 0xFFFF;
}

