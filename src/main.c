/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:35:11 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/29 20:17:43 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static void    init_minishell(t_data **minishell, char **envp)
{

    *minishell = (t_data *)malloc(sizeof(t_data));
    if(!minishell)
        ft_handle_error("Error init shell - malloc");
    (*minishell)->input = NULL;
    (*minishell)->commands = NULL;
    (*minishell)->tokens = NULL;
    (*minishell)->envir = envp;
    (*minishell)->stdin = dup(0);
	(*minishell)->stdout = dup(1);
    tcgetattr(STDIN_FILENO, &(*minishell)->terminal);
}
 
void	reset_echoctl(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	minishell_loop(t_data **minishell)
{
    while(1)
    {
        ft_free_minishell(minishell, false);
        (*minishell)->input = readline(PROMPT);
        if (!(*minishell)->input)
        {
            ft_free_minishell(minishell, true);
            printf("exit\n");
            break;
        }
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

int	main(int argc, char **argv, char **env)
{
	t_data	*minishell;

	(void)argc;
	(void)argv;
	init_minishell(&minishell, env);
	setup_signal_handlers();
	reset_echoctl();
	//init_environment(&minishell, minishell->envir);
	minishell_loop(&minishell);
	return (0);
}
