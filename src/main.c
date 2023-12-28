/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:36:50 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/28 18:23:12 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	char **path;

	if (argc < 5)
		error_check(FEW_ARGV_ERROR);
	else if (argc > 5)
		 error_check(MANY_ARGV_ERROR);
	path = get_path(envp);
}
