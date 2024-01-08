/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:06:43 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/10 16:24:19 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/* ft_conv_hexa()
 * Convert a base 10 unsigned int to its Hexadecimal base.
 * Wich is Uppercase Hexadecimal or Lowecase Hexadecimal.
 */
static void	ft_conv_hexa(unsigned int nb, char type, int *count)
{
	if (nb >= 16)
		ft_conv_hexa(nb / 16, type, count);
	if (nb == 0)
		return ;
	if (type == 'x')
		*count += write(1, &"0123456789abcdef"[nb % 16], 1);
	if (type == 'X')
		*count += write(1, &"0123456789ABCDEF"[nb % 16], 1);
}

/* ft_base_conv()
 * Take a base 10 integer to be converted by conv_hexa() function.
 * Count the length of the futur Hexadecimal number.
 */
int	ft_base_conv(int nb, char c)
{
	int	count;

	count = 0;
	if (nb == 0)
		count += write(1, "0", 1);
	ft_conv_hexa((unsigned int) nb, c, &count);
	return (count);
}
