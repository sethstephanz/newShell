#include "command.h"
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

    Command command1; // this will leave the function at some point, so don't do this locally
    char **argv = malloc(tokens_cnt * sizeof(char *));

    command1.argc = tokens_cnt;
    command1.argv = tokens;

    // printf("program: %s\n", command1.argv[0]);

    if (strcmp(command1.argv[0], "echo") == 0) {
        for (int i = 1; i < tokens_cnt; i++) {
            if (tokens[i]) {
                printf("%s ", tokens[i]);
            }
        }
    }

    free(argv); // do this in destroy_command. actually this is probably not good. come back to

    return 0;
}

void destroy_command(Command command_to_destroy) {
    // frees all resources associated with command struct
    printf("destroy_command");
}