/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:36:36 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/23 23:35:36 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

bool is_quote_closed(const char *input) {
    char quote_type;
    int     i;
    
    quote_type = '\0'; 
    i = 0;
    while (input[i] != '\0')
    {
        if (quote_type == '\0') 
        {
            if (input[i] == '\'' || input[i] == '"')
                quote_type = input[i]; 
        }
        else
        {
            if (input[i] == quote_type) 
                quote_type = '\0';
        }
        i++;
    }
    return (quote_type == '\0');
}

bool    is_input_valid(char *line)
{
    if (!line || ft_strlen(line) == 0)
        return false; // Pusty ciąg nie jest poprawny
    if(line[0] == '|')
        return(false);
    if(line[ft_strlen(line) - 1] == '|')
        return(false);
    if(!is_quote_closed(line))
        return(false);
    return(true);
}

bool    check_input(char *line)
{
    if(!is_input_valid(line))
    {
        ft_handle_error("Input is not valid");
        return(false);
    }  
    return(true);
}