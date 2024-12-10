#include "../include/shell.h"

int main(int argc, char **argv, char **envp) {
    
    char        *input;
    //t_data      *shell;
    t_tokens    *tokens;
    (void)argc;
    (void)argv;
    (void)envp;
    //shell = init_minishell(envp);
    while(true)
    {
        input = read_command();
        if(!input)
            break;
        if(is_input_valid(input))
        {
            printf("%s\n", input);
            tokens = tokenize_input(input);
        }
            // execute(tokens);
            // free_tokens(tokens);
        else
            ft_handle_error("Invalid input");
        free(input);
    }
        //cleanup_shell(shell);
        return(0);
}