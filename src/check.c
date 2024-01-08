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

void	fd_pipe_check(int *fd_input, t_pipex *pipe, char **envp)
{
	(void) envp;
	close(fd_input[0]);
	close(fd_input[1]);
	free_lst(&pipe);
	error_check(PIPE_ERROR);
}

void	fork_check(int *fd_input, int *fd_pipe, t_pipex *pipe, char **envp)
{
	(void) envp;
	close(fd_input[0]);
	close(fd_input[1]);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	free_lst(&pipe);
	error_check(FORK_ERROR);
}

void	dup_check(int *fd_input, int *fd_pipe, t_pipex *pipe,char **envp)
{
	(void) envp;
	close(fd_input[0]);
	close(fd_input[1]);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	free_lst(&pipe);
	error_check(DUP_ERROR);
}
