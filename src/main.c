#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#define ERROR_CODE 3

int yyparse();
extern FILE* yyin;

int main(int argc, char** argv){
    if (argc < 2){
        printf("Please call: ./etapa2 input.txt\n");
        exit(ERROR_CODE);
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Unable to open file %s.\n", argv[1]);
        exit(ERROR_CODE);
  }

    hashInit();
    yyparse();
    hashPrint();

    fprintf(stderr, "Terrific! Go on! \n");

    exit(0);
}