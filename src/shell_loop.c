#include "shell.h"

void shell_loop()
{
    // while loop status
    int status = 1;
    int clear_args = 0;
    // gets the username from system
    char *username = getenv("USER");
    char *parsed_str[INPUT_LIMIT];
    char str[LETTER_LIMIT];

    char **parsed_args;

    // enter into command input loop
    // puts input into str
    while (status == 1) {
        // display user info at prompt
        printf("%ssh", username);
        if (user_input(str)) {
            // no input given
            continue;
        } else {
            // input handled here
            // str - initial input
            parsed_args = parse_input(str, PIPE_TOK_DELIM);
            for (int i = 0; parsed_args[i] != NULL; i++) 
            {
                clear_args = 0;
                // determine if arg is a builtin function
                for (int i = 0; i < num_builtins(); i++) 
                {
                    if (strcmp(parsed_args[0], builtin_str[i]) == 0)
                    {
                        status = (*builtin_func[i])(parsed_args);
                        clear_args = 1;
                    }
                }
                if (clear_args)
                {
                    free(parsed_args);
                    break;
                }

                // fork a child
                pid_t pid;
                char **new_args = NULL;
                pid = fork();
                if (pid < 0)
                {
                    fprintf(stderr, "error creating child process. stop\n");
                    break;
                }

                if (pid == 0)
                {                    
                    // run linux command if valid
                    if (execvp(parsed_args[0], parsed_args) == -1)
                    {
                        fprintf(stderr, "Command not found\n", new_args[0]);
                    }
                }
            }
            // wait for child process to terminate
            wait(NULL);
        }
    }
}