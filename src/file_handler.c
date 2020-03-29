#include "shell.h"

// compares arguments to file operator values and returns true if it matches
int file_handler(char **args, char *op, int i)
{
    int flag;
    char file[2048], opt[2048], temp[2048];
    if (strstr(args[i], op) != NULL)
    {
        // argument matches operator
        if (strcmp(args[i], op) == 0)
        {
            if (args[i + 1], op == NULL)
            {

            }
        }
    }

    return 0;
}