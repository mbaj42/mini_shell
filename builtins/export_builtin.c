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

static int	export_no_args(t_data **minishell)
{
}

int	export_builtin(t_data **minishell)
{
	if (!((*minishell)->commands->args[1]))
		return (export_no_args(minishell));
}
