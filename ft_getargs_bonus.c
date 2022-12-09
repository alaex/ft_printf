/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getargs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:24:48 by aen-naas          #+#    #+#             */
/*   Updated: 2022/11/24 00:55:14 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_puthexa(unsigned long nbr, char sep, char flag)
{
	int	n;

	n = 0;
	if (sep && nbr)
	{
		if (flag == 'x')
			n += ft_putstr("0x");
		else
			n += ft_putstr("0X");
	}
	if (flag == 'x')
		return (n + ft_putbase(nbr, "0123456789abcdef"));
	return (n + ft_putbase(nbr, "0123456789ABCDEF"));
}

int	num_hundel(char flag, char sep, va_list arg)
{
	int	n;
	int	n1;

	n = 0;
	if (flag == 'i' || flag == 'd')
	{
		n1 = va_arg(arg, int);
		if (sep && n1 >= 0)
			n += ft_putchar(sep);
		return (n += ft_putnbr(n1));
	}
	else
	{
		if (flag == 'x')
			return (n += ft_puthexa(va_arg(arg, unsigned int), sep, flag));
		else
			return (n += ft_puthexa(va_arg(arg, unsigned int), sep, flag));
	}
}

int	ft_put_adrs(unsigned long long p)
{
	ft_putstr("0x");
	return (ft_putbase(p, "0123456789abcdef") + 2);
}

int	ft_check_sp(const char *str, char flag)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '+' || str[i] == '#'))
	{
		if ((flag == 'i' || flag == 'd') && str[i] == '+')
			return ('+');
		i++;
	}
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '+' || str[i] == '#'))
	{
		if ((flag == 'i' || flag == 'd' || flag == 's') && str[i] == ' ')
			return (' ');
		i++;
	}
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '+' || str[i] == '#'))
	{
		if ((flag == 'x' || flag == 'X') && str[i] == '#')
			return ('#');
		i++;
	}
	return (0);
}

int	ft_getargs_bonus(const char *str, va_list arg)
{
	int			n;
	int			i;
	char		sep;

	i = ft_skip(str);
	n = 0;
	sep = ft_check_sp(str, str[i]);
	if (str[i] == '%')
		return (ft_putchar(str[i]));
	else if (str[i] == 'i' || str[i] == 'd' || str[i] == 'x' || str[i] == 'X')
		return (num_hundel(str[i], sep, arg));
	else if (str[i] == 'u')
		return (n += ft_putnbr(va_arg(arg, unsigned int)));
	else if (str[i] == 's')
		return (n += ft_putstr(va_arg(arg, char *)));
	else if (str[i] == 'c')
		return (n += ft_putchar(va_arg(arg, int)));
	else if (str[i] == 'p')
		return (ft_put_adrs(va_arg(arg, unsigned long long)));
	if (str[0])
		return (n += ft_putchar(str[i]));
	return (0);
}
