#include "../include/executor.h"
#include "../include/parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 100

int main() {
    printf("=====================================\n");
    printf("       newShell v0.1                 \n");
    printf("=====================================\n");
    printf("Type '-(o)ptions' for options'\n");
    printf("Type '-(e)xit' to quit.\n");

    for (;;) {
        printf("newShell> ");
        char buff[BUFF_SIZE];
        fgets(buff, BUFF_SIZE, stdin);
        buff[strcspn(buff, "\n")] = '\0'; // replace ending newline with null terminator so doesn't end up in token
        ParseRes *parse_res = parse_input(buff);
        if (parse_res) {
            fprintf(stderr, "main.c: parse_res memory allocation failure\n");
            return EXIT_FAILURE;
        }

        int parse_status = parse_res->status;

        // error codes comm should be responsibility of main
        if (parse_status == PARSE_OK) {
            printf("main.c: Parse: Parse OK\n");
        } else if (parse_status == ERR_INPUT_TOO_LONG) {
            printf("main.c: Parse: Parse error: Input too long\n");
        } else if (parse_status == ERR_TOO_MANY_ARGS) {
            printf("main.c: Parse: Parse error: Too many tokens\n");
        }

        /*
        if (execute_command((*parse_res)->commands) < 0) {
            printf("main.c: ERR: execute_command");
        }
        */

        if (parse_res) {
            // parse_res may not exist, may be partially filled.
            // handle NULL cases here, partially filled in function
            // TODO: make cmd_cnt dynamic
            destroy_parse_res(5, parse_res);
            parse_res = NULL; // just 2 b safe
        }
    }
}