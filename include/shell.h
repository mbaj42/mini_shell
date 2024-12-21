/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:36:50 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/21 16:52:13 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>
# define PROMPT "Minihell_Maja_Edyta > "

# ifndef ECHOCTL
#  define ECHOCTL 0001000
# endif

typedef struct s_data
{
	char			*input;
	char			**envir;
	int				stdin;
	int				stdout;
	t_tokens		*tokens;
	t_env *env;               // do manipulacji zmiennych środowiskowcyh
	t_command_full *commands; // przechowuje przetworzone polecenia
	struct termios terminal;  // do zarządzania ustawieniami terminala
	struct s_data	*next;
}					t_data;

typedef struct s_env
{
	char			value;
	char			*key;
	struct s_env	*next;
}					t_env;

typedef struct	s_command_full
{
	char			*cmd_name;
	char			**args;
	int				fd_out;
	int				fd_in;
	char			*here_doc;
	t_redir			*redir_list_head;
	t_command_full	*next;
	t_command_full	*prev;
}					t_command_full;

typedef struct s_tokens
{
	t_token_type	type;
	char			*value;
	struct s_tokens	*next;
	struct s_tokens	*prev;
}					t_tokens;

typedef enum e_token_type
{
	T_WORD,
	T_LESS,
	T_GREAT,
	T_DLESS,
	T_DGREAT,
	T_PIPE,
}			t_token_type;

void				minishell_loop(t_data **minishell);
static void			init_minishell(t_data **minishell, char **envp);
void				reset_echoctl(void);
bool				handle_empty_input(t_data **minishell);

// error handler
void				ft_free_minishell(t_data **minishell, bool is_crash);
void				ft_handle_error(const char *msg);
bool				handle_whitespace_or_syntax(t_data **minishell);
//

// tokeny
bool				process_tokens(t_data **minishell);
int					init_tokens(t_data **minishell);
t_tokens			*get_token(char *input);
t_tokens			*update_tokens(t_tokens *token, char *input, int type);
void				append_token(t_tokens **tokens, t_tokens *new_token);

// help
char				*ft_strncpy(char *dst, char *src, int num);
bool				check_input(const char *line);
bool				is_input_valid(const char *line);
static bool			has_valid_quotes(char *str, int *i);

#endif