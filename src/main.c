#include "shell.h"

int main(int argc, char **argv) 
{

    // enter into input loop
    if (shell_loop()) {
        printf("\n\nexiting shell...goodbye!\n\n");
    };

    return 0;
}