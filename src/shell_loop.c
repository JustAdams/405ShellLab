#include "shell.h"

int shell_loop()
{
    // while loop status
    int status = 1;
    int clear_args = 0;
    // gets the username from system
    char *parsed_str[INPUT_LIMIT];
    char str[LETTER_LIMIT];

    char **parsed_args, **cmd_args;
    signal(SIGINT, signal_handler);
        
    // enter into command input loop
    // puts input into str
    while (status == 1) {
        // display user info at prompt
        printf("%ssh", username);
        // get user input and go to else if has arguments
        if (user_input(str)) {
            // no input given
            continue;
        } else {
            // input handled here
            // separate arguments by pipes
            parsed_args = parse_input(str, PIPE_TOK_DELIM);
 
            for (int i = 0; parsed_args[i] != NULL; i++) 
            {
                // split commands into individual parts
                cmd_args = parse_input(parsed_args[i], SH_TOK_DELIM);
                clear_args = 0;
                // determine if arg is a builtin function and executes
                for (int i = 0; i < num_builtins(); i++) 
                {
                    if (strcmp(cmd_args[0], builtin_str[i]) == 0)
                    {
                        status = (*builtin_func[i])(cmd_args);
                        clear_args = 1;
                    }
                }
                if (clear_args)
                {
                    free(cmd_args);
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
                    if (execvp(cmd_args[0], cmd_args) == -1)
                    {
                        fprintf(stderr, "command %s is not valid\n", new_args[0]);
                    }
                }
            }
            // wait for child process to terminate
            wait(NULL);
        }
    }
    // succesful end of program
    return 1;
}