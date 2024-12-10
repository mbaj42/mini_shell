#include "shell.h"


int     main(void)
{
    char    *line;
    char    *trimmed_input;

    while(true)
    {
        display_prompt();
        line = read_command();
        if(!line)
            break;
        init_minishell(line);
        trimmed_input = check_input(line);
        tokenize_input(trimmed_input);
        // zwolnic pamiec trimmedline
        // execute_command(line);
            free(line);
    }
    return(0);
}