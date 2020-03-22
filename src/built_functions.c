#include "shell.h"

int sh_pwd() 
{
    char *buff;
    buff = getcwd(NULL, 0);
    fprintf(stdout, "%s\n", buff);
    fflush(stdout);
    free(buff);
    return 1;
}

int sh_exit() {
    return 0;
}