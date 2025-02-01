/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:24:42 by mbaj              #+#    #+#             */
/*   Updated: 2025/02/01 19:00:11 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static char	*find_key(t_env *tmp)
{
	while (tmp)
	{
		if (ft_strncmp(tmp->key, "PATH", 4) == 0)
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
}

static char	**put_path_to_string(t_env *envp, t_command_full *arg)
{
	t_env	*tmp;
	char	**path;
	char	**full_path;
	char	*command;
	int		i;
	int		j;

	path = NULL;
	full_path = NULL;
	tmp = envp;
	command = ft_strjoin("/", arg->cmd_name);
	if (find_key(tmp) != NULL)
	{
		path = ft_split(tmp->value, ':');
		i = 0;
		while (path[i++])
		{
			j = 0;
			*full_path = ft_strjoin(path[i][j], command);	// trzeba zapisać jako jeden string
			full_path++;
		}
		*full_path = ft_strdup("\0");
		return (full_path);
	}
	return (NULL);
}
int	check_execution(char **path_list, t_command_full *arg, t_env *envp, int i)
{
	if (execve(path_list[i], arg->args, envp) == -1)
	{
		printf(stderr, "Error executing %s: %s\n", path_list[i],
		strerror(errno));
		return (1);
	}
	return(0);
}

int	check_path(t_command_full *arg, t_env *envp)
{
	char	**path_list;
	int		i;
	char	*tmp;
	char	*tmp_path;

	path_list = NULL;
	tmp = NULL;
	tmp_path = NULL;
	i = 0;
	if (!ft_strchr(arg->cmd_name, '/'))  // check what the first command is is it path or command
	{
		path_list = put_path_to_string(envp, arg);
		while (path_list[i++])
		{
			tmp = ft_strjoin(path_list[i], "/");
			tmp_path = ft_strjoin(tmp, arg->cmd_name);
			if (access(tmp_path, X_OK) == 0)
				check_execution(path_list, arg, envp, i);
			free(tmp);
			free(tmp_path);
		}
	}
	else
		path_list = ft_strdup(arg->cmd_name);
	if (access(path_list[i], X_OK) == 0)
		check_execution(path_list, arg, envp, i);
	else
	{
		printf(stderr, "Not valid path %s: %s\n", path_list, strerror(errno));
		return (1);
	}
	return (0);
}


int	check_path(t_command_full *arg, t_env *envp)
{
	char	**path_list;
	int		i;
	char	*tmp_path;

	path_list = NULL;
	tmp_path = NULL;
	if (ft_strchr(arg->cmd_name, '/'))
	{
		if (access(path_list[i], X_OK) == 0)
			return (check_execution(&arg->cmd_name, arg, envp, 0));
		else
		{
			//when is not correct error
			return (1);
		}
	}
	path_list = put_path_to_string(envp, arg);
	if (!path_list)
		return (1);
	i = 0;
	while (path_list[i++])
	{
		tmp_path = ft_strdup(path_list[i]);
		if (access(tmp_path, X_OK) == 0)
		{
			
		}

	}
	else
	{
		printf(stderr, "Not valid path %s: %s\n", path_list, strerror(errno));
		return (1);
	}
	return (0);
}

void	check_type(t_command_full *arg, t_data **minishell, t_env **envp)
{
	if (is_builtin(arg->cmd_name) == true)
		builtin_commands(minishell, envp);
	else
		check_path(arg, envp);
}
