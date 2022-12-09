/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:21:56 by aen-naas          #+#    #+#             */
/*   Updated: 2022/11/24 00:38:50 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getargs(char c, va_list arg)
{
	char	*base;

	base = "0123456789abcdef";
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(arg, unsigned int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_putbase((va_arg(arg, unsigned long long)), base) + 2);
	}
	else if (c == 'x')
		return (ft_putbase(va_arg(arg, unsigned int), base));
	else if (c == 'X')
		return (ft_putbase(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	if (c)
		return (ft_putchar(c));
	return (0);
}
