#include "../include/terminal.h"

#include <stdio.h>

//**********************************/
// Keep UI clean & tidy
//**********************************/

void print_div(char ch, size_t reps) {
    for (size_t i = 0; i < reps; i++) {
        putchar(ch);
    }
    putchar('\n');
}

void print_greeting() {
    print_div('=', 44);
    printf(
        " _   _                 ____  _          _ _\n"
        "| \\ | | _____      __ / ___|| |__   ___| | |\n"
        "|  \\| |/ _ \\ \\ /\\ / / \\___ \\| '_ \\ / _ \\ | |\n"
        "| |\\  |  __/\\ V  V /   ___) | | | |  __/ | |\n"
        "|_| \\_|\\___| \\_/\\_/   |____/|_| |_|\\___|_|_|\n\n");
    printf("===================");
    printf("[v0.1]");
    printf("===================\n");

    /*
        v0.1 — parser works
        v0.2 — executor works
        v0.3 — built-ins
        v0.4 — pipes
        v0.5 — job control
    */
}

void print_prompt() {
    printf("newShell> ");
}

void print_options() {
    print_div('=', 44);
    printf("Type '-(o)ptions' for options'\n");
    printf("Type '-(e)xit' to quit.\n");
    print_div('=', 44);
}