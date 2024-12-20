/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:42:17 by mbaj              #+#    #+#             */
/*   Updated: 2024/12/20 15:26:26 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

/*int	main(int argc, t_data *minishell, char **ev)
{
	t_env	tmp;
	bool	is_crush;
	int		i;

	(*minishell).env = malloc((strlen(ev) + 1) * sizeof(char **));
	if (!((*minishell).env))
		return (ft_free_minishell((*minishell), is_crush));
	i = 0;
	tmp = (*minishell).env[i];
	for (int i = 0; &(*minishell).env[i]; i++)
	{ // dst   // src        // Adres 8    -  4
		// alloc key i val
		strncpy((*minishell).env[i].key, ev[i], strchr(ev[i], '=') - ev[i]);
		strcpy((*minishell).env[i].value, strchr(ev[i], '=') + 1);
		(*minishell).env = (*minishell).env->next;
	}
	(*minishell).env[i] = tmp;
}*/

int	main(int argc, t_data *minishell, char **ev)
{
	int ev_count;
	int i;

	ev_count = 0;
	while (ev)
		ev_count++;
	minishell->env = malloc((ev_count + 1) * sizeof(t_env));
	if (!minishell->env)
	{
		ft_free_minishell(minishell, true);
		return (1);
	}
}