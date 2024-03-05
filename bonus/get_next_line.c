/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:18 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/20 15:55:44 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"
#include "../include/libft.h"

static char	*create_line(char **line, int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			countread;

	*line = ft_strdup(buff);
	countread = read(fd, buff, BUFFER_SIZE);
	while (!(ft_strchr(*line, '\n')) && countread > 0)
	{
		buff[countread] = '\0';
		*line = ft_strnjoin(*line, buff, countread);
	}
	if (ft_strlen(*line) == 0)
	{
		free(*line);
		return (NULL);
	}
	return (buff);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*line;
	char	*newline;
	int		to_copy;

	buff = create_line(&line, fd);
	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strlcpy(buff, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buff, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return (line);
}
