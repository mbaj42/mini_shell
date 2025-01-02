#include "../include/shell.h"

int	env_builtin(t_env node)
{
	t_env	*current;

	*current = node;
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
