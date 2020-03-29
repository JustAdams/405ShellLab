#include "shell.h"

// present working directory
int sh_pwd(char **args) 
{
    char *buff;
    buff = getcwd(NULL, 0);
    fprintf(stdout, "%s\n", buff);
    fflush(stdout);
    free(buff);
    return 1;
}

// exit the shell
int sh_exit(char **args) {
    return 0;
}

// change directory to second argument
int sh_cd(char **args)
{
    // try to change directory
    if (chdir(args[1]) != 0)
    {
        fprintf(stderr, "%s does not exist in this context\n", args[1]);
    }
    return 1;
}

// display the possible commands
int sh_help(char **args)
{
    printf("\nCommands:\n");
    printf("Built-in Functions:\n");
    printf(" *  pwd - Display the present working directory\n");
    printf(" *  exit - Exits the shell\n");
    printf(" *  cd + directory - Change the current directory to the given one\n");
    printf(" *  help - Do what you're doing now!\n");

    printf("All standard Linux commands are also included\n");

    printf("\n");
    return 1;
}