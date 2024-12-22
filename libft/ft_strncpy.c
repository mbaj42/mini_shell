/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:23:44 by mbaj              #+#    #+#             */
/*   Updated: 2024/12/22 17:27:32 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

	i = 0;
    while (i < n && src[i] != '\0')// Copy characters from src to dest until n is reached or src ends
	{
        dest[i] = src[i];
        i++;
    }
    while (i < n)// Pad with null characters if src has fewer than n characters
	{
        dest[i] = '\0';
        i++;
    }
    return dest;
}