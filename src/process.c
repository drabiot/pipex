/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:13:49 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/08 18:13:51 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <fcntl.h>

void	process(int *fd_in, int *fd_out, t_pipex *pipe_struct, char **envp)
{
	int	ret_execve;
	
	if ((dup2(fd_in[0], STDIN_FILENO) == -1)
		|| (dup2(fd_out[1], STDOUT_FILENO) == -1))
		dup_check(fd_in, fd_out, pipe_struct, envp);
	close(fd_in[1]);
	close(fd_out[0]);
	ret_execve = execve(pipe_struct->command, pipe_struct->flags, envp);
	if (ret_execve == -1)
	{
		close(fd_in[0]);
		close(fd_out[1]);
		error_check(EXECVE_ERROR);
	}
}

void	init_process(int *fd_input, int *fd_pipe, t_pipex *pipe_struct,
	char **envp)
{
	pipe_struct->pid = fork();
	if (pipe_struct->pid == -1)
		fork_check(fd_input, fd_pipe, pipe_struct, envp);
	else if (pipe_struct->pid == 0)
		process(fd_input, fd_pipe, pipe_struct, envp);
	else
	{
		close(fd_input[0]);
		close(fd_pipe[1]);
	}
}

void	check_files(char **argv, char **envp, t_pipex *pipe_struct)
{
	int	fd_input[2];
	int	fd_pipe[2];

	fd_input[0] = open(argv[1], O_RDONLY);
	if (fd_input[0] == -1)
		fd_input_check(fd_input, pipe_struct, 0);
	fd_input[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_input[1] == -1)
		fd_input_check(fd_input, pipe_struct, 1);
	if (pipe(fd_pipe) == -1)
		fd_pipe_check(fd_input, pipe_struct, envp);
	init_process(fd_input, fd_pipe, pipe_struct, envp);
	init_process(fd_pipe, fd_input, pipe_struct->next, envp);
	waitpid(pipe_struct->next->pid, NULL, 0);
	waitpid(pipe_struct->pid, NULL, 0);
}
