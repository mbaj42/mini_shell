/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:53:10 by ecymer            #+#    #+#             */
/*   Updated: 2025/02/05 20:47:34 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define MAX_TOKENS 100

# include "tokens.h"

typedef struct s_command_full	t_command_full;
typedef struct s_redir			t_redir;

struct							s_redir
{
	t_token_type				type;
	char						*file_name;
	int							*fd;
	char						*value;
	t_redir						*next;
	t_redir						*prev;
};

struct							s_command_full
{
	char						*cmd_name;
	char						**args;
	int							fd_out;
	int							fd_in;
	char						*here_doc;
	t_redir						*redir_list_head;
	t_command_full				*next;
	t_command_full				*prev;
};

t_command_full					*init_command_structure(t_command_full *prev_cmd);
char							**append_string_to_array(char **str,
									char **array);
int								size_of_array(char **array);

#endif