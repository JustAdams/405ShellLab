#include "shell.h"

// checks the input array for file piping operators
char **fileIO(char *args[]) {
    // keep track of the current args position
    int i = 0;
    // position for the new_args array return
    int r_pos = 0;
    int buff_size = 32;
    int flag_in, flag_out;
    char **new_args = NULL;
    char **tmp_ptr = NULL;
    MALLOC(new_args, 32, char *);
    while (args[i] != NULL)
    {
        flag_in = file_handler(args, "<", i);
        flag_out = file_handler(args, ">", i);
        // if there's a file pipe operator...
        if ((flag_in > 0 || flag_out > 0))
        {
            // pipe operator
            i += 2;
            continue;
        }
        if ((flag_in == 0) && (flag_out == 0))
        {
            MALLOC(new_args[r_pos], strlen(args[i]) + 1, char);
            strcpy(new_args[r_pos], args[i]);
            r_pos++;
            if (r_pos >= buff_size)
            {
                REALLOC(new_args, tmp_ptr, buff_size, char *, 32);
            }
        }
        i++;
    }
    new_args[r_pos] = NULL;
    return new_args;
}

// compares arguments to file operator values and returns true if it matches
int file_handler(char **args, char *op, int i)
{
    char file[1024], opt[1024], temp[1024];
    if (strstr(args[i], op) != NULL)
    {
        // argument matches operator
        if (strcmp(args[i], op) == 0)
        {
            // check for a valid output file
            if (args[i + 1], op == NULL) { printf("invalid type\n"); }
            int flag = file_open(args[i + 1], op);
            // currently sending output to file
            return flag;
        }
    }
    return 0;
}

// copy file descriptors and close pipes dependning on pipe type
int file_open(char *file, char *opt)
{
    // file descripter #
    int file_d;

    // write to file
    if (strcmp(">", opt) == 0)
    {
        file_d = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0600);
        if (file_d < 0) { printf("Error: file write problem\n"); }
        dup2(file_d, STDOUT_FILENO);
        close(file_d);
        return 1;
    }
    // input from file
    if (strcmp("<", opt) == 0)
    {
        file_d = open(file, 00);
        if(file_d < 0) { printf("Error: file read problem\n"); }
        dup2(file_d, STDIN_FILENO);
        close(file_d);
        return 1;
    }
    // append to a file
    if (strcmp(">>", opt) == 0)
    {
        file_d = open(file, O_APPEND | O_WRONLY);
        if ( file_d < 0) { printf("Error: file append problem\n"); }
        dup2(file_d, STDOUT_FILENO);
        close(file_d);
        return 1;
    }
    return 0;
}