/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:13:49 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/29 21:12:41 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"
#include <fcntl.h>

static void	process(t_cmd *pipe_struct, t_cmd *list, char **envp,
	char *tmp_file)
{
	int		ret_execve;
	int		dup_in;
	int		dup_out;

	dup_in = dup2(pipe_struct->fd_in, STDIN_FILENO);
	dup_out = dup2(pipe_struct->fd_out, STDOUT_FILENO);
	ret_execve = 0;
	if (dup_in == -1 || dup_out == -1)
		close_error(list, DUP_ERROR, tmp_file);
	close_fds(list);
	if (pipe_struct->flags)
		ret_execve = execve(pipe_struct->command, pipe_struct->flags,
				envp);
	else
		close_error(list, EXECVE_ERROR, tmp_file);
	if (ret_execve == -1)
		close_error(list, EXECVE_ERROR, tmp_file);
}

static void	init_process(t_cmd *list, t_cmd *pipe_struct, char **envp,
	char *tmp_file)
{
	pipe_struct->pid = fork();
	if (pipe_struct->pid == -1)
		close_error(list, FORK_ERROR, tmp_file);
	else if (pipe_struct->pid == 0)
		process(pipe_struct, list, envp, tmp_file);
}

static void	create_pipe(t_cmd *pipe_struct, int fd_input[2],
	char *tmp_file)
{
	int		i;
	int		pipe_ret;
	int		fd_pipe[2];
	t_cmd	*list;

	i = 0;
	list = NULL;
	if (pipe_struct)
		list = pipe_struct;
	pipe_struct->fd_in = fd_input[0];
	while (pipe_struct->next)
	{
		pipe_ret = pipe(fd_pipe);
		if (pipe_ret == -1)
			close_error(list, PIPE_ERROR, tmp_file);
		pipe_struct->fd_out = fd_pipe[1];
		pipe_struct->next->fd_in = fd_pipe[0];
		pipe_struct = pipe_struct->next;
	}
	pipe_struct->fd_out = fd_input[1];
}

static int	wait_all_pid(t_cmd *list)
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

int	check_files(char **argv, char **envp, t_cmd *pipe_struct, char *tmp_file)
{
	int		fd_input[2];
	int		ret;
	t_cmd	*list;

	ret = 0;
	list = NULL;
	fd_input[0] = open(argv[1], O_RDONLY);
	if (fd_input[0] == -1)
		fd_input_check(fd_input, pipe_struct, 0);
	fd_input[1] = open(argv[pipe_struct->nb_cmd + 2],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_input[1] == -1)
		fd_input_check(fd_input, pipe_struct, 1);
	create_pipe(pipe_struct, fd_input, tmp_file);
	if (pipe_struct)
		list = pipe_struct;
	while (pipe_struct)
	{
		init_process(list, pipe_struct, envp, tmp_file);
		pipe_struct = pipe_struct->next;
	}
	close_fds(list);
	ret = wait_all_pid(list);
	return (ret);
}
