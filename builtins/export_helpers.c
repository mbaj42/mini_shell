/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:37:35 by mbaj              #+#    #+#             */
/*   Updated: 2025/02/22 18:47:30 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int	get_key_length(const char *argv)
{
	int len;

	len = 0;
	while (argv[len] && argv[len] != '=')
		len++;
	if (argv[len] == '=')
		len++;
	return (len);
}
