/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:39:35 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/10 16:43:57 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/* ft_divide()
 * Transform an integer into a string.
 * Count & return the size of the integer.
 */
static int	ft_divide(int nb)
{
	int	len;

	if (nb > -10 && nb < 10)
	{
		if (nb < 0)
			nb = -nb;
		nb += '0';
		write (1, &nb, 1);
		return (1);
	}
	len = ft_divide(nb / 10);
	len += ft_divide(nb % 10);
	return (len);
}

/* ft_putnbr()
 * Chek if the given integer is negative & execute divide() function.
 */
int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		write(1, "-", 1);
	}
	len += ft_divide(nb);
	return (len);
}
