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
        size_t input_len = strlen(buff);
        parse_input(input_len, buff);
    }
}