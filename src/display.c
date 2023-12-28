/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:21:26 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/28 22:27:05 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdio.h>

void	display(t_pipex *lst)
{
	int	i;

	while (lst)
	{
		printf("Command : %s\nFlags :", lst->command);
		i = 0;
		while (lst->flags[i])
		{
			printf("%s ", lst->flags[i]);
			i++;
		}
		printf("\nNb_cmd %d\nPos_cmd %d\n", lst->nb_cmd, lst->pos_cmd);
		lst = lst->next;
	}
}
