#ifndef __SHELL_H__
#define __SHELL_H__
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

// GNU libraries
#include <readline/readline.h>
#include <readline/history.h>

#define PIPE_TOK_DELIM "|\t\r\n\a"
#define SH_TOK_DELIM " \t\r\n\a"
#define INPUT_LIMIT 100
#define LETTER_LIMIT 100
#endif

#ifndef __BASIC_FUNC__  
#define __BASIC_FUNC__

int shell_loop();
int user_input(char *str);
char **parse_input(char *input, char *delim);
void execute_cmd(char *cmd);
int sh_pwd(char **args);
int sh_exit(char **args);
int sh_cd(char **args);
int sh_help(char **args);
char **fileIO(char *args[]);
int file_handler(char **args, char *op, int i);
int file_open(char *file, char *opt);
// users system username
char *username;

void signal_handler(int signum);

#define REALLOC(ptr, ptr_old, num, type, std_size) {\
    num += std_size;\
    ptr_old = ptr;\
    ptr = (type *) realloc(ptr, num * sizeof(type));\
    if (!ptr)\
    {\
        free(ptr_old);\
        fprintf(stderr, "Allocation error\n");\
        ptr = NULL;\
    }\
}

#define MALLOC(ptr, num, type) {\
    ptr = (type *)malloc((num) * sizeof(type));\
    if (!ptr) fprintf(stderr, "Memory allocation error\n");\
}

static char *builtin_str[] = {
    "pwd",
    "exit",
    "cd",
    "help"
};

static int (*builtin_func[])(char **) = {
    &sh_pwd,
    &sh_exit,
    &sh_cd,
    &sh_help
};

static int num_builtins()
{
    return sizeof(builtin_str) / sizeof(char *);
};



#endif