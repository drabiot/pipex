/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:36:50 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/29 21:12:36 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"
#include "../include/libft.h"

static int	execute_commands(char **argv, char **envp, char *tmp_file,
	t_pipex *pipe)
{
	int		ret;

	ret = check_files(argv, envp, pipe, tmp_file);
	free_lst(&pipe);
	destroy_tmp(tmp_file);
	return (ret);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipe;
	char	**path;
	int		ret;
	char	*tmp_file;

	path = NULL;
	if (argc < 5)
		error_check(FEW_ARGV_ERROR);
	generate_key_random();
	path = get_path(envp);
	tmp_file = NULL;
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
	{
		tmp_file = heredoc(argv, path);
		pipe = append_link_list(path, argv + 1, argc - 4, tmp_file);
		free_matrix(path);
		ret = execute_commands(argv + 1, envp, tmp_file, pipe);
	}
	else
	{
		pipe = append_link_list(path, argv, argc - 3, tmp_file);
		free_matrix(path);
		ret = execute_commands(argv, envp, tmp_file, pipe);
	}
	return (ret);
}
