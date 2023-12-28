/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:46:06 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/28 18:54:56 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../ft_printf/src/ft_printf.h"

void	error_check(int	error)
{
	char	*error_message[4];

	error_message[FEW_ARGV_ERROR] = "Error\n(Too few arguments)";
	error_message[MANY_ARGV_ERROR] = "Error\n(Too many arguments)";
	error_message[PATH_ERROR] = "Error\n(No \"PATH\" detected)";
	error_message[PATH_SPLIT_ERROR] = "Error\n(Failed when \"PATH\" splitting)";
	ft_printf("%s\n", error_message[error]);
	exit (1);
}
