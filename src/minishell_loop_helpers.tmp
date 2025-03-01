/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:35:46 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/29 19:01:18 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/shell.h"

//✅ 
bool	handle_whitespace_or_syntax(t_data **minishell)
{
    if (ft_is_only_whitespaces((*minishell)->input))
	{
		free((*minishell)->input);
		return (true);
	}
    if(is_input_valid((*minishell)->input) == false)
    {
        free((*minishell)->input);
        ft_handle_error("Minihell_Maja_Edyta: syntax error");
        return(true);
    }
    if (!ft_is_only_whitespaces((*minishell)->input))
	    add_history((*minishell)->input);
        //biblioteka readline
    return(false);
}

//❌ 
bool	process_tokens(t_data **minishell)
{
    init_tokens(minishell); // ✅ 
    if (validate_tokens((*minishell)->tokens) < 0)
	{
		ft_handle_error("Token validation failed: syntax error detected.");
		return (false);
	}
    //parsuje je i rozszerza o zmienne środowiskowe
    //obsługuje przekierowania < i >
    // zwraca true, jeśli wszystko się powiedzie
    return(true);
}

// ✅ 
bool    handle_empty_input(t_data **minishell)
{
    if(!(*minishell)->input)
    {
        ft_free_minishell(minishell, true);
        printf("exit\n");
        return(true);
    }
    return(false);
}
