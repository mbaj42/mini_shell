/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:53:33 by mbaj              #+#    #+#             */
/*   Updated: 2024/12/30 19:37:08 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void	delete_node(t_env **head, t_env *node_to_delete)
{
	t_env	*prev;
	t_env	*tmp;

	tmp = *head;
	prev = NULL;
	if (tmp && tmp == node_to_delete)
	{
		*head = tmp->next;  //jeśli pierwszy node jest nodem do usunięcia to musimy ustawić head na kolejny node.. żeby mieć pointer na nasz nowy pierwszy node w szyku.
		free(tmp->value);
		free(tmp->key);
		free(tmp);
		return;
	}
	while (tmp && tmp != node_to_delete)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return;
	prev->next = tmp->next;
	free(tmp->value);
	free(tmp->key);
	free(tmp);
}

int	unset_builtin(t_data **minishell)
{
	int	i;
	t_env	*tmp;

	i = 1;
	if (!((*minishell)->commands->args) || !((*minishell)->commands->args[1]))
		return(0);
	while ((*minishell)->commands->args[i])
	{
		tmp = (*minishell)->env;
		while (tmp)
		{
			if(ft_strcmp(tmp->key, (*minishell)->commands->args[i]) == 0)
			{
				delete_node(&(*minishell)->env, tmp);//deletenodefunction
				break;
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}