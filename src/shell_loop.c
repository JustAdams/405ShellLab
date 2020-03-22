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
            for (int i = 0; parsed_args[i] != NULL; i++) {

                // determine if arg is a builtin function
                for (int i = 0; i < num_builtins(); i++) 
                {
                    if (strcmp(parsed_args[0], builtin_str[i]) == 0)
                    {
                        printf("built in function: %s\n", parsed_args[0]);
                    }
                }

                // fork a child
                pid_t pid;
                pid = fork();
                if (pid < 0)
                {
                    fprintf(stderr, "error creating child process. stop\n");
                    break;
                }

                if (pid == 0)
                {
                    printf("child process %d created\n", pid);
                }
            }
        }
    }

    free(str);
}