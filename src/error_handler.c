/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:35:39 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/20 15:22:43 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "shell.h"

void    ft_handle_error(const char *msg)
{
    printf("ERROR: %s\n", msg);
    exit(1);
}
void free_env(t_env *env) //musiałam dodać bo robię część z builtin "env" więc też alokuje pamięć i kopuje oryginalny env do naszego stworzonego bo robię przypadek dla builtin gdzie musi wypisać posortowane alfabetycznie env... Polecam!
{
    int i = 0;
    if (!env)
        return;
    while (env[i].key)
    {
        free(env[i].key);
        free(env[i].value);
        i++;
    }
    free(env);
}
//❌
void    ft_free_minishell(t_data **minishell, bool is_crash)
{
    if(!(*minishell))
        return ; // jak nic nie ma, wychodzimy z funkcji i narka
    if((*minishell)->input)
        (*minishell)->input = NULL;
    if((*minishell)->tokens)
        //funkcja do czyszczenia tokenów;
    if((*minishell)->commands)
        //funkcja do czyszczenia komend;
    if((*minishell)->env && is_crash)
        free_env((*minishell)->env);// funkcja do czyszczenia tych zmiennych środowiskowych, ale tylko, gdy jest awaria
    if (is_crash)
    {
        free(*minishell);
        *minishell = NULL; // usuwamy wskaźnik na miejsce w pamięci, którego już z nami nie ma RIP
    }
}