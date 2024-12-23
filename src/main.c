/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:35:11 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/20 20:22:15 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

//✅ 
void    init_minishell(t_data **minishell, char **envp)
{

    *minishell = (t_data *)malloc(sizeof(t_data));
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
// Ten kod resetuje ustawienie terminala, żeby włączyć lub upewnić się, 
// że jest włączone coś zwanego ECHOCTL.
//To ustawienie mówi terminalowi, czy ma wyświetlać specjalne znaki kontrolne
// (np. ^C przy Ctrl+C) na ekranie.


//❌ 
void	minishell_loop(t_data **minishell)
{
    while(1)
    {
        //✅ 
        ft_free_minishell(minishell, false);
        (*minishell)->input = readline(PROMPT);
        if (!(*minishell)->input)
        {
            ft_free_minishell(minishell, true);
            printf("exit\n");
            break;
        }
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
    
    //char        *input;
    t_data      *minishell;
    //t_tokens    *tokens;
    (void)argc;
    (void)argv;
    init_minishell(&minishell, envp);
    setup_signal_handlers();
	reset_echoctl();
	//init_environment(&minishell, minishell->envir);
    minishell_loop(&minishell);
    //cleanup_shell(shell);
        return(0);
}

// (*minishell)->stdin = dup(0);
// (*minishell)->stdout = dup(1);
// W shellu (np. minishell) często wykonuje się operacje przekierowania, 
// które tymczasowo zmieniają standardowe wejście/wyjście:
// Przekierowanie wejścia (<): Zamiast czytać dane z terminala (deskryptor 0), program czyta z pliku.
// Przekierowanie wyjścia (>): Zamiast pisać dane na terminal (deskryptor 1), program zapisuje do pliku.
// Potoki (|): Wyjście jednego procesu jest przekierowywane jako wejście do innego.
// Po wykonaniu polecenia shell musi przywrócić standardowe deskryptory wejścia i wyjścia.


// tcgetattr(STDIN_FILENO, &(*minishell)->terminal);
// pobiera USTAWIENIA TERMINALA i zapisuje je w strukturze

/*Gdy wywołujesz ft_free_minishell(minishell, false);, program
Wie, że ma usunąć tylko dane tymczasowe (np. input, tokens), ale zachować zmienne środowiskowe i główną strukturę minishell.*/