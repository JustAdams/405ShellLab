#include "shell.h"

// catch an interrupt signal
void signal_handler(int sig)
{
    //char *username = getenv("USER");
    if (sig == SIGINT)
    {
        fprintf(stdout, "\n");
        fflush(stdout);
        signal(SIGINT, signal_handler);
        
        // display user info at prompt
        printf("%ssh> ", username);
    }
}