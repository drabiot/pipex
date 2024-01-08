/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_to_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:09:47 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/10 16:29:21 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/* ft_conv_hexa()
 * Convert a base 10 address to its Lowercase Hexadecimal base.
 */
static void	ft_conv_hexa(unsigned long long nb, int *count)
{
	if (nb >= 16)
		ft_conv_hexa(nb / 16, count);
	if (nb == 0)
		return ;
	*count += write(1, &"0123456789abcdef"[nb % 16], 1);
}

/* ft_bse_conv()
 * Take an address to be converted by conv_hexa() function.
 * Add string "0x" before writting the address.
 * Count the length of the futur Hexadecimal base address.
 */
int	ft_point_to_hexa(void *addr)
{
	int	count;

	count = 0;
	if (!addr)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		ft_conv_hexa((unsigned long long) addr, &count);
	}
	return (count);
}
