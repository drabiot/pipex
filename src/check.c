/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:07:47 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/08 19:10:24 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	fd_input_check(int *fd_input, t_cmd *pipe, int fd_type)
{
	if (fd_type == 0 && fd_input[0] == -1)
		error_soft_check(INFILE_ERROR);
	else if (fd_type == 1 && fd_input[1] == -1)
	{
		close(fd_input[0]);
		free_lst(&pipe);
		error_check(OUTFILE_ERROR);
	}
}

void	close_fds(t_cmd *close_fd)
{
	while (close_fd)
	{
		if (close_fd->fd_in != -1)
			close(close_fd->fd_in);
		if (close_fd->fd_out != -1)
			close(close_fd->fd_out);
		close_fd = close_fd->next;
	}
}

void	close_error(t_cmd *close_fd, int error)
{
	close_fds(close_fd);
	free_lst(&close_fd);
	error_check(error);
}
