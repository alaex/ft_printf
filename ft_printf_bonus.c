/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:28:45 by aen-naas          #+#    #+#             */
/*   Updated: 2022/11/25 20:16:03 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

int	ft_skip(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '+' || str[i] == '#'))
		i++;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	va_list	arg;

	i = 0;
	n = 0;
	va_start(arg, str);
	if (write(1, NULL, 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			n += ft_getargs_bonus(str + i, arg);
			i += ft_skip(str + i);
		}
		else
			n += ft_putchar(str[i]);
		if (str[i])
			i++;
	}
	return (n);
}
