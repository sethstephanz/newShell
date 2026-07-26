#ifndef PARSER_H
#define PARSER_H

#include <stddef.h>

// parser response codes
enum ParseCode {
    PARSE_OK = 0,
    ERR_INPUT_TOO_LONG,
    ERR_TOO_MANY_ARGS
};

int parse_input(char *arg);

#endif