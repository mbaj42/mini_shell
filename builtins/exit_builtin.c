/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:52:45 by mbaj              #+#    #+#             */
/*   Updated: 2024/12/29 18:04:38 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int	exit_builtin(t_data **minishell)
{
	rl_clear_history();
	ft_free_minishell(minishell, true);
	exit(0);
}