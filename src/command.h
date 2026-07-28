#ifndef COMMAND_H
#define COMMAND_H

#include <stddef.h>

typedef struct Command {
    char **argv; // exec(program, argv) is coming up, so want *argv[0] == program name
    size_t argc;
} Command;

int create_command(int tokens_cnt, char **tokens);
void destroy_command(Command command_to_destroy);

#endif