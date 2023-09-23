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

uint16_t aofs_asmline_tobinary(char *asmline)
{
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

    // this function is not meant to parse comments
    if (strpbrk(asmline, '#') != NULL) {
        snprintf(g_aofs_errormsg, 256, "BAD CALL: '%s' - Can't parse comments.", asmline);
        return 0xFFFF;
    }

    // get a capitalized copy of the input token
    // note: copy the null termination char too (hence + 1 size)
    const char *delim = " \t\f\r\v";

    strpbrk(asmline, delim);

    uint16_t bincode = aofs_mnemtok_tobinary(asmline, instructions_set, 12);
    printf("Result: %x\n", bincode);
    printf("%s", g_aofs_errormsg);

    // tokenize string using strpbrk instead of strtok

    // get instr token & bincode
    // get rd

    // switch case on each instr type, parse each token
    //          if (aofs_mnemtok_tobinary( ... )) {
    //              mybincode += bincode << ... ;
    //          }
    //          else aofs_asm_fmterror(tok, ... );

    return 0xFFFF;
}

uint16_t aofs_mnemtok_tobinary(char *mnemtok, const char *mnemset, int shift) {
    // Parse assembly mnemonic by comparing to a mnemonic set

    // start looping to find match
    uint16_t iter = 0;
    while (mnemset[0] != '\0'){
        // check for matching & return with shift
        if (strcmp(mnemtok, mnemset) == 0) return iter << shift;
        // move on to the next token
        while(mnemset[0] != '\0') mnemset++;
        mnemset++;
    }
    
    // is not found
    snprintf(g_aofs_errormsg, 256, "Assembly Error: '%s' - Invalid mnemonic.", mnemtok);
    return 0xFFFF;
}

uint16_t aofs_immtok_tobinary(char *immtok, int bitsize){
    // Parse immediate value using strtol and some bitmasking
    char *invalid_char;
    int number = strtol(immtok, &invalid_char, 0);

    // Handle invalid character issues
    if (*invalid_char != '\0'){
        snprintf(g_aofs_errormsg, 256, "Assembly Error: '%s' - Invalid literal.", immtok);
        return 0xFFFF;
    }

    // Check size, do bitmask, and return value
    uint16_t bitmask = (1u << bitsize) - 1;
    if (abs(number) > bitmask) {
        snprintf(g_aofs_errormsg, 256, "Assembly Error: '%s' - Literal too large.");
        return 0xFFFF;
    }
    return (uint16_t)number & bitmask;

}
