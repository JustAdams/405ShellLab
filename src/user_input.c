#include "shell.h"

// Gets the users next input
// Runs from while-loop in main.c
// Changes str to current input
int user_input(char *str) 
{
    char* buff;

    buff = readline("> ");
    if (strlen(buff) != 0) {
        // add input to CLI history
        add_history(buff);
        // pass buff line to str
        strcpy(str, buff);
        return 0;
    } else {
        return 1;
    }
}