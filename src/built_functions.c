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

// 
int sh_cd(char **args)
{
    return 1;
}