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
#include "../include/libft.h"

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
		if ((*lst)->flags)
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

void	error_soft_check(int error)
{
	char	*error_message[11];

	error_message[FEW_ARGV_ERROR] = "(Too few arguments)";
	error_message[MANY_ARGV_ERROR] = "(Too many arguments)";
	error_message[PATH_ERROR] = "(No \"PATH\" detected)";
	error_message[PATH_SPLIT_ERROR] = "(Failed when \"PATH\" splitting)";
	error_message[LINK_LIST_ERROR] = "(Failed when create link-list)";
	error_message[INFILE_ERROR] = "(Failed when open infile)";
	error_message[OUTFILE_ERROR] = "(Failed when create outfile)";
	error_message[PIPE_ERROR] = "(Failed when create pipe)";
	error_message[FORK_ERROR] = "(Failed when fork)";
	error_message[DUP_ERROR] = "(Dup error)";
	error_message[EXECVE_ERROR] = "(Execve error)";
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_message[error], 2);
}

void	error_check(int error)
{
	error_soft_check(error);
	exit (1);
}
