/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:39:35 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/10 16:45:00 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ft_putnbr_unsigned()
 * Transform an unsigned int into a string.
 * Count & return the size of the unsigned int.
 */
unsigned int	ft_putnbr_unsigned(unsigned int nb)
{
	unsigned int	len;

	if (nb < 10)
	{
		nb += '0';
		write (1, &nb, 1);
		return (1);
	}
	len = ft_putnbr_unsigned(nb / 10);
	len += ft_putnbr_unsigned(nb % 10);
	return (len);
}
