/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:52:11 by mbaj              #+#    #+#             */
/*   Updated: 2025/02/28 20:44:12 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static int	export_no_args(t_data **minishell, char **ev)
{
	t_env	*tmp;

	copy_env(minishell, ev);
	swap_alphabetic(minishell);
	tmp = (*minishell)->env;
	while (tmp)
	{
		write(1, "declare -x ", 11);
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
static int	is_only_key(t_command_full *command, t_env *env)
{
	int	key_length;

	key_length = ft_strlen(*command->args) + 1;
	env->key = malloc((key_length) * sizeof(char));
	if (!env->key)
	{
		free_env(env);
		return (2);
	}
	ft_strncpy(env->key, *command->args, key_length);
	env->value = malloc((1) * sizeof(char));
	if (!env->value)
	{
		free_env(env);
		return (2);
	}
	ft_strcpy(env->value, "");
	if (command->next == NULL)
	{
		env->next->key = NULL;
		env->next->value = NULL;
		return (3);
	}
	return (0);
}
static int add_key_value(char *arg, t_env **env)
{
	char *equal_sign = strchr(arg, '=');
	if (!equal_sign)
		return -1; // Invalid format
	t_env *new_node = malloc(sizeof(t_env));
	if (!new_node)
		return -1; // Allocation failure
	new_node->key = strndup(arg, equal_sign - arg);
	new_node->value = strdup(equal_sign + 1);
	new_node->next = NULL;

	if (!new_node->key || !new_node->value)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (-1);
	}
	if (!(*env))
	{
		*env = new_node;
		return 0;
	}
	t_env *current = *env;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return 0;
}

static int	no_equal_sign(t_command_full *command, t_env *env)
{
	int	result;

	result = is_only_key(command, env);
	if (result == 3)
		return (0);
	return (0);
}

int	export_builtin(t_data **minishell, char **ev)
{
	t_env			*tmp;
	t_command_full	*command;
	size_t			i;

	tmp = (*minishell)->env;
	command = (*minishell)->commands;
	if (!((*minishell)->commands->args[1]))
		return (export_no_args(minishell, ev));
	while (tmp->next)
		tmp = tmp->next;
	i = 1;
	while (command->args[i] != NULL)
	{
		if (!ft_strchr(command->args[i], '='))
			no_equal_sign(command, tmp);
		add_key_value(command->args[i], &tmp);
		i++;
	}
	return (0);
}
