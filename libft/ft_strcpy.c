/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:23:54 by mbaj              #+#    #+#             */
/*   Updated: 2024/12/22 19:24:45 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void ft_strcpy(char *dest, const char *src)
{
    while (*src != '\0')
	{
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Add the null terminator at the end
}
