#include <signal.h>
#include "shell.h"

void signal_handler(int sig)
{
    if (sig == SIGINT)
    {
        fprintf(stdout, "\n");
        fflush(stdout);
    }
}