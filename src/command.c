#include "../include/command.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Command *create_command(int tokens_cnt, char **tokens) {
    //*******************************************/
    // Creates and packs individual command structs
    //*******************************************/
    printf("----------start command.c-----------\n");

    Command *command = malloc(sizeof(*command));
    if (!command) {
        return NULL;
    }
    char **argv = malloc((tokens_cnt + 1) * sizeof(char *)); // array of char *s, + 1 for sentinel
    if (!argv) {
        free(command);
        return NULL;
    }

    command->argc = tokens_cnt - 1; // don't count (null) sentinel at end. this is how unix does it
    command->argv = argv;

    for (int i = 0; i < tokens_cnt; i++) {
        // char *token = malloc();
        //  this is the problem. argv is set to tokens, which is statically allocated before we use it
        command->argv[i] = tokens[i];
    }

    printf("tokens[0] = %s\n", tokens[0]);
    printf("argv[0] = %s\n", command->argv[0]);
    printf("tokens[0] ptr: %p\n", (void *)tokens[0]);
    printf("argv[0] ptr:   %p\n", (void *)command->argv[0]);

    return command;
}