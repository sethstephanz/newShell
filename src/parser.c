#include "../include/parser.h"
#include "../include/command.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TODO:
// commands
- ls
- echo
- cat
- grep
- ./program
- cd
- exit
- pwd

// redirection
- >
- >>
- <

// pipe
- |

// background
- &

// quoted args
- "etc."
*/

/*
1. tokenization
2. command representation
3. built-in detection
4. pipes/redirects
*/

ParseRes *parse_input(char *arg) {
    ParseRes *parse_res = malloc(sizeof(*parse_res));
    if (!parse_res) {
        fprintf(stderr, "parser.c: Error: parse_res memory allocation failure1\n");
        return NULL; // if malloc is failing, there are bigger issues. just return null for now and exit with error from main
    }

    // for array of ptrs to Command objects
    Command **commands = malloc(5 * sizeof(*commands)); // make space for up to 5 commands ptrs for now
    if (!commands) {
        fprintf(stderr, "parser.c: Error: commands memory allocation failure2\n");
        destroy_parse_res(5, parse_res); // don't want to do anything with this back in main. free now
        return NULL;
    }

    // hook array to parse_res struct
    parse_res->commands = commands;

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
    create_command(tokens_cnt, tokens);

    /*
    ptr -> ParseRes parse_res

    typedef struct ParseRes {
        Command **commands; // pointer to array of pointers to commands
        int status;
    } ParseRes;
    */

    printf("returning parse_res");
    return parse_res;
}

void destroy_parse_res(size_t cmd_cnt, ParseRes *parse_res) {
    /* TODO:
        1. loop thru and free each command
        2. free commands array
        3. free parse_res
    */
    for (size_t i = 0; i < cmd_cnt; i++) {
        free(parse_res->commands[i]);
    }
    free(parse_res->commands);
    free(parse_res);

    printf("destroy >:)\n");
}