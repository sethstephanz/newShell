#include "../include/parser.h"
#include "../include/command.h"

#include <stdio.h>
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
    ParseRes parse_res;
    // Command **commands = malloc(5 * sizeof(Command)); // make space for 5 commands for now

    // printf("parser raw input: %s\n", arg);
    size_t arg_len = strlen(arg); // get this here instead of being passed in
    const size_t str_cpy_len = 256;

    char arg_cpy[str_cpy_len];
    const size_t tokens_cap = 20;
    size_t tokens_cnt = 0;
    char *tokens[tokens_cap];

    // printf("str_cpy_len: %zu, arg_len: %zu\n", str_cpy_len, arg_len);

    if (arg_len < str_cpy_len) {
        strcpy(arg_cpy, arg);
    } else {
        fprintf(stderr, "[parser.c]: Err: Input too long\n");
        return ERR_INPUT_TOO_LONG;
    }

    // tokenize input string and store in array of char ptrs
    char *token = strtok(arg_cpy, " "); // this consumes arg_cpy
    tokens[tokens_cnt++] = token;       // store first token in array of char ptrs

    while (token) {
        // note: currently storing (NULL) as last element in array. this is not nec. a bad thing
        token = strtok(NULL, " ");
        if (tokens_cnt < tokens_cap) {
            tokens[tokens_cnt++] = token;
        } else {
            // fprintf(stderr, "[parser.c]: Err: Too many arguments\n");
            return ERR_TOO_MANY_ARGS;
        }
    }

    /* check that input strings are being stored correctly
    for (int i = 0; i < tokens_cnt; i++) {
        printf("tokens[%d]: %s\n", i, tokens[i]);
    }
    */

    // for Unix commands, first word is always the program, followed by args (valid or not)
    // this holds for multiple args, but the line is broke up, like with a pipe, etc.

    // 2. commands
    create_command(tokens_cnt, tokens);
    return &parse_res;
}