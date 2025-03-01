/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:42:17 by mbaj              #+#    #+#             */
/*   Updated: 2025/02/27 20:11:01 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void	free_env(t_env *env)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	while (env->key)
	{
		free(env->key);
		free(env->value);
		i++;
	}
	free(env);
}
static int	malloc_env(t_data **minishell, char **ev, int i, char *delimiter)
{
	int	key_length;

	if (!(*minishell) || !((*minishell)->env))
		return (1);
	if (delimiter)
	{
		key_length = delimiter - ev[i];
		(*minishell)->env->key = malloc((key_length + 1) * sizeof(char));
		if (!((*minishell)->env->key))
		{
			free_env((*minishell)->env);
			return (2);
		}
		(*minishell)->env->value = malloc((ft_strlen(delimiter + 1) + 1)
				* sizeof(char));
		if (!((*minishell)->env->value))
		{
			free_env((*minishell)->env);
			return (3);
		}
		ft_strncpy((*minishell)->env->key, ev[i], key_length);
		(*minishell)->env->key[key_length] = '\0';
		ft_strcpy((*minishell)->env->value, delimiter + 1);
	}
	return (0);
}
static void terminate_env(t_data **minishell)
{
	while ((*minishell)->env->next != NULL)
		(*minishell)->env = (*minishell)->env->next;
	(*minishell)->env->key = NULL;
	(*minishell)->env->value = NULL;
}

int	copy_env(t_data **minishell, char **ev)
{
	int		ev_count;
	char	*delimiter;
	int		i;

	ev_count = 0;
	if (!ev || !(*ev))
		return (3);
	while (ev[ev_count])
		ev_count++;
	(*minishell)->env = malloc((ev_count + 1) * sizeof(t_env));
	if (!(*minishell)->env)
	{
		free_env((*minishell)->env);
		return (1);
	}
	i = 0;
	while (i < ev_count)
	{
		delimiter = ft_strchr(ev[i], '=');
		malloc_env(minishell, ev, i, delimiter);
		i++;
	}
	terminate_env(minishell);
	(*minishell)->env[ev_count].key = NULL;
	(*minishell)->env[ev_count].value = NULL;
	return (0);
}
