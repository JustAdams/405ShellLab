#include "shell.h"

int parse_input(char *input)
{
    char *str_pipe[2];

    for (int i = 0; i < 2; i++) {
        str_pipe[i] = strsep(&input, "|");
        if (str_pipe[i] == NULL) {
            break;
        }
    }
    
    if (str_pipe[1] == NULL) {
        execute_cmd(str_pipe);
    } else {
        //parse_cmd(str_pipe);
    }

}

void execute_cmd(char **cmd)
{
    pid_t p = fork();
    if (p == -1) {
        printf("Error in forking child...stop\n");
        return;
    } else if (p == 0) {
        // execute command
        if (execvp(cmd[0], cmd) < 0) {
            printf("Error executing command...stop\n");
        }
        exit(0);
    } else {
        // wait for child to terminate
        wait(NULL);
        return;
    }
    
}