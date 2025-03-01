/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:35:39 by ecymer            #+#    #+#             */
/*   Updated: 2025/02/22 16:19:24 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void	ft_free_token_list(t_tokens **token_list)
{
	t_tokens	*temp;
	t_tokens	*temp_next;

	if (!token_list || !*token_list)
		return ;
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

//❌
void	ft_free_minishell(t_data **minishell, bool is_crash)
{
	if (!(*minishell))
		return ; // jak nic nie ma, wychodzimy z funkcji i narka
	if ((*minishell)->input)
		(*minishell)->input = NULL;
	if ((*minishell)->tokens)
		ft_free_token_list(&(*minishell)->tokens);
	// if((*minishell)->commands)
	// czyści komendy i przekierowania
	// if((*minishell)->env && is_crash)
	// funkcja do czyszczenia tych zmiennych środowiskowych, ale tylko,
	//gdy jest awaria
    if (is_crash)
	{
		free(*minishell);
		*minishell = NULL; // usuwamy wskaźnik na miejsce w pamięci,
		//którego już z nami nie ma RIP
	}
}
