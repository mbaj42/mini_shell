/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:52:11 by mbaj              #+#    #+#             */
/*   Updated: 2024/12/23 19:13:47 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static int	export_no_args(t_data **minishell, char **envp)
{
	int	i;

	i = 0;
	copy_env(minishell, envp);
	swap_alphabetic(&minishell);
	while (&(*minishell)->env[i])
	{
		write(1, "declare -x ", 11);
		printf("%s=%s\n", (*minishell)->env[i].key, (*minishell)->env[i].value);
		i++;
	}
}

static int	is_only_key(t_data **minishell, int	i, int	j)
{
	int	key_length;

	key_length = ft_strlen((*minishell)->commands->args[i]) + 1;
	(*minishell)->env[j].key = malloc((key_length) * sizeof(char));
	if (!(*minishell)->env[j].key)
	{
		free_env(&(*minishell)->env[j]);
		return (2);
	}
	(*minishell)->env[j].key = ft_strncpy((*minishell)->env[j].key,
				(*minishell)->commands->args[i], key_length);
	(*minishell)->env[j].value = malloc((1) * sizeof(char));
	if (!(*minishell)->env[j].value)
	{
		free_env(&(*minishell)->env[j]);
		return (2);
	}
	(*minishell)->env[j].value = ft_strcpy((*minishell)->env[j].value, "");
	if ((*minishell)->commands->args[i + 1] == '\0')
	{
		(*minishell)->env[j + 1].key = NULL;
		(*minishell)->env[j + 1].value = NULL;
		return (3);
	}
	return(0);
}
static int	add_key_value(t_data **minishell, int i, int j)
{
	int	key_length;
	int	value_length;

	key_length = ft_strchr((*minishell)->commands->args[i], '=')
			- (*minishell)->commands->args[i] + 1;
	(*minishell)->env[j].key = malloc((key_length) * sizeof(char));
	if (!(*minishell)->env[j].key)
	{
		free_env(&(*minishell)->env[j]);
		return (2);
	}
	(*minishell)->env[j].key = ft_strncpy((*minishell)->env[j].key,
				(*minishell)->commands->args[i], key_length);
	value_length = ft_strlen(ft_strchr((*minishell)->commands->args[i], '=')
				+ 1) + 1;
	(*minishell)->env[j].value = malloc(value_length * sizeof(char));
	if (!(*minishell)->env[j].value)
	{
		free_env(&(*minishell)->env[j]);
		return (2);
	}
	(*minishell)->env[j].value = ft_strncpy((*minishell)->env[j].value,
				(*minishell)->commands->args[i], value_length);
	return (0);
}
static int	no_equal_sign(t_data **minishell, int i, int j, int is_equal_sign)
{
	if (is_equal_sign = 1)
			{
				is_only_key(&(*minishell), i, j);
				if(is_only_key(&(*minishell), i, j) == 3)
					return (0);
			}
			else
				return (1);
	return (0);
}

int	export_builtin(t_data **minishell, char **envp)
{
	int	i;
	int	is_equal_sign;
	int	j;

	i = 1;
	is_equal_sign = 0;
	if (!((*minishell)->commands->args[1]))
		return (export_no_args(minishell, envp));
	j = 0;
	while (&(*minishell)->env[j])
		j++;
	while ((*minishell)->commands->args[i])
	{
		if (!(ft_strchr((*minishell)->commands->args[i], '=')))
			no_equal_sign(&(*minishell), i, j, is_equal_sign);
		else
			is_equal_sign = 1;
		add_key_value(&(*minishell), i, j);
		j++;
		i++;
	}
	(*minishell)->env[j].key = NULL;
	(*minishell)->env[j].value = NULL;
	return(0);
}
