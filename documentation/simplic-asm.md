# Simplic-ASM Documentation
This is work-in-progress

## Instructions

### General Purpose Instructions
| Name              | Syntax            | Description                                           |
| ----------------- | ----------------- | ----------------------------------------------------- |
| Move              | `MOV Rd Rn CND`   |  Conditionally move value from Rn to Rd               |
| Conditionally Add | `CNA Rd Rn CND`   |  Conditionally add value from Rn to Rd                |
| Load              | `LDR Rd Rn IMM4`  |  Load memory [Rn] to Rd with post indexing            |
| Store             | `STR Rd Rn IMM4`  |  Store memory [Rn] to Rd with post indexing           |
| Insert            | `INS Rd IMM8`     |  Left shift Rd by 8 and insert IMM8 to Rd             |
| Shift             | `SFT Rd Rm SOP`   |  Shift Rd using shift operation SOP by Rm distance    |

### Arithmatic and Logic Instructions, 
e.g. `ADD Rd Rn Rm`
Performs operation on Rn and Rm, and write the result to Rd
"ADD", "SUB",  "MUL", "LML", "DIV", "MOD",
"AND", "ORR", "XOR", "NOR"

## Registers
"ZR", "R1", "R2", "R3", "R4", "R5", // General Purpose Registers
"R6", "R7", "R8", "R9", "RA", "RB", 
"SP", // Stack Pointer (points to current top of stack)
"BR", // Buffer Register (for jumps, memory address, literal assignments etc)
"LR", // Link Register (PC's last location to return to, after finished a call)
"PC"  // Program Counter (points to the current instruction to read)

## Conditions
// Set & Clear status for each flags
"ZS", "ZC", // Zero Flag for equality comparison
"CS", "CC", // Carry Flag, for handling arithmatics
"NS", "NC", // Negative Flag for more than & less than comparison
"VS", "VC", // Overflow flag for handling nasty arithmatics
// General comparison useful for branches
"SM", "HI", // Smaller & Higher, for unsigned, use with SUB
"LT", "GT", // Lesser & Greater, for signed, use with SUB
"LE", "GE", // LT & GT or Equal
"FC", // Flag Clear
// And of course...
"AL" // Always, does not bother with flags