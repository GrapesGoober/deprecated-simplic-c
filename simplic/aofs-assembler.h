/**
 * Simplic Compiler 2023, Nachat Kaewmeesang
 * aofs-assembler.h is the header file for the simplic assembler. It contains parsers that
 * converts simplic assembly instructions (in string) into binary code (in uint16_t). 
 * All functions of simplic assembler is prefixed with aofs_ for clarity.
*/

#include <stdint.h>
#include <stdbool.h>

/** 
 * A global variable that contains error messages for all AOFs.
 * This is only used for assembly syntax errors and hexfile errors.
*/
char g_aofs_error_msg[256];

/** 
 * Writes an assembly error message to `g_aofs_error_msg`.
 * Arguments:
 * - `char *mnem` Null terminated string containing the mnemonic(s) of the problem.
 * - `char *message` Null terminated string containing the message.
*/
void aofs_asm_error(char *mnem, char *message);

/** 
 * Parses an entire line of assembly instruction to binary. 
 * Arguments:
 * - `char *asmline` Null terminated string containing a line of assembly.
 * - `uint16_t* bincode` The pointer to write the result binary code to.
 * 
 * Returns: `true` if success, `false` otherwise. 
 * Note: if returns `false`, the error messages can be found in `g_aofs_error_msg`.
*/
bool aofs_ASM_tobinary(char *asmline, uint16_t *bincode);

/** 
 * Parses a hexadecimal literal to binary code (with size restriction)
 * Arguments:
 * - `char *hex_literal` Null terminated string containing 2 digits of hex.
 * - `uint8_t size` Size restriction, in number of bits.
 * - `uint16_t* bincode` The pointer to write the result binary code to.
 * 
 * Returns: `true` if success, `false` otherwise. 
 * 
 * Notes:
 * - The caller must do appropriate shift left to place the binary code at the right location
 * - If returns `false`, caller should disregard `bincode` and check `g_aofs_error_msg`.
*/
bool aofs_HEX_tobinary(char *hex_literal, uint8_t size, uint16_t *bincode);

/** 
 * Parses a register mnemonic to binary code
 * Arguments:
 * - `char *reg_mnemonic` Null terminated string containing 2 digits of register mnemonic.
 * - `uint16_t* bincode` The pointer to write the result binary code to.
 * 
 * Returns: `true` if success, `false` otherwise. 
 * 
 * Notes:
 * - The caller must do appropriate shift left to place the binary code at the right location
 * - If returns `false`, caller should disregard `bincode` and check `g_aofs_error_msg`.
*/
bool aofs_REG_tobinary(char *reg_mnemonic, uint16_t* bincode);

/** 
 * Parses conditional assembly instructions (`MOV` or `CNA`) to binary code.
 * Arguments:
 * - `char *asmline` Null terminated string containing a line of assembly.
 * - `uint16_t* bincode` The pointer to write the result binary code to.
 * 
 * Returns: true if success, false otherwise.
 * 
 * Notes: 
 * - Assembly arguments are in format `Rd Rn CND`. 
 * - If returns `false`, caller should disregard `bincode` and check `g_aofs_error_msg`.
*/
bool aofs_CND_tobinary(char *asmline, uint16_t* bincode);

bool aofs_MEM__tobinary(char *asmline, uint16_t* bincode);

bool aofs_SFT__tobinary(char *asmline, uint16_t* bincode);

bool aofs_ALU__tobinary(char *asmline, uint16_t* bincode);
