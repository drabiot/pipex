/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:55:26 by tchartie          #+#    #+#             */
/*   Updated: 2024/03/04 18:55:52 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"
#include "../include/libft.h"
#include <fcntl.h>

void	generate_key_random(void)
{
	int		pid;

	pid = fork();
	if (pid == 0)
		exit(0);
	ft_srand(pid);
}

static char	*generate_random_file(char *tmp_file)
{
	int		c_rand;
	char	*suff;
	char	*final_file;

	c_rand = ft_rand(0, 51);
	suff = ft_substr("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
			c_rand, 1);
	final_file = ft_strjoin(suff, tmp_file);
	if (tmp_file)
		free(tmp_file);
	if (suff)
		free(suff);
	return (final_file);
}

static char	*create_file(char **path, int *tmp_fd)
{
	char	*tmp_file;

	tmp_file = ft_strdup("tmp");
	if (!tmp_file)
	{
		free_matrix(path);
		error_check(MALLOC_ERROR);
	}
	*tmp_fd = open("tmp", O_EXCL | O_CREAT, 0644);
	while (*tmp_fd == -1)
	{
		tmp_file = generate_random_file(tmp_file);
		*tmp_fd = open(tmp_file, O_EXCL | O_WRONLY | O_CREAT, 0644);
	}
	return (tmp_file);
}

static void	set_infile(int tmp_fd, char *limiter, char **path,
	char *tmp_file)
{
	char	*line;
	int		len_limiter;

	len_limiter = ft_strlen(limiter);
	ft_putstr_fd("> ", STDOUT_FILENO);
	line = get_next_line(STDIN_FILENO);
	while ((ft_strncmp(line, limiter, len_limiter + 1)) && line)
	{
		ft_putstr_fd(line, tmp_fd);
		free(line);
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
	}
	close(tmp_fd);
	if (!line)
	{
		free(limiter);
		free_matrix(path);
		destroy_tmp(tmp_file);
		error_check(MALLOC_ERROR);
	}
	else
		free(line);
}

char	*heredoc(char **argv, char **path)
{
	char	*file;
	char	*limiter;
	int		tmp_fd;

	limiter = ft_strjoin(argv[2], "\n");
	if (!limiter)
	{
		free_matrix(path);
		error_check(MALLOC_ERROR);
	}
	file = create_file(path, &tmp_fd);
	argv[2] = file;
	set_infile(tmp_fd, limiter, path, file);
	if (limiter)
		free(limiter);
	return (file);
}
