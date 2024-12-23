/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:35:26 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/20 20:40:48 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

//✅ 
void    append_token(t_tokens **tokens, t_tokens *new_token)
{
    t_tokens *current;
    if(*tokens == NULL)
    {
        new_token->prev = NULL;
        *tokens = new_token;
    }
    else
    {
        current = *tokens;
        while(current->next != NULL)
            current = current->next;
        current->next = new_token;
        new_token->prev = current;
    }
    new_token->next = NULL;
}

//✅ 
//inicjalizujemy strukturę tokeny
int	init_tokens(t_data **minishell)
{
    char    *string;
    t_tokens *token;

    token = NULL;
    string = (*minishell)->input;
    if(!string || ft_is_only_whitespace(string) || ft_strlen(string) == 0)
    {
            return(200);
    }
    while(string && *string)
    {
        ft_skip_spaces(&string);
        token = get_token(string);
        if(token)
        {
            append_token(&((*minishell)->tokens), token);
            // Przesuń wskaźnik string o długość wartości tokena
            string += ft_strlen(token->value);
        }
        if (!token)
            break;
    }
    return(200);
}


//✅ 
t_tokens	*get_token(char *input)
{
    t_tokens *token;

    token = (t_tokens *)malloc(sizeof(t_tokens));
    if(!token)
        return(NULL);
    token->value = NULL;
    token->next = NULL;
    token->type = NULL;
    if(*input)
    {
        if(ft_strncmp(">>", input, 2) == 0)
            update_tokens(token, ">>", T_DGREAT);
        else if(ft_strncmp("<<", input, 2) == 0)
            update_tokens(token, "<<", T_DLESS);
        else if(*input == "<")
            update_tokens(token, "<", T_LESS);
        else if(*input == ">")
            update_tokens(token, ">", T_GREAT);
        else if(*input == "|")
            update_tokens(token, "|", T_PIPE);
        else
            update_tokens(token, input, T_WORD);
    }
    free(token);
    return(NULL);
}

//✅ 
t_tokens *update_tokens(t_tokens *token, char *input, int type)
{
    token->value = malloc(ft_strlen(input) + 1);
    if(!token->value)
        return(NULL);
    ft_strncpy(token->value, input, ft_strlen(input));
    token->value[ft_strlen(input)] = '\0';
    token->type = type;
    return(token);
}

//✅ 
char    *ft_strncpy(char *dst, char *src, int num)
{
    int     i;

    i = 0;
    if(!dst || !src)
        return(NULL);
    while(src[i] != '\0' && i < num)
    {
        dst[i] = src[i];
        i++;
    }
    while(i < num)
    {
        dst[i] = '\0';
        i++;
    }
    return(dst);
}

int	ft_is_only_whitespace(char *str)
{
	while (*str)
	{
		if (!ft_is_whitespace(*str))
			return (0);
		str++;
	}
	return (1);
}