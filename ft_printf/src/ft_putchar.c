/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:52:02 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/10 16:40:32 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/* ft_putchar()
 * Return the size of the given character.
 */
int	ft_putchar(int c)
{
	return (write (1, &c, 1));
}
