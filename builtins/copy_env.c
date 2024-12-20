/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:42:17 by mbaj              #+#    #+#             */
/*   Updated: 2024/12/20 17:30:13 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

/*int	main(int argc, t_data *minishell, char **ev)
{
	t_env	tmp;
	bool	is_crush;
	int		i;

	(*minishell).env = malloc((strlen(ev) + 1) * sizeof(char **));
	if (!((*minishell).env))
		return (ft_free_minishell((*minishell), is_crush));
	i = 0;
	tmp = (*minishell).env[i];
	for (int i = 0; &(*minishell).env[i]; i++)
	{ // dst   // src        // Adres 8    -  4
		// alloc key i val
		strncpy((*minishell).env[i].key, ev[i], strchr(ev[i], '=') - ev[i]);
		strcpy((*minishell).env[i].value, strchr(ev[i], '=') + 1);
		(*minishell).env = (*minishell).env->next;
	}
	(*minishell).env[i] = tmp;
}*/

int	main(int argc, t_data **minishell, char **ev)
{
	int ev_count;
	int i;
	char *delimiter;
	int key_lenght;
	int value_lenght;

	ev_count = 0;
	if (!ev || !(*ev))
		return (3);
	while (ev[ev_count])
		ev_count++;
	(*minishell)->env = malloc((ev_count + 1) * sizeof(t_env));
	if (!(*minishell)->env)
	{
		ft_free_minishell(minishell, true);
		return (1);
	}
	i = 0;
	while (i < ev_count)
	{
		delimiter = strchr(ev[i], '=');
		if (delimiter)
		{
			key_lenght = delimiter - ev[i];
			(*minishell)->env->key = malloc((key_lenght + 1) * sizeof(char));
			if (!((*minishell)->env->key))
			{
				ft_free_minishell(minishell, true);
				return (2);
			}
			(*minishell)->env->value = malloc((ft_strlen(delimiter + 1) + 1) * sizeof(char));
			if (!((*minishell)->env->value))
			{
				ft_free_minishell(minishell, true);
				return (2);
			}
			ft_strncpy((*minishell)->env[i].key, ev[i], key_lenght);
			(*minishell)->env[i].key[key_lenght] = '\0';
			ft_strcpy((*minishell)->env[i].value, delimiter + 1);
		}
		i++;
	}
	(*minishell)->env[ev_count].key = NULL;
	(*minishell)->env[ev_count].value = NULL;
	return (0);
}
