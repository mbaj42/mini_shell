/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:36:50 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/20 13:51:50 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
# include <termios.h>

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
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
	t_env			*env; // do manipulacji zmiennych środowiskowcyh
	t_command_full	*commands; // przechowuje przetworzone polecenia
	struct termios	terminal; // do zarządzania ustawieniami terminala
	struct s_data	*next;
}					t_data;

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
};

void	minishell_loop(t_data **minishell);
static void init_minishell(t_data **minishell, char **envp);
void	reset_echoctl(void);
bool    handle_empty_input(t_data **minishell);


// error handler
void    ft_free_minishell(t_data **minishell, bool is_crash);
void    ft_handle_error(const char *msg);
bool	handle_whitespace_or_syntax(t_data **minishell);
//


//tokeny
bool	process_tokens(t_data **minishell);
int	init_tokens(t_data **minishell);
t_tokens	*get_token(char *input);
t_tokens *update_tokens(t_tokens *token, char *input, int type);
void    append_token(t_tokens **tokens, t_tokens *new_token);

//help
char	*ft_strncpy(char *dst, char *src, int num);
bool	check_input(const char *line);
bool	is_input_valid(const char *line);
static bool	has_valid_quotes(char *str, int *i);


#endif