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

static bool	search_for_n_flag(char *arg)
{
	int	i;

	if (arg[0] != '-')
		return (false);
	i = 1;
	while (arg[i] == 'n')
		i++;
	if (arg[i] != '\0')
		return (false);
	return (true);
}
static void	print_args(char **argv, bool found_n, int fd_out)
{
	int	i;

	i = 0;
	if (!argv)
	{
		if (found_n == false)
			write(fd_out, "\n", 1);
		return ;
	}
	while (argv[i])
	{
		ft_putstr(argv[1], fd_out);
		if (argv[i + 1])
			write(fd_out, " ", 1);
		i++;
	}
	if (found_n == false)
		write(fd_out, "\n", 1);
	return ;
}
void	echo_command(char **argv, int fd_out)
{
	bool found_n;
	int i;

	i = 1;
	found_n = false;
	while (argv[i] && search_for_n_flag(argv[i]))
	{
		found_n = true;
		i++;
	}
	print_args(argv + 1, found_n, fd_out);
	return ;
}