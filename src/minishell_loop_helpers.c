#include "../include/shell.h"

bool	handle_whitespace_or_syntax(t_data **minishell)
{
    if (ft_is_only_whitespace((*minishell)->input))
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
    //DOPISAĆ
    //if (!ft_is_only_whitespace((*minishell)->input))
	//add_history((*minishell)->input);
    // czy daje poprawne komendy do historii
}

bool	process_tokens(t_data **minishell)
{
    init_tokens(minishell);
    //sprawdza tokeny
    //parsuje je i rozszerza o zmienne środowiskowe
    //obsługuje przekierowania < i >
    // zwraca true, jeśli wszystko się powiedzie
}


bool    handle_empty_input(t_data **minishell)
{
    if(!(*minishell)->input)
    {
        ft_free_minishell(*minishell, true);
        printf("exit\n");
        return(true);
    }
    return(false);
}
