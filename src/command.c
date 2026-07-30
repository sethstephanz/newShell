#include "../include/command.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int create_command(int tokens_cnt, char **tokens) {
    // printf("create command\n");
    /*
    creates command struct
    example:
    Command1 = {
        program = echo
        argv = [hello, world]
        argc = 2
    }
    */

    /*
    for (int i = 0; i < tokens_cnt; i++) {
        printf("token[%d]: %s\n", i, tokens[i]);
    }
    */

    /*
    TODO:
    - Decide whether Command owns argv
    - Return/pass Command to executor
    - Move echo handling into executor
    */

    Command command; // this will leave the function at some point, so don't do this locally
    char **argv = malloc(tokens_cnt * sizeof(char *));

    command.argc = tokens_cnt - 1; // don't count (null) sentinel at end. this is how unix does it
    command.argv = tokens;

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
    printf("argc = %zu\n", command.argc);
    for (size_t i = 0; i <= command.argc; i++) {
        // should print all tokens in argument plus sentinel (NULL) at end
        if (command.argv[i]) {
            printf("argv[%zu] = %s\n", i, command.argv[i]);
        } else {
            printf("argv[%zu] = (NULL)\n", i);
        }
    }

    free(argv); // do this in destroy_command. actually this is probably not good. come back to

    return 0;
}

void destroy_command(Command *command) {
    // frees all resources associated with command struct
    printf("%zu\n", command->argc); // suppress warning
    printf("destroy_command");
}