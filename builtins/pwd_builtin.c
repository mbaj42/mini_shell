/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:53:15 by mbaj              #+#    #+#             */
/*   Updated: 2024/12/23 17:52:03 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int	pwd_builtin(t_data **minishell)
{
	char current_path[PATH_MAX];

	if (getcwd(current_path, sizeof(current_path)))
	{
		ft_putstr_fd(current_path, 1);
		ft_putstr_fd("\n", 1);
	}
	else
	{
		ft_putstr_fd("error with pwd_builtin function\n", 2);
		return (1);
	}
	return (0);
}