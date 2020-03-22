#include "shell.h"

// Parse the input by piping
char **parse_input(char *input, char *delim)
{
    int t_pos = 0;
    int buff_size = 64;
    char **parsed_args;
    char **tokens = (char**) malloc(buff_size * sizeof(char *));
    char *token, **tokens_backup;

    token = strtok(input, delim);
    while (token != NULL) 
    {
        tokens[t_pos] = token;
        t_pos++;
        if (t_pos >= buff_size)
        {
            REALLOC(tokens, tokens_backup, buff_size, char*, 64);
        }
        token = strtok(NULL, delim);
    }
    
    tokens[t_pos] = NULL;
    return tokens;
}

// execute the passed command argument
void execute_cmd(char *cmd)
{

    
}