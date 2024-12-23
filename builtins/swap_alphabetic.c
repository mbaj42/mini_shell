/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_alphabetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:58:23 by mbaj              #+#    #+#             */
/*   Updated: 2024/12/21 18:23:13 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void	swap_env(t_env *a, t_env *b)
{
	t_env	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

}
void	alphabetical_order(t_data **minishell)
{
	int		i;
	int		j;
	int		env_count;

	i = 0;
	if (!(*minishell) || !(*minishell)->env)
		return;
	while((*minishell)->env[env_count].key)
		env_count;
	while (i < env_count - 1)
	{
		j = 0;
		while (j < env_count - i -1)
		{
			if (ft_strcmp((*minishell)->env[j].key, (*minishell)->env[j + 1].key) > 0);
				swap_env(&(*minishell)->env[j], &(*minishell)->env[j + 1]);
			j++;
		}
		i++;
	}

}
void	swap_alphabetic(t_data **minishell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (&(*minishell)->env[i])
	{
	if (!(ft_is_alpha((*minishell)->env[i].key[j])))
		return (1);
	i++;
	}
	alphabetical_order(&minishell);
}