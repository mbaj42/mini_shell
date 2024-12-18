/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:35:39 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/18 14:35:41 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "shell.h"

void    ft_handle_error(const char *msg)
{
    printf("ERROR: %s\n", msg);
    exit(1);
}

//❌ 
void    ft_free_minishell(t_data **minishell, bool is_crash)
{
    if(!(*minishell))
        return(NULL); // jak nic nie ma, wychodzimy z funkcji i narka
    if((*minishell)->input)
        (*minishell)->input = NULL;
    if((*minishell)->tokens)
        //funkcja do czyszczenia tokenów;
    if((*minishell)->commands)
        //funkcja do czyszczenia komend;
    if((*minishell)->env && is_crash)
        // funkcja do czyszczenia tych zmiennych środowiskowych, ale tylko, gdy jest awaria
    if (is_crash)
    {
        free(*minishell);
        *minishell = NULL; // usuwamy wskaźnik na miejsce w pamięci, którego już z nami nie ma RIP
    }
}