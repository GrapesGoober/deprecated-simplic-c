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
 * - `char *token` Null terminated string containing the token of the problem.
 * - `char *message` Null terminated string containing the message.
*/
void aof_asm_fmterror(char *token, char *message);

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
 * Parses a literal token to binary code (with size restriction)
 * Arguments:
 * - `char *literal_tok` Null terminated string containing the literal.
 * - `uint8_t size` Restrict how large the literal can represent.
 * - `uint16_t* bincode` The pointer to write the result binary code to.
 * 
 * Returns: `true` if success, `false` otherwise. 
 * 
 * Notes:
 * - The caller must do appropriate shift left to place the binary code at the right location
 * - If returns `false`, caller should disregard `bincode` and check `g_aofs_errormsg`.
*/
bool aof_literal_tobinary(char *literal_tok, uint8_t size, uint16_t *bincode);

/** 
 * Parses a register mnemonic to binary code
 * Arguments:
 * - `char *reg_tok` Null terminated string containing 2 digits of register mnemonic.
 * - `uint16_t* bincode` The pointer to write the result binary code to.
 * - `uint8_t shift` The distance to left shift to.
 * 
 * Returns: `true` if success, `false` otherwise. 
 * 
 * Note: if returns `false`, caller should disregard `bincode` and check `g_aofs_errormsg`.
*/
bool aof_REG_tobinary(char *reg_tok, uint16_t* bincode, uint8_t shift);

/** 
 * Parses conditional assembly instructions (`MOV` or `CNA`) to binary code.
 * Arguments:
 * - `char *asmline` Null terminated string containing a line of assembly.
 * - `uint16_t* bincode` The pointer to write the result binary code to.
 * 
 * Returns: `true` if success, `false` otherwise.
 * 
 * Notes:
 * - The assembly arguments are `Rd Rn CND`.
 * - If returns `false`, caller should disregard `bincode` and check `g_aofs_errormsg`.
*/
bool aof_CND_tobinary(char *asmline, uint16_t* bincode);

bool aof_MEM__tobinary(char *asmline, uint16_t* bincode);

bool aof_SFT__tobinary(char *asmline, uint16_t* bincode);

bool aof_ALU__tobinary(char *asmline, uint16_t* bincode);
