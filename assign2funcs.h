#ifndef ASSIGN2FUNCS_H_INCLUDED
#define ASSIGN2FUNCS_H_INCLUDED

int checkInput (int argc, char* argv[]);

void cutAllLine(char inputDel, char outputDel, char allLines[], int fields[], int sizeFields);

void cutOneLine(char inputDel, char outputDel, char line[], int fields[], int sizeFields);

#endif // ASSIGN2FUNCS_H_INCLUDED
