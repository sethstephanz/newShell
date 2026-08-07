#include "../include/parser.h"
#include "../include/command.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ParseRes *parse_input(char *arg) {
    ParseRes *parse_res = malloc(sizeof(*parse_res));
    if (!parse_res) {
        fprintf(stderr, "parser.c: Error: parse_res memory allocation failure1\n");
        return NULL; // if malloc is failing. return null exit with error from main
    }

    // for array of ptrs to Command objects
    Command **commands = malloc(sizeof(*commands)); // doing one for now
    if (!commands) {
        fprintf(stderr, "parser.c: Error: commands memory allocation failure2\n");
        destroy_parse_res(5, parse_res); // don't want to do anything with this back in main. free now
        return NULL;
    }

    // hook empty Command ptr array to parse_res struct
    parse_res->cmd_list = commands;

    size_t arg_len = strlen(arg);
    const size_t str_cpy_len = 256;

    char arg_cpy[str_cpy_len];
    const size_t tokens_cap = 10;
    size_t tokens_cnt = 0;
    char *tokens[tokens_cap];

    if (arg_len < str_cpy_len) {
        // input string is reasonable length. create copy to be consumed when tokenized
        strcpy(arg_cpy, arg);
    } else {
        // too many chars in input string. do not pack commands. return immediately with correct error code
        fprintf(stderr, "[parser.c]: Err: Input too long\n");
        parse_res->status = ERR_INPUT_TOO_LONG;
        return parse_res;
    }

    // tokenize input string and store in array of char ptrs
    char *token = strtok(arg_cpy, " "); // this consumes arg_cpy
    tokens[tokens_cnt++] = token;       // store first token in array of char ptrs

    while (token) {
        // note: currently storing (NULL) as last element in array as sentinel node to mark end of token array
        token = strtok(NULL, " ");
        if (tokens_cnt < tokens_cap) {
            tokens[tokens_cnt++] = token;
        } else {
            parse_res->status = ERR_TOO_MANY_ARGS; // want to report these in main, so don't destroy yet
            return parse_res;
        }
    }

    // for Unix commands, first word is always the program, followed by args (valid or not)
    // this holds for multiple args, but the line is broken up, like with a pipe, etc.

    // 2. commands
    Command *cmd = create_command(tokens_cnt, tokens);
    if (!cmd) {
        destroy_parse_res(5, parse_res);
        return NULL;
    }

    parse_res->cmd_list[0] = cmd; // hard-coded for now. TODO: replace

    printf("returning parse_res");
    return parse_res;
}

void destroy_parse_res(size_t cmd_cnt, ParseRes *parse_res) {
    /***********************************************
        1. for each command, free argv
        2. free each command in cmd_list
        2. free commands array
        3. free parse_res
    ************************************************/
    for (size_t i = 0; i < 1; i++) {        // TODO: switch this back to cmd_cnt
        free(parse_res->cmd_list[i]->argv); // 1
        free(parse_res->cmd_list[i]);       // 2
    }
    free(parse_res->cmd_list); // 3
    free(parse_res);           // 4

    printf("parse_res destroyed! >:)\n");
}