/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:25:19 by aen-naas          #+#    #+#             */
/*   Updated: 2022/11/23 23:38:25 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_BONUS_H
# 	define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_getargs_bonus(const char *str, va_list arg);
int	ft_putbase(unsigned long nbr, char *base);
int	ft_putchar(char c);
int	ft_putnbr(long n);
int	ft_putstr(char *str);
int	ft_skip(const char *str);
#endif
