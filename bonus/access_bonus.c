/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:23:50 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/29 21:12:05 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"
#include "../include/libft.h"

static char	*check_correct_path(char **path, char *command)
{
	int		i;
	int		access_state;
	char	*correct_path;

	i = 0;
	access_state = 1;
	if (access(command, X_OK) == 0)
	{
		correct_path = ft_strdup(command);
		return (correct_path);
	}
	while (path[i] && access_state != 0)
	{
		correct_path = ft_strjoin(path[i], command);
		if (!correct_path)
			return (NULL);
		access_state = access(correct_path, X_OK);
		i++;
		if (path[i] && access_state != 0)
			free(correct_path);
	}
	return (correct_path);
}

char	*get_correct_path(char	**path, char *command)
{
	char	*tmp_path;
	char	*tmp_cmd;
	char	**cmd_flags;

	cmd_flags = ft_split(command, ' ');
	tmp_cmd = NULL;
	if (!cmd_flags)
		return (NULL);
	if (access(cmd_flags[0], X_OK) == 0)
		tmp_cmd = ft_strdup(cmd_flags[0]);
	else if (cmd_flags[0])
		tmp_cmd = ft_strjoin("/", cmd_flags[0]);
	free_matrix(cmd_flags);
	if (!tmp_cmd)
		return (NULL);
	tmp_path = check_correct_path(path, tmp_cmd);
	free(tmp_cmd);
	if (!tmp_path)
	{
		free_matrix(path);
		return (NULL);
	}
	return (tmp_path);
}

char	**get_flags(char *command, char *path_cmd)
{
	char	**flags;

	flags = ft_split(command, ' ');
	if (!flags || !*flags)
		return (NULL);
	free(flags[0]);
	flags[0] = path_cmd;
	return (flags);
}

char	**get_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	if (!envp[i] || !ft_strnstr(envp[i], "PATH=", 5))
		error_check(PATH_ERROR);
	path = ft_split(envp[i] + 5, ':');
	if (!path || !*path)
		error_check(PATH_SPLIT_ERROR);
	return (path);
}
