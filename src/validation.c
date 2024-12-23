/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:36:10 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/20 20:20:21 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

bool	has_valid_quotes(char *str, int *i)
{
    bool  result;
    char  quote;

    result = true;
    while (str[*i])
    {
        if (str[*i] == '\'' || str[*i] == '\"')
        {
            result = false;
            quote = str[*i];
            (*i)++;
            while (str[*i])
            {
                if (str[*i] == quote)
                {
                    result = true;
                    break ;
                }
                (*i)++;
            }
        }
        (*i)++;
    }
    return (result);
}

bool    is_input_valid(char *str)
{
    int     i;

    i = 0;
    if(str[0] == '|')
        return(false);
    else if (has_valid_quotes(str, &i) == false)
		    return (false);
    else
        return(true);
}