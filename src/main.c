#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 100

int main() {
    for (;;) {
        printf("newShell> ");
        char buff[BUFF_SIZE];
        fgets(buff, BUFF_SIZE, stdin);
        int parse_res = parse_input(buff);

        // error codes comm should be responsibility of main
        if (parse_res == PARSE_OK) {
            printf("main.c: Parse: Parse OK\n");
        } else if (parse_res == ERR_INPUT_TOO_LONG) {
            printf("main.c: Parse: Parse error: Input too long\n");
        } else if (parse_res == ERR_TOO_MANY_ARGS) {
            printf("main.c: Parse: Parse error: Too many tokens\n");
        }
    }
}