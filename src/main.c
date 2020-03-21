#include "shell.h"

int main(int argc, char **argv) {

    // gets the username from system
    char *username = getenv("USER");

    char str[100];

    // enter into command input loop
    // puts input into str
    while (1) {
        printf("%ssh", username);
        if (user_input(str)) {
            // no input given
            continue;
        } else {
            // input handled here
            
        }
    }

    free(str);
    return 0;
}