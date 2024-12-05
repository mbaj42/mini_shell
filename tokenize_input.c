#include "shell.h"

char *trim_input(char *line)
{
    int i = 0, j = 0;
    bool in_word = false;
    char *trimmed_line;

    while (line[i] == ' ' || line[i] == '\n' || line[i] == '\t')
        i++;
    int start = i;
    while (line[i] != '\0')
        i++;
    int len = i - start;

    trimmed_line = malloc(len + 1);
    if (!trimmed_line)
        return NULL;

    i = start;
    while (line[i] != '\0')
    {
        if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
        {
            trimmed_line[j++] = line[i];
            in_word = true;
        }
        else if (in_word)
        {
            trimmed_line[j++] = ' ';
            in_word = false;
        }
        i++;
    }
    if (j > 0 && trimmed_line[j - 1] == ' ')
        j--;

    trimmed_line[j] = '\0';
    return trimmed_line;
}

t_data    *tokenize_input(char *line, t_data *data)
{
    char    *trimmed_line;

    if(!is_input_valid(line))
        ft_handle_error("Input is not valid");
    trimmed_line = trim_input(line);
    data->tokens = finall_tokenize_input(trimmed_line);
    free(trimmed_line);
    return(data);
}

// zrobić Makefile
// osobny folder dla object plików
// przypomnieć linked listy 
// podział tokenów 
// wyczyścić pamięć 
// pamiętać, że na etapie tokenów na końcu obsłużyć heredoca 
// podzielić na foldery