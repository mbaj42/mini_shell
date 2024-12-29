/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:36:50 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/29 19:02:20 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <signal.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "../printf/ft_printf.h"
# include "../libft/libft.h"
# include "tokens.h"
# include "parsing.h"

# define PROMPT "Minihell_Maja_Edyta > "

# ifndef ECHOCTL
#  define ECHOCTL 0001000
# endif

extern int	g_last_exit_status;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_data
{
	char			*input;
	char			**envir;
	int				stdin;
	int				stdout;
	t_tokens		*tokens;
	t_env			*env;
	t_command_full	*commands;
	struct termios	terminal;
	struct s_data	*next;
}					t_data;

void				minishell_loop(t_data **minishell);
void				init_minishell(t_data **minishell, char **envp);
void				reset_echoctl(void);
bool				handle_empty_input(t_data **minishell);

// error handler
void				ft_free_token_list(t_tokens **token_list);
void				ft_handle_error(const char *msg);
bool				handle_whitespace_or_syntax(t_data **minishell);
void				free_env(t_env *env);
void				ft_free_minishell(t_data **minishell, bool is_crash);

// tokeny
bool				process_tokens(t_data **minishell);
int					init_tokens(t_data **minishell);
t_tokens			*get_token(char *input);
t_tokens			*update_tokens(t_tokens *token, char *input, int type);
void				append_token(t_tokens **tokens, t_tokens *new_token);
t_tokens			*update_token_word(t_tokens *token, char *input, int type);
int					validate_tokens(t_tokens *tokens);

// help
char				*ft_strncpy(char *dst, char *src, int num);
bool				check_input(char *line);
bool				is_input_valid(char *line);
bool				has_valid_quotes(char *str, int *i);
bool				is_quote_closed(const char *input);
int					ft_is_only_whitespaces(char *str);
bool				ft_is_white_space(char c);
void				ft_skip_spaces(char **s);
//
void				setup_signal_handlers(void);
void				handle_sigint(int sig);
#endif