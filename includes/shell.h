#ifndef __SHELL_H__
#define __SHELL_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// GNU libraries
#include <readline/readline.h>
#include <readline/history.h>


#define INPUT_LIMIT 100
#define LETTER_LIMIT 100

#endif


#ifndef __BASIC_FUNC__  
#define __BASIC_FUNC__

int user_input(char *str);
int parse_input(char *input);
void execute_cmd(char **cmd);

#endif