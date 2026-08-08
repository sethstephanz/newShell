#include "../include/command.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Command *create_command(size_t tokens_cnt, char **tokens) {
    //*******************************************/
    // Creates and packs individual command structs
    //*******************************************/
    printf("----------start command.c-----------\n");

    printf("tokens_cnt3: %zu\n", tokens_cnt);

    Command *command = malloc(sizeof(*command));
    if (!command) {
        return NULL;
    }
    char **argv = malloc((tokens_cnt + 1) * sizeof(char *)); // array of char *s, + 1 for sentinel
    if (!argv) {
        free(command);
        return NULL;
    }

    command->argv = argv;
    command->argc = 0;

    for (size_t i = 0; i < tokens_cnt; i++) {
        size_t token_len = strlen(tokens[i]);
        char *token = malloc(token_len + 1);
        if (!token) {
            for (size_t j = 0; j < command->argc; j++) {
                free(command->argv[j]);
            }
            free(command);
            free(command->argv);
            return NULL;
        }
        strcpy(token, tokens[i]);
        command->argv[i] = token;
        command->argc += 1;
    }

    command->argv[tokens_cnt] = NULL; // add sentinel. not counted by argc!

    printf("tokens[0] = %s\n", tokens[0]);
    printf("argv[0] = %s\n", command->argv[0]);
    printf("tokens[0] ptr: %p\n", (void *)tokens[0]);
    printf("argv[0] ptr:   %p\n", (void *)command->argv[0]);

    return command;
}