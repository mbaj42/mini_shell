#include "shell.h"

char    *read_command(void) {
    char    *input;

    input = readline("Minishell_Edi_and_Maja$ ");
    if(input)
        return(input);
        //add_history();
    
    return(NULL);
}