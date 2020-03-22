#include "shell.h"

int main(int argc, char **argv) {

    // gets the username from system
    char *username = getenv("USER");
    char *parsed_str[INPUT_LIMIT];
    char str[LETTER_LIMIT];

    // enter into command input loop
    // puts input into str
    while (1) {
        printf("%ssh", username);
        if (user_input(str)) {
            // no input given
            continue;
        } else {
            // input handled here
            // str - initial input
            parse_input(str);
        }
    }

    free(str);
    return 0;
}