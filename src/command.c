#include "../include/command.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Command *create_command(int tokens_cnt, char **tokens) {
    //*******************************************/
    // Creates and packs individual command structs
    //*******************************************/
    printf("----------start command.c-----------\n");

    Command *command = malloc(sizeof(*command)); // this will leave the function at some point, so don't do this locally
    if (!command) {
        return NULL;
    }
    char **argv = malloc((tokens_cnt + 1) * sizeof(char *));
    if (!argv) {
        free(command);
        return NULL;
    }

    command->argc = tokens_cnt - 1; // don't count (null) sentinel at end. this is how unix does it
    command->argv = argv;

    for (int i = 0; i < tokens_cnt; i++) {
        size_t tok_len = strlen(tokens[i]);
        char *new_tok = malloc(tok_len + 1); // allocate for each new token
        if (!new_tok) {
            free(command);
            free(argv);
            return NULL;
        }
        strcpy(new_tok, tokens[i]); // copy token into new_tok
        command->argv[i] = new_tok; // hook new_tok to argv[i] slot
    }
    command->argv[tokens_cnt] = NULL; // sentinel token

    printf("tokens[0] ptr: %p\n", (void *)tokens[0]);
    printf("argv[0] ptr:   %p\n", (void *)command->argv[0]);

    return command;
}