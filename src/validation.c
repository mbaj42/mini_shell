/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:36:10 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/18 14:36:13 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

bool    is_input_valid(char *str)
{
    int     i;

    i = 0;
    if(str[0] == '|')
        return(false);
    //else if (ft_quotes_are_closed(input_str, &i) == false)
		//return (false);
    else
        return(true);
}