/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:25:25 by mbaj              #+#    #+#             */
/*   Updated: 2025/01/05 16:59:56 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void	update_env_value(t_data **minishell, char *key, char *new_value)
{
	t_env	*current;

	current = (*minishell)->env;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = ft_strdup(new_value);
			if (!current->value)
				ft_handle_error("Error updating env value");
			return ;
		}
		current = current->next;
	}
}
