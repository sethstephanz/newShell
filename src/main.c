#include "../include/executor.h"
#include "../include/parser.h"
#include "../include/terminal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 100

void print_greeting();

int main() {
    print_greeting();
    print_options();
    for (;;) {
        print_prompt();
        char buff[BUFF_SIZE];
        fgets(buff, BUFF_SIZE, stdin);
        buff[strcspn(buff, "\n")] = '\0'; // replace ending newline with null terminator so doesn't end up in token

        ParseRes *parse_res = parse_input(buff);
        if (!parse_res) {
            fprintf(stderr, "main.c: parse_res returned as null. Exiting\n");
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
        printf("parse_res          = %p\n", (void *)parse_res);
        printf("commands           = %p\n", (void *)parse_res->cmd_list);
        printf("commands[0]        = %p\n", (void *)parse_res->cmd_list[0]);
        printf("command[0]         = %s\n", parse_res->cmd_list[0]->argv[0]);

        printf("Command ptr        = %p\n", (void *)parse_res->cmd_list[0]);

        printf("argv ptr           = %p\n", (void *)parse_res->cmd_list[0]->argv);

        printf("argv[0] ptr        = %p\n", (void *)parse_res->cmd_list[0]->argv[0]);

        if (parse_res) {
            // parse_res may not exist, may be partially filled.
            // handle NULL cases here, partially filled in function
            // TODO: make cmd_cnt dynamic
            destroy_parse_res(5, parse_res);
            parse_res = NULL; // just 2 b safe
        }
    }
}
