#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_tokens t_tokens; // Deklaracja typu

typedef struct s_data {
    char        *input;    // Wczytane wejście
    t_tokens    *tokens;   // Lista tokenów
}               t_data;

enum token_type {
    WORD,        // Reprezentuje słowa (np. polecenia lub argumenty)
    PIPE,        // Symbol '|'
    REDIRECT_IN, // Symbol '<' (przekierowanie wejścia)
    REDIRECT_OUT,// Symbol '>' (przekierowanie wyjścia)
    APPEND,      // Symbol '>>' (przekierowanie wyjścia w trybie dopisywania)
    HEREDOC,     // Symbol '<<' (heredoc)
    END,         // Koniec tokenów (np. EOF)
    INVALID      // Błędny lub nierozpoznany token
};

typedef enum token_type t_token_type;

// Definicja struktury s_tokens (jedna, bez duplikatów)
typedef struct s_tokens {
    t_token_type    type;  // Typ tokena
    char            *value; // Wartość tokena
    struct s_tokens *next;  // Wskaźnik do następnego tokena
    struct s_tokens *prev;  // Wskaźnik do poprzedniego tokena
} t_tokens;

// typedef struct s_data
// {
// 	char			*input;
// 	char			**envir; // zmienne środowiskowe
// 	int				stdin;
// 	int				stdout;
// 	t_tokens		*tokens;
// 	t_env			*env;
// 	t_command_full	*commands;
// 	struct termios	terminal;
// 	struct s_data	*next;
// }					t_data;



typedef enum token_type t_token_type;
/*tokeny*/
t_tokens *create_token(int type, char *value);
void add_token_to_list(t_tokens **tokens, t_tokens *new_token);
t_tokens *finall_tokenize_input(char *input);



void	display_prompt(void);
char	*read_command(void);

/*PARSING PART*/
t_data	*tokenize_input(char *line, t_data *data);
char	*trim_input(char *line);
bool	is_input_valid(char *line);

/*ERROR HANDLER*/
void	ft_handle_error(const char *msg);


// void    execute_command(const char *command);

#endif