#include "shell.h"
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

static int	export_no_args(t_data **minishell, char **envp)
{
	int	i;

	i = 0;
	copy_env(minishell, envp);
	swap_alphabetic(&minishell);
	while((*minishell)->env[i])
	{
		write(1, "declare -x ", 11);
		printf("%s=%s", (*minishell)->env[i].key, (*minishell)->env[i].value);
	}
}

int	export_builtin(t_data **minishell, char **envp)
{
	if (!((*minishell)->commands->args[1]))
		return (export_no_args(minishell, envp));
}
