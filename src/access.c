/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:23:50 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/28 18:41:45 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../libft/src/libft.h"

char	**get_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	if (!ft_strnstr(envp[i], "PATH=", 5))
		error_check(PATH_ERROR);
	path = ft_split(envp[i] + 5, ':');
	if (!path || !*path)
		error_check(PATH_SPLIT_ERROR);
	return (path);
}
