/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:50:58 by mbaj              #+#    #+#             */
/*   Updated: 2024/12/23 18:49:54 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

bool	is_builtin(t_command_full *command)
{
	char		*name;
	int			i;
	const char	*builtins[] = {"cd", "echo", "env", "exit", "export", "pwd",
			"unset", NULL};

	i = 0;
	if (!command->args || command->args[0])
		return (false);
	name = command->cmd_name;
	while (builtins[i])
	{
		if (ft_strcmp(name, builtins[i]) == 0)
			return (true);
		i++;
	}
	return (false);
}
int	builtin_commands(t_data **minishell, t_env **env)
{
	t_command_full	*fd;

	if (strcmp((*minishell)->commands->cmd_name, "export") == 0)
		export_builtin((*minishell)->commands->args, env);
	if (strcmp((*minishell)->commands->cmd_name, "echo") == 0)
		echo_builtin((*minishell)->commands->args, fd->fd_out);
	if (strcmp((*minishell)->commands->cmd_name, "exit") == 0)
		exit_builtin((*minishell)->commands->args);
	if (strcmp((*minishell)->commands->cmd_name, "unset") == 0)
		unset_builtin((*minishell)->commands->args);
	if (strcmp((*minishell)->commands->cmd_name, "pwd") == 0)
		pwd_builtin((*minishell)->commands->args);
	if (strcmp((*minishell)->commands->cmd_name, "cd") == 0)
		cd_builtin((*minishell)->commands->args);
	return (0);
}
/*
int	main(int argc, char **envp)
{
	char	argv;

	argv = {"export", '\0'};
	builtin_commands(&argv, &envp);
	return (0);
}*/
