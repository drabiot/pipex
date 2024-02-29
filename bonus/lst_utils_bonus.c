/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:07:26 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/29 21:12:17 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/*
** Return the last node of the given stack
*/
t_pipex	*ft_last_node(t_pipex *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
** Add a new node in the front (tail) of a given stack
*/
void	ft_add_back(t_pipex **lst, t_pipex *new)
{
	t_pipex	*buffer;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		buffer = ft_last_node((*lst));
		buffer->next = new;
	}
}
