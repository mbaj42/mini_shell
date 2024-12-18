/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:35:11 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/18 14:35:14 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

//✅ 
static void init_minishell(t_data **minishell, char **envp)
{

    minishell = (t_data *)malloc(sizeof(t_data));
    (*minishell)->input = NULL;
    (*minishell)->commands = NULL;
    (*minishell)->tokens = NULL;
    (*minishell)->envir = envp;
    (*minishell)->stdin = dup(0);
	(*minishell)->stdout = dup(1);
    tcgetattr(STDIN_FILENO, &(*minishell)->terminal);
}

//✅ 
void	reset_echoctl(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	if (!(term.c_lflag & ECHOCTL))
	{
		term.c_lflag |= ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
	}
}

//❌ 
void	minishell_loop(t_data **minishell)
{
    while(1)
    {
        //✅ 
        ft_free_minishell(minishell, false);
        /*Gdy wywołujesz ft_free_minishell(minishell, false);, program:
        Wie, że ma usunąć tylko dane tymczasowe (np. input, tokens), ale zachować zmienne środowiskowe i główną strukturę minishell.*/
        (*minishell)->input = readline(PROMPT);
        //✅ 
        reset_echoctl();
        if(handle_empty_input(minishell))
            break;
        if(handle_whitespace_or_syntax(minishell))
            continue;
        if(process_tokens(minishell))
        {
            //execute_commands(minishell);
        }
    }
}

//❌ 
int main(int argc, char **argv, char **envp) {
    
    char        *input;
    t_data      *minishell;
    t_tokens    *tokens;
    (void)argc;
    (void)argv;
    (void)envp;
    init_minishell(&minishell, envp);
    //setup_signal_handlers();
	//disable_echoctl();
	//init_environment(&minishell, minishell->envir);
    minishell_loop(&minishell);
    //cleanup_shell(shell);
        return(0);
}