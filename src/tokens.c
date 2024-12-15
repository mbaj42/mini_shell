#include "../include/shell.h"

//inicjalizujemy strukturę tokeny
int	init_tokens(t_data **minishell)
{
    char    *string;
    t_tokens *token;

    token = NULL;
    string = (*minishell)->input;
    if(!string || ft_is_only_white_spaces(string) || ft_strlen(string) == 0)
    {
            return(200);
    }
    while(string && *string)
    {
        ft_skip_spaces(&string);
        // pobieramy token
        // jeśli jest token to:
             // tworzymy noda i dodajemy tokena do listy
             // przesuwamy wskaźnik, by przeskoczyć np. na nowe słowo
    }

    //loop -> pomijamy nadmiar spacji
    token = get_token(string);
    //tworzenie noda i dopisywanie mu tokena
}

t_tokens	*get_token(char *input)
{
    t_tokens *token;
    token = (t_tokens *)malloc(sizeof(t_tokens));
	if (!token)
		return (NULL);
    token->value = NULL;
    token->type = 0;
    token->next = NULL;
    //porównywanie stringa i przypisywanie do typu tokena ten kawałek stringa
}