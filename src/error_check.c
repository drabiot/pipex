/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:46:06 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/28 22:08:46 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../ft_printf/src/ft_printf.h"

/*
** Free the given stack
*/
void	free_lst(t_pipex **lst)
{
	t_pipex	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free_matrix((*lst)->flags);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

/*
** Free the given matrix & its arrays
*/
void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	error_check(int error)
{
	char	*error_message[5];

	error_message[FEW_ARGV_ERROR] = "Error\n(Too few arguments)";
	error_message[MANY_ARGV_ERROR] = "Error\n(Too many arguments)";
	error_message[PATH_ERROR] = "Error\n(No \"PATH\" detected)";
	error_message[PATH_SPLIT_ERROR] = "Error\n(Failed when \"PATH\" splitting)";
	error_message[LINK_LIST_ERROR] = "Error\n(Failed when create link-list)";
	ft_printf("%s\n", error_message[error]);
	exit (1);
}
