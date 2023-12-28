/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:01:50 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/10 16:39:22 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ft_arguments()
 * Look at the arguments put after the '%' in the ft_printf() string.
 */
static int	ft_arguments(const char c, va_list array, int count)
{
	if (c == 'c')
		count += ft_putchar(va_arg(array, int));
	else if (c == 's')
		count += ft_putstr(va_arg(array, char *));
	else if (c == 'p')
		count += ft_point_to_hexa(va_arg(array, void *));
	else if (c == 'd')
		count += ft_putnbr(va_arg(array, int));
	else if (c == 'i')
		count += ft_putnbr(va_arg(array, int));
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(array, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_base_conv(va_arg(array, int), c);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

/* ft_valid_arg()
 * checks if the given arguments are correct.
 */
static int	ft_valid_arg(const char *s, int i)
{
	return (s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 's'
			|| s[i + 1] == 'p' || s[i + 1] == 'd' || s[i + 1] == 'i'
			|| s[i + 1] == 'u' || s[i + 1] == 'x' || s[i + 1] == 'X'
			|| s[i + 1] == '%'));
}

/* ft_printf()
 * Read the given string & check out for specific given arguments
 * which start with '%'. Count the size of the final string and return it.
 */
int	ft_printf(const char *s, ...)
{
	va_list	array;
	int		i;
	int		count;

	va_start(array, s);
	i = 0;
	count = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (ft_valid_arg(s, i))
		{
			count = ft_arguments(s[i + 1], array, count);
			i += 2;
		}
		else
		{
			count += write(1, &s[i], 1);
			i++;
		}
	}
	va_end(array);
	return (count);
}
