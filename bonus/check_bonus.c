/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:07:47 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/29 21:12:23 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	fd_input_check(int *fd_input, t_pipex *pipe, int fd_type)
{
	if (fd_type == 0 && fd_input[0] == -1)
	{
		free_lst(&pipe);
		error_check(INFILE_ERROR);
	}
	else if (fd_type == 1 && fd_input[1] == -1)
	{
		close(fd_input[0]);
		free_lst(&pipe);
		error_check(OUTFILE_ERROR);
	}
}

void	close_fds(t_pipex *close_fd)
{
	while (close_fd)
	{
		close(close_fd->fd_in);
		close(close_fd->fd_out);
		close_fd = close_fd->next;
	}
}

void	close_error(t_pipex *close_fd, int error)
{
	close_fds(close_fd);
	free_lst(&close_fd);
	error_check(error);
}
