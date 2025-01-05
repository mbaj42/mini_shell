/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:50:47 by mbaj              #+#    #+#             */
/*   Updated: 2025/01/05 16:57:15 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void	add_to_env(t_data **minishell, char *key, char *new_value)
{
	t_env	*tmp;
	t_env	*next;

	tmp = (*minishell)->env;
	while (tmp)
	{
		if (strncmp(tmp->key, key, sizeof (key)) == 0);
		{
			update_env_value(minishell, key, new_value);
			tmp = tmp->next;
			continue;
		}
		tmp = tmp->next;
	}
}

static char	*get_home_env_value(t_env *env, const char *key)
{
	while (env)
	{
		if (ft_strchr(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	write(2, "No HOME env found", 18);
	return (NULL);
}

static int	get_current_pwd(char *current_pwd)
{
	if (!getcwd(current_pwd, sizeof(current_pwd)))
	{
		write(2, "Error while getting current pwd", 32);
		return (1);
	}
	return (0);
}

static char	*find_home_env(t_data **minishell)
{
	char	*target_dir;

	target_dir = get_home_env_value((*minishell)->env, "HOME");
	if (!target_dir)
		return (NULL);
	return (target_dir);
}

int	cd_builtin(t_data **minishell)
{
	char	current_pwd[PATH_MAX];
	char	new_pwd[PATH_MAX];
	char	*target_directory;

	get_current_pwd(current_pwd);
	if (!(*minishell)->commands->args[1])
	{
		target_directory = find_home_env(minishell);
		if (!target_directory)
			return (1);
	}
	target_directory = (*minishell)->commands->args[1];
	if (!chdir(target_directory))
	{
		write(2, "the directory doesn't exist", 28);
		return (1);
	}
	add_to_env(minishell, "OLDPWD", current_pwd);
	if (!getcwd(new_pwd, sizeof(new_pwd)))
	{
		write(2, "Error while getting current pwd", 32);
		return (1);
	}
	add_to_env(minishell, "PWD", new_pwd);
	return (0);
}
