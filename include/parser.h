#ifndef PARSER_H
#define PARSER_H

#include "command.h"
#include <stddef.h>

// parser response codes
enum ParseCode {
    PARSE_OK = 0,
    ERR_INPUT_TOO_LONG,
    ERR_TOO_MANY_ARGS
};

typedef struct ParseRes {
    Command **cmd_list; // pointer to array of pointers to commands
    size_t cmd_cnt;
    int status;
} ParseRes;

// ParseRes -> [*Command, *Command, ... , *Command], status
// Command -> argv -> strings, argc

ParseRes *parse_input(char *arg);
void destroy_parse_res(size_t cmd_cnt, ParseRes *res);

void print_parse_res(ParseRes res);

#endif