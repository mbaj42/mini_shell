#include "shell.h"

char    *read_command(void) {
    char    *input;

    input = readline("");
    if(input)
    {
        //add_history();
    }
    return(input);
}