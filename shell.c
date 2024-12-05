#include "shell.h"


int     main(void)
{
    char    *line;
    t_data  *hell;
    t_data *hell = malloc(sizeof(t_data));
if (!hell)
    ft_handle_error("Memory allocation failed");

hell->tokens = NULL; // Ważne!
hell->input = NULL;

    while(true)
    {
        display_prompt();
        line = read_command();
        if(!line)
            break;
        hell = tokenize_input(line, hell);
        // execute_command(line);
            free(line);
    }
    return(0);
}