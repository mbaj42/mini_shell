/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:36:21 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/23 23:15:58 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int    ft_is_only_whitespaces(char *str)
{
    int     i;

    i = 0;
    while(str[i] != '\0')
    {
        if(!ft_is_white_space(str[i]))
            return(0);
        i++;
    }
    return(1);
}

bool    ft_is_white_space(char c)
{
   if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
        return(true);
    return(false);
}

void    ft_skip_spaces(char **s)
{
    if(**s)
    {
        while(**s == '\t' || **s == '\n' || **s == '\v' || **s == '\f'
		|| **s == '\r' || **s == ' ')
            (*s)++;
    }
}