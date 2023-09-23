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
 * Parses an assembly mnemonic token to binary by comparing to `mnemset`.
 * Arguments:
 * - `char *mnemtok` Null terminated string for input token.
 * - `const char *mnemset` Null delimited string for the set of mnemonic tokens to compare to.
 * Note that the string uses double null character for termination.
 * - `int shift` Left shift distance for the specific result code.
 * 
 * Returns `uint16_t`, either 
 * - Binary code equivalence, if successful,
 * - or `0xFFFF` value, if failure.
 *
 * Note: Error message will be put to `g_aofs_errormsg` upon failure.
*/
uint16_t aofs_mnemtok_tobinary(char *mnemtok, const char *mnemset, int shift);

/** 
 * Parses an assembly immediate-value token to binary.
 * Arguments:
 * - `char *immtok` Null terminated string for input token.
 * - `int bitsize` The max number of bits the value can be.
 * 
 * Returns `uint16_t`, either 
 * - Binary code equivalence, if successful,
 * - or `0xFFFF` value, if failure.
 *
 * Note: Error message will be put to `g_aofs_errormsg` upon failure.
*/
uint16_t aofs_immtok_tobinary(char *immtok, int bitsize);

