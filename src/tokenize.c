/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:36:27 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/29 19:03:17 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/shell.h"

static int	skip_quotes(const char *input, int i)
{
	char	quote;

	quote = input[i];
	i++;
	while (input[i] && input[i] != quote)
		i++;
	if (input[i])
		i++;
	return (i);
}

static int     process_word(const char *str, int i)
{
    while(str[i])
    {
        if(str[i] == '\"' || str[i] == '\'')
            return(skip_quotes(str, i));
        else if(ft_is_white_space(str[i]) || ft_strchr("><|", str[i]))
            break;
        i++;
    }
    return(i);
}

static t_tokens	*allocate_token_value(t_tokens *token, const char *input,
		int length)
{
	token->value = (char *)malloc(length + 1);
	if (!token->value)
		return (NULL);
	ft_strncpy(token->value, (char *)input, length);
	token->value[length] = '\0';
	return (token);
}
t_tokens	*update_token_word(t_tokens *token, char *input, int type)
{
	int	i;

	i = 0;
	i = process_word(input, i);
	if (!allocate_token_value(token, input, i))
		return (NULL);
	token->type = type;
	return (token);
}

// Znajduje pierwsze "słowo" w input.
// Kopiuje je do tokena (token->value).
// Ustawia typ tokena (token->type).
// Zwraca zaktualizowany token.

t_tokens *update_tokens(t_tokens *token, char *input, int type)
{
    if (token->value)
		free(token->value);
    token->value = malloc(ft_strlen(input) + 1);
    if(!token->value)
        return(NULL);
    ft_strncpy(token->value, input, ft_strlen(input));
    token->value[ft_strlen(input)] = '\0';
    token->type = type;
    return(token);
}