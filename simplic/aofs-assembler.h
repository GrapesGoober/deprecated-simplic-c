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
char g_aofs_errormsg[256];

/** 
 * Formats an assembly error message to `g_aofs_errormsg`.
 * Arguments:
 * - `char *mnem` Null terminated string containing the mnemonic(s) of the problem.
 * - `char *message` Null terminated string containing the message.
*/
void aof_asm_fmterror(char *mnem, char *message);

/** 
 * Parses an entire line of assembly instruction to binary. 
 * Arguments:
 * - `char *asmline` Null terminated string containing a line of assembly.
 * - `uint16_t* bincode` The pointer to write the result binary code to.
 * 
 * Returns: `true` if success, `false` otherwise. 
 * Note: if returns `false`, the error messages can be found in `g_aofs_errormsg`.
*/
bool aof_ASM_tobinary(char *asmline, uint16_t *bincode);

/** 
 * Parses a hexadecimal literal to binary code (with size restriction)
 * Arguments:
 * - `char *hex_literal` Null terminated string containing 2 digits of hex.
 * - `uint8_t size` Restrict how big the value of hex literal be. Will return false if too large.
 * - `uint16_t* bincode` The pointer to write the result binary code to.
 * 
 * Returns: `true` if success, `false` otherwise. 
 * 
 * Notes:
 * - The caller must do appropriate shift left to place the binary code at the right location
 * - If returns `false`, caller should disregard `bincode` and check `g_aofs_errormsg`.
*/
bool aof_HEX_tobinary(char *hex_literal, uint8_t size, uint16_t *bincode);

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
 * - If returns `false`, caller should disregard `bincode` and check `g_aofs_errormsg`.
*/
bool aof_REG_tobinary(char *reg_mnemonic, uint16_t* bincode);

/** 
 * Parses conditional assembly instructions (`MOV` or `CNA`) to binary code.
 * Arguments:
 * - `char *asmline` Null terminated string containing a line of assembly.
 * - `uint16_t* bincode` The pointer to write the result binary code to.
 * 
 * Returns: `true` if success, `false` otherwise.
 * 
 * Notes: 
 * - Assembly arguments are in format `Rd Rn CND`. 
 * - If returns `false`, caller should disregard `bincode` and check `g_aofs_errormsg`.
*/
bool aof_CND_tobinary(char *asmline, uint16_t* bincode);

bool aof_MEM__tobinary(char *asmline, uint16_t* bincode);

bool aof_SFT__tobinary(char *asmline, uint16_t* bincode);

bool aof_ALU__tobinary(char *asmline, uint16_t* bincode);
