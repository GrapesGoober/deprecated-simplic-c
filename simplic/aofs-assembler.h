/**
 * Simplic Compiler 2023, Nachat Kaewmeesang
 * aofs-assembler.h is the header file for the simplic assembler. It contains parsers that
 * converts simplic assembly instructions (in string) into binary code (in uint16_t). 
 * All assembly parser functions are prefixed with aof_ for clarity.
*/

#include <stdint.h>
#include <stdbool.h>

/** 
 * A global variable that contains assembly syntax error and output error messages.
*/
char g_aofs_errormsg[255];

/** 
 * Formats an assembly error message to `g_aofs_errormsg`.
 * Arguments:
 * - `char *token` Null terminated string containing the token of the problem.
 * - `char *message` Null terminated string containing the message.
*/
void aof_asm_fmterror(char *token, char *message);

/** 
 * Parses an entire line of assembly instruction to binary. 
 * Arguments:
 * - `char *asmline` Null terminated string containing an input line of assembly.
 * 
 * Returns: Either a 16-bit binary code instruction if successful or `0xFFFF` for failure.
 *
 * Notes: 
 * - Error message will be put to `g_aofs_errormsg` upon error.
 * - Instruction `NOR PC PC PC` is considered as invalid, and will be put to `g_aofs_errormsg`
*/
uint16_t aof_asmline_tobinary(char *asmline);

/** 
 * Parses an literal token to binary.
 * Arguments:
 * - `char *asmline` Null terminated string for input token.
 * - `uint16_t` Literal size restriction. Maximum size is 256 or 1 byte.
 * 
 * Returns: Either the binary code value if successful or `0xFFFF` for failure.
 *
 * Note: Error message will be put to `g_aofs_errormsg` upon error.
*/
uint16_t aof_literal_tobinary(char *literal_tok, uint8_t size)
