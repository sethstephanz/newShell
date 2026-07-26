#include "parser.h"

#include <stdio.h>
#include <string.h>

#define STR_CPY_LEN 256 // length of string copy buffer for tokenization
#define ERR_INPUT_TOO_LONG 1
#define ERR_TOO_MANY_ARGS 2

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

int parse_input(size_t arg_len, char *arg) {
    printf("parser raw input: %s\n", arg);

    char arg_cpy[STR_CPY_LEN];
    const int tokens_cap = 20;
    size_t tokens_cnt = 0;
    char *tokens[tokens_cap];

    printf("str_cpy_len: %d, arg_len: %zu\n", STR_CPY_LEN, arg_len);

    if (arg_len < STR_CPY_LEN) {
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

    // check that input strings are being stored correctly
    for (int i = 0; i < tokens_cnt; i++) {
        printf("tokens[%d]: %s\n", i, tokens[i]);
    }

    // 2. commands
    // echo

    return 0;
}