#ifndef COMMAND_H
#define COMMAND_H

#include <stddef.h>

typedef struct Command {
    char **argv; // array of argument strings
    size_t argc; // number of args
} Command;

Command *create_command(int tokens_cnt, char **tokens);
void destroy_command(Command *command);

#endif