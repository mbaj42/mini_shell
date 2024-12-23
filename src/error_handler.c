/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:35:39 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/23 22:50:02 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void	ft_free_token_list(t_tokens **token_list)
{
    t_tokens *temp;
    t_tokens *temp_next;

    if (!token_list || !*token_list)
        return;

    temp = *token_list;
    while (temp)
    {
        temp_next = temp->next;
        if (temp->value)
        {
            free(temp->value);
            temp->value = NULL;
        }
        free(temp);
        temp = temp_next;
    }
    *token_list = NULL;
}

// void free_env(t_env *env) //musiałam dodać bo robię część z builtin "env" więc też alokuje pamięć i kopuje oryginalny env do naszego stworzonego bo robię przypadek dla builtin gdzie musi wypisać posortowane alfabetycznie env... Polecam!
// {
//     int i = 0;
//     if (!env)
//         return;
//     while (env[i].key)
//     {
//         free(env[i].key);
//         free(env[i].value);
//         i++;
//     }
//     free(env);
// }

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
        ft_free_token_list(&(*minishell)->tokens);
    if((*minishell)->commands)
        //funkcja do czyszczenia komend;
    //if((*minishell)->env && is_crash)
        // funkcja do czyszczenia tych zmiennych środowiskowych, ale tylko, gdy jest awaria
    if (is_crash)
    {
        free(*minishell);
        *minishell = NULL; // usuwamy wskaźnik na miejsce w pamięci, którego już z nami nie ma RIP
    }
}