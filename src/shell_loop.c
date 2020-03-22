#include "shell.h"

void shell_loop()
{
    // gets the username from system
    char *username = getenv("USER");
    char *parsed_str[INPUT_LIMIT];
    char str[LETTER_LIMIT];

    char **parsed_args;

    // enter into command input loop
    // puts input into str
    while (1) {
        // display user info at prompt
        printf("%ssh", username);
        if (user_input(str)) {
            // no input given
            continue;
        } else {
            // input handled here
            // str - initial input
            parsed_args = parse_input(str, PIPE_TOK_DELIM);
            //execute_cmd(parsed_args);
        }
    }

    free(str);
}