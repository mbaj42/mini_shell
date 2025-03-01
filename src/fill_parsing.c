#include "../include/shell.h"

t_env	*fill_env(char **env)
{
	t_env	*head;
	t_env	*current;
	t_env	*new_node;
	char	*key;
	char	*value;
	size_t	i;

	head = NULL;
	current = NULL;
	new_node = NULL;
	key = NULL;
	value = NULL;
	i = 0;
	while (env[i])
	{
		key = strtok(env[i], "=");
		value = strtok(NULL, "=");
		if (key && value)
		{
			new_node = (t_env *)malloc(sizeof(t_env));
			if (!new_node)
				return (NULL);
			new_node->key = ft_strdup(key);
			new_node->value = ft_strdup(value);
			new_node->next = NULL;
			if (!head)
			{
				head = new_node;
			}
			else
			{
				current->next = new_node;
			}
			current = new_node;
		}
		i++;
	}
	return (head);
}

char	**dupenv(char **env)
{
	char	**res;

	res = malloc(100 * sizeof(char *));
	for (int i = 0; env[i]; i++)
	{
		res[i] = ft_strdup(env[i]);
	}
	return (res);
}

t_data	*fill_parsing(char **env)
{
	t_data *minishell;

	minishell = malloc(sizeof(t_data));
	minishell->env = fill_env(dupenv(env));
	// ustawic co wpisujesz do terminala
	minishell->input = ft_strdup("unset USER");
	minishell->commands = malloc(sizeof(t_command_full *));
	// ustawic ile argumentow + null (sizeof(char *) * <ilosc>)
	minishell->commands->args = malloc(sizeof(char *) * 3);
	// wpisac argumenty
	// minishell->commands->args[0] = <command_name>
	// minishell->commands->args[1] = <arg1>
	// minishell->commands->args[2] = <arg2>
	// ...
	// pamietaj ze ostatni musi byc NULL
	minishell->commands->args[0] = "unset";
	minishell->commands->args[1] = "USER";
	// minishell->commands->args[1] = "/nfs/homes/mbaj/pierdułki";
	//minishell->commands->args[2] = "unset";
	//minishell->commands->args[3] = "HEY=";
	minishell->commands->args[2] = NULL;
	// command name
	minishell->commands->cmd_name = ft_strdup(minishell->commands->args[0]);
	return (minishell);
}