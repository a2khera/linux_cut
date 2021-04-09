#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assign2funcs.h"
#include "assign2funcs.c"

#define MAX_FIELDS (100)
#define MAX_CHAR (10000)

/* Purpose: An implementation of a simplified version of cut function from Linux
*  Source: assign2.c
*  Parameters: argc is the argument count while argv is an array containing all argument values
*  Output: Strings separated by output delimiter
*  Return Value: Returns 1 when invalid input. Returns 0 other wise */

int main(int argc, char* argv[]){

    int inputResult = checkInput(argc, argv);

    if  (inputResult == 1) {
        char allLines[MAX_CHAR]; // Max Characters allowed
        int userChar = 0;       // Current character User Entered
        int charCount = 0;      // Total characters entered by User

        while ((userChar = getchar()) != EOF && charCount < MAX_CHAR - 1) {
            allLines[charCount] = userChar;
            charCount = charCount + 1;
        }

        int sizeFields = argc - 3;  // Number of fields
        int fields[sizeFields - 2]; // Array with all fields

        int u;  // Counter
        for(u=0; u < argc - 3; u++){
            int num = atoi(argv[u + 3]);
            fields[u] = num;
        }

        cutAllLine(*argv[1], *argv[2], allLines, fields, sizeFields);

        return 0;
    }
    else {
        printf("%d", argc);
        fprintf(stderr, "%s: specify input_delimiter output_delimiter and 1-%d fields in order", argv[0], MAX_FIELDS);
        return 1;
    }
}

