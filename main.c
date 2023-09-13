#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    
    // read cli arguments to get the filepath
    // cli should look like      smplc.exe 'file-to-compile'
    if (argc != 2) {
        // filepath argument not given
        fprintf(stderr, "Requires 1 argument: filepath");
        exit(EXIT_FAILURE);
    }

    // start reading the file
    FILE* sourcefile;
    sourcefile = fopen(argv[1], "r");
    if (sourcefile == NULL) {
        perror("Cannot open file");
        exit(EXIT_FAILURE);
    }

    // start parsing the file
    // unimplemented

    // write to hex file
    // unimplemented

    // close file as a good measure
    fclose(sourcefile);
    exit(EXIT_SUCCESS);
}
