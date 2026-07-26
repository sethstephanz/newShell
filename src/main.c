#include "parser.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool hello = false;

int main() {
    for (;;) {
        if (!hello) {
            printf("Hello, newShell!\n");
            char test_arg[] = "parser test!";
            parser_test(strlen(test_arg), test_arg);
            hello = true;
        } else {
            printf("exiting newshell!\n");
            exit(EXIT_SUCCESS);
        }
    }
}