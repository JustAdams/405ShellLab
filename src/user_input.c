#include "shell.h"

int user_input(char* str) 
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