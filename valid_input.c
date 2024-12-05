#include "shell.h"

bool is_quote_closed(char *line) {
    int i;
    char quote_type;

    i = 0;
    quote_type = '\0';

    while (line[i]) {
        if (quote_type == '\0') {
            if (line[i] == '\'' || line[i] == '"') {
                quote_type = line[i];
            }
        } else {
            if (line[i] == quote_type) {
                quote_type = '\0';
            }
        }
        i++;
    }
    return (quote_type == '\0');
}

bool    is_input_valid(char *line)
{
    int     i;

    i = 0;
    if (!line || ft_strlen(line) == 0)
        return false; // Pusty ciąg nie jest poprawny
    if(line[0] == '|')
        return(false);
    if(line[ft_strlen(line) - 1] == '|')
        return(false);
    if(!is_quote_closed(line))
        return(false);
    return(true);
} 