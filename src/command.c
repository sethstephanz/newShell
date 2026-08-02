#include "../include/command.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int create_command(int tokens_cnt, char **tokens) {
    //*******************************************/
    // Creates and packs individual command structs
    //*******************************************/
    // TODO: create multiple commands. for now, just create one to get pipeline in order

    /*
    creates command struct
    example:
    Command cmd1 = {
        argv = ["echo", "hello", "world"]
        argc = 3
    }
    -> returns to parser to be packed in with other commands in ParseRes struct

    ~~~in parser.c~~~
    ParseRes parse_res {
        cmds -> [cmd1, cmd2, ... , cmdn]
        status = x
    }
    */

    /*
    for (int i = 0; i < tokens_cnt; i++) {
        printf("token[%d]: %s\n", i, tokens[i]);
    }
    */
    printf("----------start command.c-----------\n");

    Command *command = malloc(sizeof(*command)); // this will leave the function at some point, so don't do this locally
    char **argv = malloc(tokens_cnt * sizeof(char *));

    command->argc = tokens_cnt - 1; // don't count (null) sentinel at end. this is how unix does it
    command->argv = tokens;

    // printf("program: %s\n", command.argv[0]);

    /*
    if (strcmp(command.argv[0], "echo") == 0) {
        for (int i = 1; i < tokens_cnt; i++) {
            if (tokens[i]) {
                printf("%s ", tokens[i]);
            }
        }
    }
    */

    // test basic command representation. "echo hello world" should be argc = 3, argv[0] = "echo", etc.
    printf("Command\n----------------------\n");
    printf("argc = %zu\n", command->argc);
    for (size_t i = 0; i <= command->argc; i++) {
        // should print all tokens in argument plus sentinel (NULL) at end
        if (command->argv[i]) {
            printf("argv[%zu] = %s\n", i, command->argv[i]);
        } else {
            printf("argv[%zu] = (NULL)\n", i);
        }
    }

    return 0;
}