/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:01:44 by aen-naas          #+#    #+#             */
/*   Updated: 2022/11/25 20:14:43 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

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
			n += ft_getargs(str[i], arg);
		}
		else
			n += ft_putchar(str[i]);
		i++;
	}
	return (n);
}
