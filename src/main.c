// CPSC 405 - Shell Lab
// Inspired by Gusty Coopers Shell Lab and TeenyShell
// 
// Authors:
// Justin Adams
// Zachary Wallace

#include "shell.h"

int main(int argc, char **argv) 
{
    printf("\033[2J\033[1;1H");
    printf("**********************\n\n");
    printf(" ** Shell Lab for 405 ** \n");
    printf("Inspired by Gusty Coopers Shell Lab\n");
    printf("Authors: Justin Adams & Zach Wallace\n");
    printf("\n\nEnter 'help' if you need help, and have fun!\n");
    printf("\nTODO:\n");
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