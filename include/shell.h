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
	t_env			*env;
	t_command_full	*commands;
	struct termios	terminal;
	struct s_data	*next;
}					t_data;

typedef struct s_tokens
{
	t_token_type	type;
	char			*value;
	struct s_tokens	*next;
	struct s_tokens	*prev;
}					t_tokens;

// typedef enum e_token_type
// {
// 	T_WORD,
// 	T_LESS,
// 	T_GREAT,
// 	T_DLESS,
// 	T_DGREAT,
// 	T_PIPE,
// }

char    *read_command(void);
void    ft_handle_error(const char *msg);

/*check input*/
bool    check_input(const char *line);
bool    is_input_valid(const char *line);
bool is_quote_closed(const char *input);

/*tokenizacja*/
char **tokenize_input(const char *input);
#endif