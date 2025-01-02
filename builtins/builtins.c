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

// double check
int	builtin_commands(char **argv, t_env **env)
{
	t_command_full	*fd;

	if (strcmp(argv[1], "export") == 0)
		export_builtin(argv, env);
	if (strcmp(argv[1], "echo") == 0)
		echo_builtin(argv, fd->fd_out);
	return (0);
}
int	main(int argc, char **envp)
{
	char argv = {"export", '\0'};

	builtin_commands(&argv, &envp);
	return (0);
}
