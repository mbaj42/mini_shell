/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_alphabetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:58:23 by mbaj              #+#    #+#             */
/*   Updated: 2025/02/28 18:41:45 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void	alphabetical_order(t_env **env)
{
	t_env	*current;
	t_env	*prev;
	t_env	*next;
	int		swapped;

	if (!env || !(*env) || !(*env)->next)
		return ;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		prev = NULL;
		current = *env;

		while (current && current->next)
		{
			next = current->next;
			if (ft_strcmp(current->key, next->key) > 0)
			{
				// Swap nodes instead of just values
				current->next = next->next;
				next->next = current;

				if (prev)
					prev->next = next;
				else
					*env = next;

				swapped = 1;
				prev = next;
			}
			else {
				prev = current;
				current = current->next;
			}
		}
	}
}
void	swap_alphabetic(t_data **minishell)
{
	if (!(*minishell) || !(*minishell)->env)
		return ;
	alphabetical_order(&(*minishell)->env);
}