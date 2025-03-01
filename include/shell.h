/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:36:50 by ecymer            #+#    #+#             */
/*   Updated: 2025/02/28 21:58:54 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "parsing.h"
# include "tokens.h"
# include <errno.h>
# include <fcntl.h>
# include <linux/limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define PROMPT "Mini_hell_Maja_Edyta > "
# define HEREDOC_PROMPT "> "

# ifndef ECHOCTL
#  define ECHOCTL 0001000
# endif

extern int			g_last_exit_status;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_data
{
	char			*input;
	int				stdin;
	int				stdout;
	t_tokens		*tokens;
	t_env			*env;
	t_command_full	*commands;
	struct termios	terminal;
	struct s_data	*next;
}					t_data;

void				minishell_loop(t_data **minishell);
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

int					check_path(t_command_full *arg, t_env *envp);

// help
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

// tmp
char				*find_key(t_env *tmp);
void				ft_free_array(char **array);
bool				is_builtin(t_command_full *command, t_env **env);
t_data				*fill_parsing(char **env);
int					builtin_commands(t_data *minishell, char **ev);
void				echo_command(char **argv, int fd_out);
int					pwd_builtin(void);
void				update_env_value(t_data **minishell, char *key,
						char *new_value);
int					cd_builtin(t_data **minishell);
int					exit_builtin(t_data **minishell);
int					export_builtin(t_data **minishell, char **ev);
void				swap_alphabetic(t_data **minishell);
//void				alphabetical_order(t_data **minishell);
void				swap_env(t_env *a, t_env *b);
char				*read_heredoc_line(char *limiter);
char				*execution_heredoc(char *limiter);
int					copy_env(t_data **minishell, char **ev);
int					get_key_length(const char *argv);
void				alphabetical_order(t_env **env);

//tmp
int	env_builtin(t_env *node);
int	unset_builtin(t_data **minishell);
void	delete_node(t_env **head, t_env *node_to_delete);
#endif