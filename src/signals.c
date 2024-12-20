/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:52:16 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/20 18:47:39 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void    handle_sigint(int sig)
{
    (void)sig;

    write(1, "\n", 1);
    rl_on_new_line();                 // Informuje readline, że rozpoczęto nową linię
	rl_replace_line("", 0);           // Czyści aktualną linię w terminalu
	rl_redisplay();                  // ponownie wyświetla prompt
}
// wbudowane funkcje z biblioteki readline


void	setup_signal_handlers(void)
{
    struct sigaction	sa_int;
	struct sigaction	sa_quit;

	sa_int.sa_handler = handle_sigint;
	sa_int.sa_flags = 0;
	sigemptyset(&sa_int.sa_mask);
	sigaction(SIGINT, &sa_int, NULL);
	sa_quit.sa_handler = SIG_IGN;
	sa_quit.sa_flags = 0;
	sigemptyset(&sa_quit.sa_mask);
	sigaction(SIGQUIT, &sa_quit, NULL); 
}

//Po naciśnięciu Ctrl+C shell nie kończy działania, tylko czyści aktualną linię i wyświetla prompt od nowa.
// Po naciśnięciu Ctrl + \ nie wydarzy się NIC :D