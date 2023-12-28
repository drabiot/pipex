/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:36:38 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/28 18:47:02 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>

enum	e_error
{
		FEW_ARGV_ERROR,
		MANY_ARGV_ERROR,
		PATH_ERROR,
		PATH_SPLIT_ERROR
} ;

char	**get_path(char **envp);
void	error_check(int	error);

#endif //PIPEX_H
