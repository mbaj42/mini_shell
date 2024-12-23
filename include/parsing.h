/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:53:10 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/23 22:53:10 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PARSING_H
# define PARSING_H

# define MAX_TOKENS 100

typedef struct s_command_full	t_command_full;
typedef struct s_redir			t_redir;

struct	s_redir
{
	t_token_type	type;
	char			*file_name;
	int				*fd;
	char			*value;
	t_redir			*next;
	t_redir			*prev;
};

struct	s_command_full
{
	char			*cmd_name;
	char			**args;
	int				fd_out;
	int				fd_in;
	char			*here_doc;
	t_redir			*redir_list_head;
	t_command_full	*next;
	t_command_full	*prev;
};

#endif