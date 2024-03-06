/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:07:26 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/28 21:10:51 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
** Return the last node of the given stack
*/
t_cmd	*ft_last_node(t_cmd *lst)
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
void	ft_add_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*buffer;

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
