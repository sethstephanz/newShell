#include "parser.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool hello = false;

int main() {
    for (;;) {
        if (!hello) {
            printf("Hello, newShell!\n");
            parser_test();
            hello = true;
        } else {
            printf("exiting newshell!\n");
            exit(EXIT_SUCCESS);
        }
    }
}