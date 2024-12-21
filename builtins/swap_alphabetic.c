/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_alphabetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:58:23 by mbaj              #+#    #+#             */
/*   Updated: 2024/12/21 17:05:40 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void	alphabetical_order()
{
	
}
void	swap_alphabetic(t_data **minishell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*minishell)->env[i])
	{
	if (!(ft_is_alpha((*minishell)->env[i].key[j])))
		return (1);
	i++;
	}
	alphabetical_order();
}