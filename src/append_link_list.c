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

t_pipex *append_node(char **path, char *command, int nb_cmd, int pos_cmd)
{
	t_pipex	*current;

	current = malloc(sizeof(t_pipex));
	if (!current)
		return (NULL);
	//optimisation
	current->command = get_correct_path(path, command);
	if (!(current->command))
	{
		free(current);
		return (NULL);
	}
	current->flags = get_flags(command, current->command);
	if (!(current->flags) || !(current->flags[0]))
	{
		free(current->command);
		free(current);
		return (NULL);
	}
	current->nb_cmd = nb_cmd;
	current->pos_cmd = pos_cmd;
	current->next = NULL;
	return (current);
}

t_pipex	*append_link_list(char **path, char **commands, int nb_cmd)
{
	t_pipex	*first_node;
	t_pipex	*second_node;

	first_node = append_node(path, commands[2], nb_cmd, 1);
	if (!first_node)
		error_check(LINK_LIST_ERROR);
	second_node = append_node(path, commands[3], nb_cmd, 2);
	if (!second_node)
	{
		free_lst(&first_node);
		error_check(LINK_LIST_ERROR);
	}
	ft_add_back(&first_node, second_node);
	return (first_node);
}
