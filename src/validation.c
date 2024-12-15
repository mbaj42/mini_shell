#include "../include/shell.h"

bool    is_input_valid(char *str)
{
    int     i;

    i = 0;
    if(str[0] == '|')
        return(false);
    //else if (ft_quotes_are_closed(input_str, &i) == false)
		//return (false);
    else
        return(true);
}