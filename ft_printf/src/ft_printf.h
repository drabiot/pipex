/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:02:49 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/10 16:15:20 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

/* ********************************************************** */
/*                                                            */
/*                      Printf functions                      */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                ft_putchar.c                */
/*           write the character &            */
/*              return its size               */
/* ****************************************** */
int				ft_putchar(int c);

/* ****************************************** */
/*                ft_putstr.c                 */
/*             write the string &             */
/*              return its size               */
/* ****************************************** */
int				ft_putstr(char *str);

/* ****************************************** */
/*                ft_putnbr.c                 */
/*             write the number &             */
/*             return its length              */
/* ****************************************** */
int				ft_putnbr(int nb);

/* ****************************************** */
/*            ft_putnbr_unsigned.c            */
/*        write the unsigned integer &        */
/*             return its length              */
/* ****************************************** */
unsigned int	ft_putnbr_unsigned(unsigned int nb);

/* ****************************************** */
/*               ft_base_conv.c               */
/*          take a base 10 integer &          */
/*     convert it to his hexadecimal base     */
/* ****************************************** */
int				ft_base_conv(int nb, char c);

/* ****************************************** */
/*               ft_base_conv.c               */
/*        take address of a pointer &         */
/*            turn in hexadecimal.            */
/* ****************************************** */
int				ft_point_to_hexa(void *addr);

/* ****************************************** */
/*                ft_printf.c                 */
/*     write the string & the variable &      */
/*              return its size               */
/* ****************************************** */
int				ft_printf(const char *s, ...);

#endif //FT_PRINTF_H
