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