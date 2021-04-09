#include "assign2funcs.h"

/* Purpose: Checks whether the user input is valid or not
*  Source: assign2funcs.c
*  Parameters: argc is the argument count while argv is an array containing all argument values
*  Output: Output based on user input. It is 0 when input is valid, 1 otherwise
*  Return Value: Returns 1 when invalid input. Returns 0 other wise */

int checkInput(int argc, char* argv[]) {
    int len1 = strlen(argv[1]); // Length of first argument
    int len2 = strlen(argv[2]); // Length of second argument

    if  (len1 != 1 || len2 != 1) {
        return 0;
    }
    else {
        int prevDig = 0; // Previous field
        for(int k = 3; k < argc; k++){
            int currentDig = atoi(argv[k]); // Current field
            if  (currentDig > prevDig) {
                prevDig = currentDig;
            }
            else {
                return 0;
            }
        }
        return 1;
    }
}

/* Purpose: Takes the entire text entered by user calls the cutOneLine for each lines
*  Source: assign2funcs.c
*  Parameters: input delimiter (a single character), output delimiter (a single character), the entire text, fields, size of fields
*  Output: strings separated by output delimiter
*  Return Value: None */

void cutAllLine(char inputDel, char outputDel, char allLines[], int fields[], int sizeFields) {
    int start = 0;  // Start New line from
    int lenLines = strlen(allLines);  // Length of entire input
    int lenOneLine = 0; // Length of one line from entire text
    for (int i = 0; i < lenLines; i++){
        if (i == lenLines - 1 || (allLines[i] == '\n')) {
            lenOneLine = i - start;
            char oneLine[lenOneLine];   // One line from entire text
            strncpy(oneLine, allLines+start, lenOneLine);
            cutOneLine(inputDel, outputDel, oneLine, fields, sizeFields);
            if (i != lenLines - 1) {
                printf("\n");
                start = i + 1;
            }
        }
    }

}

/* Purpose: Performs a simplified cut operation on a single line
*  Source: assign2funcs.c
*  Parameters: input delimiter (a single character), output delimiter (a single character), one line, fields, size of fields
*  Output: strings separated by output delimiter
*  Return Value: None */

void cutOneLine(char inputDel, char outputDel, char line[], int fields[], int sizeFields){
    int lenLine = strlen( line );   // Length of the line
    int start = 0;  // Start of field
    int end = 0; // End of field
    int fieldCount = 1;
    for (int i = 0; i < lenLine; i++){
        if (line[i] == inputDel) {
            int j; // Counter
            for (j = 0; j <= sizeFields; j++){
                if(fields[j] == fieldCount){
                    if (fieldCount != 1) {
                        printf("%c", outputDel);
                    }
                    printf("%.*s", end - start, line + start);
                }
            }
            start = i + 1;
            fieldCount = fieldCount + 1;
        }
        end = end + 1;
    }
    if (fields[sizeFields - 1] == fieldCount) {
        if (fieldCount != 1) {
            printf("%c", outputDel);
        }
        printf("%.*s", end, line + start);
    }
}
