#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

int	env_builtin(t_env node)
{
	t_env	*current;

	current = node;
	if (!current)
	{
		write(2, "Error with env", 14);
		return (1);
	}
	while (current != NULL)
	{
		ft_printf("%s=%s\n", current -> key, current -> value);
		current = current -> next;
	}
	return (0);
}
