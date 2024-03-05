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

static void	process(t_pipex *pipe_struct, t_pipex *list, char **envp)
{
	int		ret_execve;
	int		dup_in;
	int		dup_out;

	dup_in = dup2(pipe_struct->fd_in, STDIN_FILENO);
	dup_out = dup2(pipe_struct->fd_out, STDOUT_FILENO);
	if (dup_in == -1 || dup_out == -1)
		close_error(list, DUP_ERROR);
	close_fds(list);
	ret_execve = execve(pipe_struct->command, pipe_struct->flags, envp);
	if (ret_execve == -1)
		close_error(list, EXECVE_ERROR);
}

static void	init_process(t_pipex *list, t_pipex *pipe_struct, char **envp)
{
	pipe_struct->pid = fork();
	if (pipe_struct->pid == -1)
		close_error(list, FORK_ERROR);
	else if (pipe_struct->pid == 0)
		process(pipe_struct, list, envp);
}

static void	create_pipe(t_pipex *pipe_struct, int fd_input[2])
{
	int		i;
	int		pipe_ret;
	int		fd_pipe[2];
	t_pipex	*list;

	i = 0;
	list = NULL;
	if (pipe_struct)
		list = pipe_struct;
	pipe_struct->fd_in = fd_input[0];
	while (pipe_struct->next)
	{
		pipe_ret = pipe(fd_pipe);
		if (pipe_ret == -1)
			close_error(list, PIPE_ERROR);
		pipe_struct->fd_out = fd_pipe[1];
		pipe_struct->next->fd_in = fd_pipe[0];
		pipe_struct = pipe_struct->next;
	}
	pipe_struct->fd_out = fd_input[1];
}

static int	wait_all_pid(t_pipex *list)
{
	int	ret;

	ret = 0;
	while (list->next)
	{
		waitpid(list->pid, NULL, 0);
		list = list->next;
	}
	waitpid(list->pid, &ret, 0);
	ret = WEXITSTATUS(ret);
	return (ret);
}

int	check_files(char **argv, char **envp, t_pipex *pipe_struct)
{
	int		fd_input[2];
	int		ret;
	t_pipex	*list;

	ret = 0;
	list = NULL;
	fd_input[0] = open(argv[1], O_RDONLY);
	if (fd_input[0] == -1)
		fd_input_check(fd_input, pipe_struct, 0);
	fd_input[1] = open(argv[pipe_struct->nb_cmd + 2],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_input[1] == -1)
		fd_input_check(fd_input, pipe_struct, 1);
	create_pipe(pipe_struct, fd_input);
	if (pipe_struct)
		list = pipe_struct;
	while (pipe_struct)
	{
		init_process(list, pipe_struct, envp);
		pipe_struct = pipe_struct->next;
	}
	close_fds(list);
	ret = wait_all_pid(list);
	return (ret);
}
