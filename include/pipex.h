/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:36:38 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/28 21:04:13 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pipex
{
	char			*command;
	char			**flags;
	int				nb_cmd;
	int				pos_cmd;
	struct s_pipex	*next;
}					t_pipex;

enum	e_error
{
	FEW_ARGV_ERROR,
	MANY_ARGV_ERROR,
	PATH_ERROR,
	PATH_SPLIT_ERROR,
	LINK_LIST_ERROR
} ;

char		**get_path(char **envp);
void		error_check(int error);
void		free_matrix(char **matrix);
void		free_lst(t_pipex **lst);
t_pipex		*append_link_list(char **path, char	**commands, int nb_cmd);
t_pipex		*append_node(char **path, char *command, int nb_cmd, int pos_cmd);

t_pipex		*ft_last_node(t_pipex *lst);
void		ft_add_back(t_pipex **lst, t_pipex *new);

char		**get_flags(char *command, char *path_cmd);
char		*get_correct_path(char  **path, char *command);

void    	display(t_pipex *lst);

#endif //PIPEX_H
