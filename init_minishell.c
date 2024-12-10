#include "shell.h"

static void     init_minishell(t_data **minishell)
{
    *minishell = (t_data *)malloc(sizeof(t_data));
	if (!minishell)
        error_handler("something wrong with allocation");
    (*minishell)->tokens = NULL;
	(*minishell)->commands = NULL;
	(*minishell)->input = NULL;
}

// tutaj dopisać zmienne środowiskowe i przypisać do struktury