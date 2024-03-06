/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_link_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:22:57 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/28 21:22:00 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_cmd	*append_node(char **path, char *command, int nb_cmd, int pos_cmd)
{
	t_cmd	*current;

	current = malloc(sizeof(t_cmd));
	if (!current)
		return (NULL);
	current->command = get_correct_path(path, command);
	current->flags = get_flags(command, current->command);
	current->nb_cmd = nb_cmd;
	current->pos_cmd = pos_cmd;
	current->pid = 0;
	current->next = NULL;
	current->fd_in = -1;
	current->fd_out = -1;
	return (current);
}

t_cmd	*append_link_list(char **path, char **commands, int nb_cmd)
{
	t_cmd	*last_node;
	t_cmd	*current_node;
	t_cmd	*first;
	int		i;

	i = 0;
	last_node = NULL;
	while (i < nb_cmd)
	{
		current_node = append_node(path, commands[2 + i], nb_cmd, (i + 1));
		if (!current_node)
		{
			if (i != 0)
				free_lst(&last_node);
			error_check(LINK_LIST_ERROR);
		}
		ft_add_back(&last_node, current_node);
		if (i == 0)
			first = last_node;
		i++;
	}
	return (first);
}
