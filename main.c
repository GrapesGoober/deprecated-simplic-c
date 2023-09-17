// Simplic Compiler 2022, Nachat Kaewmeesang
// main.c file is the entry point for the compiler, and a good starting point to read how this works.
// This file handles cli arguments, file reading & writing, and various function calls to compile the code.

#include <stdio.h>
#include <stdlib.h>

#include "simplic/aofs-assembler.h" // for the assembler

int main(int argc, char* argv[]) {
    
    // read cli arguments to get the filepath
    // cli should look like      smplc.exe 'file-to-compile'
    // if (argc != 2) {
    //     // filepath argument not given
    //     fprintf(stderr, "Requires 1 argument: filepath");
    //     exit(EXIT_FAILURE);
    // }

    // start reading the file
    FILE* sourcefile;
    sourcefile = fopen(argv[1], "r");
    if (sourcefile == NULL) {
        perror("Cannot open file");
        exit(EXIT_FAILURE);
    }

    // start parsing the file
    // unimplemented
    uint16_t bincode;
    char *my_asm = argv[2];
    aof_REG_tobinary(my_asm, &bincode, 0);
    printf("Result: %x\n", bincode);
    printf("%s", g_aofs_errormsg);

    // write to hex file
    // unimplemented

    // close file as a good measure
    fclose(sourcefile);
    exit(EXIT_SUCCESS);
}
