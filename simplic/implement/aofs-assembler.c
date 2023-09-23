/**
 * Simplic Compiler 2023, Nachat Kaewmeesang
 * aofs-assembler.h is the implementation file for the simplic assembler. It contains parsers that
 * converts simplic assembly instructions (in string) into binary code (in uint16_t). 
 * All functions of simplic assembler is prefixed with aofs_ for clarity.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../aofs-assembler.h"

void aofs_asm_fmterror(char *mnem, char *message){
    snprintf(g_aofs_errormsg, 256, "Assembly Syntax Error: '%s' - %s", mnem, message);
}

uint16_t aofs_asmline_tobinary(char *asmline)
{
    // tokenize string

    // get instr token & bincode
    // get rd

    // switch case on each instr type, parse each token
    //          if (aofs_mnemtok_tobinary( ... )) {
    //              mybincode += bincode << ... ;
    //          }
    //          else aofs_asm_fmterror(tok, ... );

    return 0xFFFF;
}

uint16_t aofs_immtok_tobinary(char *immtok, enum aofs_asmtok_type type){
    // Parse immediate value using strtol and some bitmasking

    // firstly: strtol to int and handle invalid characters
    char *invalid_char;
    int number = strtol(immtok, &invalid_char, 0);

    // handle invalid character issues
    if (*invalid_char != '\0'){
        aofs_asm_fmterror(immtok, "Invalid literal.");
        return 0xFFFF;
    }
    
    // check size, do bitmask, and return value
    if (type == AOFS_IMMTOK_IMM4) {
        if (abs(number) > 15) aofs_asm_fmterror(immtok, "Literal too large for 4 bits.");
        return (uint16_t)number & 0xF;
    }
    if (type == AOFS_IMMTOK_IMM8) {
        if (abs(number) > 255) aofs_asm_fmterror(immtok, "Literal too large for 8 bits.");
        return (uint16_t)number & 0xFF;
    }

    // handle bad enum type input (although it should not happen anyways)
    aofs_asm_fmterror("BAD CALL", "Undefined immediate token type");
    return 0xFFFF;
}

uint16_t aofs_mnemtok_tobinary(char *mnemtok, enum aofs_asmtok_type type){
    // Parse assembly mnemonic by comparing to a mnemonic set

    // get a capitalized copy of the input token
    // note: copy the null termination char too (hence + 1 size)
    char mnemtok_copy[strlen(mnemtok) + 1];
    for (int char_i = 0; char_i < sizeof(mnemtok_copy); char_i++) {
        mnemtok_copy[char_i] = toupper(mnemtok[char_i]);
    }

    // select the appropriate set of tokens to compare this to
    // note that aofs_get_mnemset will handle undefined aofs_asmtok_type itself
    const char *mnemset;
    int mnemset_size = aofs_get_mnemset(&mnemset, type);
    if (mnemset_size == -1) return 0xFFFF;

    // start looping to find match
    for (int i = 0; i < mnemset_size; i++){
        if (strcmp(mnemtok_copy, mnemset) == 0) {
            // match found, return bincodes (do shifting in case of register)
            if (type == AOFS_MNEMTOK_RD) 
                return (uint16_t)i << 8;
            else if (type == AOFS_MNEMTOK_RN) 
                return (uint16_t)i << 4;
            else 
                return (uint16_t)i;
        }

        while(mnemset[0] != '\0') mnemset++;
        mnemset++;
    }
    
    // is not found
    aofs_asm_fmterror(mnemtok, "Unrecognized token");
    return 0xFFFF;
}

int aofs_get_mnemset(const char **mnemset, enum aofs_asmtok_type type)
{
    // switch-case for each aofs_asmtok_type, then return the correct string

    // Instruction mnemonic tokens set
    static const char *instructions_set = 
        "MOV\0CNA\0LDR\0STR\0MVS\0SFT\0ADD\0SUB\0"
        "MUL\0LML\0DIV\0MOD\0AND\0ORR\0XOR\0NOR\0";
    // Register mnemonic tokens set
    static const char *registers_set = 
        "ZR\0R1\0R2\0R3\0R4\0R5\0R6\0R7\0"
        "R8\0R9\0RA\0RB\0SP\0BR\0LR\0PC\0";
    // Conditional mnemonic tokens set used by MOV and CNA
    static const char *conditionals_set = 
        "ZS\0ZC\0CS\0CC\0NS\0NC\0VS\0VC\0"
        "SM\0HI\0LT\0GT\0LE\0GE\0FC\0AL\0";
    // Shift Opertation tokens set used by SFT instruction
    static const char *shiftop_set =
        "LSL\0LSR\0ASR\0ROR\0";

        // imm-lsl imm-lsr imm-asl imm-asr imm-rol imm-ror
        // reg-lsl reg-lsr reg-asl reg-asr reg-rol reg-ror

    switch (type) {
        case AOFS_MNEMTOK_INSTR: 
            *mnemset = instructions_set; return 16;
        case AOFS_MNEMTOK_RD: case AOFS_MNEMTOK_RN: case AOFS_MNEMTOK_RM: 
            *mnemset = registers_set;  return 16;
        case AOFS_MNEMTOK_CND:
            *mnemset = conditionals_set; return 16;
        case AOFS_MNEMTOK_SOP:
            *mnemset = shiftop_set; return 4;
        // Handle invalid enum... should not happen anyways
        default:
            aofs_asm_fmterror("BAD CALL", "Undefined mnemonic token type.");
            return -1;
    }
}
