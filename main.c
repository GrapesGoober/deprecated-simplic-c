#include <stdio.h>

#include <utils\simplic-node.h>

int main(int argc, char* argv[])
{
    // read cli arguments to get the filepath
    // cli should look like      smplc.exe 'file-to-compile'
    if (argc != 2)
    {
        // filepath argument not given
        fprintf(stderr, "Requires 1 argument: filepath");
        return 1;
    }

    // start reading the file
    FILE* sourcefile;
    sourcefile = fopen(argv[1], "r");
    if (sourcefile == NULL)
    {
        perror("Cannot open file");
    }

    // start parsing the file
    // unimplemented

        fprintf(stderr, "test error");
    // write to hex file
    // unimplemented

    // close file as a good measure
    fclose(sourcefile);
    return 0;
}
