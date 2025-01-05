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
