#include "shell.h"

void    ft_handle_error(const char *msg)
{
    printf("ERROR: %s\n", msg);
    exit(1);
}