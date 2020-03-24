// CPSC 405 - Shell Lab
// Justin Adams
// Zachary Wallace

#include "shell.h"

int main(int argc, char **argv) 
{
    printf("\n\n**********************\n\n");
    printf("\nTODO:\n");
    printf("\nImplement signal interrupts\n");
    printf("\nImplement I/O redirection\n");
    printf("\n\n**********************\n\n");

    // set the username based on system
    username = getenv("USER");

    // enter into shell loop
    if (shell_loop()) {
        printf("\n\n**********************\n\n");
        printf("exiting shell...goodbye!");
        printf("\n\n**********************\n\n");
    };

    return 0;
}