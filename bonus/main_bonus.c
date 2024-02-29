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

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipe;
	char	**path;
	int		ret;

	path = NULL;
	if (argc < 5)
		error_check(FEW_ARGV_ERROR);
	path = get_path(envp);
	pipe = append_link_list(path, argv, argc - 3);
	free_matrix(path);
	ret = check_files(argv, envp, pipe);
	free_lst(&pipe);
	return (ret);
}
