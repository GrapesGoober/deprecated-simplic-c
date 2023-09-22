/**
 * Simplic Compiler 2023, Nachat Kaewmeesang
 * aofs-assembler.h is the header file for the simplic assembler. It contains parsers that
 * converts simplic assembly instructions (in string) into binary code (in uint16_t). 
 * All assembly parser functions are prefixed with aofs_ for clarity.
*/

#include <stdint.h>
#include <stdbool.h>

/** 
 * A global variable that contains assembly syntax error and output error messages.
*/
char g_aofs_errormsg[255];

/** 
 * Enum type to tell the function `aofs_mnemtok_tobinary` and `aofs_immtok_tobinary` what mnemonic type to parse
*/
enum aofs_asmtok_type {
    AOFS_IMMTOK_IMM4, AOFS_IMMTOK_IMM8, // Immediate-Value tokens of either 8-bits or 4-bits
    AOFS_MNEMTOK_INSTR, // Instruction token
    AOFS_MNEMTOK_RD, AOFS_MNEMTOK_RN, AOFS_MNEMTOK_RM, // Register token with various positions
    AOFS_MNEMTOK_CND, // Condition token used for MOVs and CNAs
    AOFS_MNEMTOK_SOP, // Shift Operation token used by SFTs
};


/** 
 * Formats an assembly error message to `g_aofs_errormsg`.
 * Arguments:
 * - `char *token` Null terminated string containing the token of the problem.
 * - `char *message` Null terminated string containing the message.
*/
void aofs_asm_fmterror(char *token, char *message);

/** 
 * Parses an entire line of assembly instruction to binary. 
 * Arguments:
 * - `char *asmline` Null terminated string containing an input line of assembly.
 * 
 * Returns `uint16_t`, either 
 * - Binary code instruction, if successful,
 * - or `0xFFFF` value, if failure.
 *
 * Notes: 
 * - Error message will be put to `g_aofs_errormsg` upon error.
 * - Instruction `NOR PC PC PC` is reserved for error message.
 *  It is considered invalid and will be put to `g_aofs_errormsg`
*/
uint16_t aofs_asmline_tobinary(char *asmline);

/** 
 * Gets an appropriate set of mnemonic tokens. Used by `aofs_mnemtok_tobinary` parser.
 * Arguments:
 * - `char **mnemset` Pointer to output mnemonic set as a null-delimited string.
 * - `enum aofs_asmtok_type type` Type of mnemonic set. Enum members are prefixed with `AOFS_MNEMTOK`.
 * 
 * Returns `int`, either 
 * - `> 0` for the size of the set
 * - or `-1` value, for failure.
 *
 * Notes: 
 * - Error message will be put to `g_aofs_errormsg` upon error.
*/
int aofs_get_mnemset(const char **mnemset, enum aofs_asmtok_type type);

/** 
 * Parses an assembly mnemonic token to binary.
 * Arguments:
 * - `char *mnemtok` Null terminated string for input token.
 * - `enum aofs_asmtok_type type` Type of token to parse. Enum members are prefixed with `AOFS_IMMTOK`.
 * 
 * Returns `uint16_t`, either 
 * - Binary code equivalence, if successful,
 * - or `0xFFFF` value, if failure.
 *
 * Note: Error message will be put to `g_aofs_errormsg` upon failure.
*/
uint16_t aofs_mnemtok_tobinary(char *mnemtok, enum aofs_asmtok_type type);

/** 
 * Parses an assembly immediate-value token to binary.
 * Arguments:
 * - `char *immtok` Null terminated string for input token.
 * - `enum aofs_asmtok_type type` Type of immediate token to parse,
 *  either `AOFS_IMMTOK_IMM4` or `AOFS_IMMTOK_IMM8` are allowed
 * 
 * Returns `uint16_t`, either 
 * - Binary code equivalence, if successful,
 * - or `0xFFFF` value, if failure.
 *
 * Note: Error message will be put to `g_aofs_errormsg` upon failure.
*/
uint16_t aofs_immtok_tobinary(char *immtok, enum aofs_asmtok_type type);

