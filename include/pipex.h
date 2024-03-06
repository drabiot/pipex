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
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_cmd
{
	char			*command;
	char			**flags;
	int				nb_cmd;
	int				pos_cmd;
	int				fd_in;
	int				fd_out;
	pid_t			pid;
	struct s_cmd	*next;
}					t_cmd;

enum	e_error
{
	FEW_ARGV_ERROR,
	MANY_ARGV_ERROR,
	PATH_ERROR,
	PATH_SPLIT_ERROR,
	LINK_LIST_ERROR,
	INFILE_ERROR,
	OUTFILE_ERROR,
	PIPE_ERROR,
	FORK_ERROR,
	DUP_ERROR,
	EXECVE_ERROR
} ;

char		**get_path(char **envp);
void		error_check(int error);
void		free_matrix(char **matrix);
void		free_lst(t_cmd **lst);
t_cmd		*append_link_list(char **path, char	**commands, int nb_cmd);
t_cmd		*append_node(char **path, char *command, int nb_cmd, int pos_cmd);
t_cmd		*ft_last_node(t_cmd *lst);
void		ft_add_back(t_cmd **lst, t_cmd *new);
char		**get_flags(char *command, char *path_cmd);
char		*get_correct_path(char **path, char *command);
int			check_files(char **argv, char **envp, t_cmd *pipe);
void		fd_input_check(int *fd_input, t_cmd *pipe, int fd_type);
void		fd_input_check(int *fd_input, t_cmd *pipe, int fd_type);
void		display(t_cmd *lst);
void		fd_pipe_check(int *fd_input, t_cmd *pipe, char **envp);
void		fork_check(int *fd_input, int *fd_pipe, t_cmd *pipe, char **envp);
void		dup_check(int *fd_input, int *fd_pipe, t_cmd *pipe, char **envp);
void		close_fds(t_cmd *close_fd);
void		close_error(t_cmd *close_fd, int error);
void		error_soft_check(int error);

#endif //PIPEX_H
