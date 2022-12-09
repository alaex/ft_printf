/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:39:02 by aen-naas          #+#    #+#             */
/*   Updated: 2022/11/24 00:54:59 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putbase(unsigned long nbr, char *base)
{
	unsigned long	len;
	int				i;

	len = 0;
	i = 0;
	while (base[len])
		len++;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		i++;
	}
	if (nbr < len)
		i += ft_putchar(base[nbr % len]);
	if (nbr >= len)
	{
		i += ft_putbase(nbr / len, base);
		i += ft_putchar(base[nbr % len]);
	}
	return (i);
}
