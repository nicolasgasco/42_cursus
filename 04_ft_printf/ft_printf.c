/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 10:57:57 by ngasco            #+#    #+#             */
/*   Updated: 2021/08/26 12:20:23 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
// c = single character
// s = string
// void * printed in hexadecimal
// d = decimal number
// i = integer
//  u = unsigned decimal
// x = hexadec with lower
// X = hexadec with upper
// %% = percent
void	ft_puthex(unsigned long hex, int uppercase)
{
	char *alpha;

	if (uppercase == 0)
		alpha = "abcdef";
	else
		alpha = "ABCDEF";
	if ((hex / 16) == 0)
	{
		if ((hex % 16) < 10)
			ft_putnbr(hex % 16);
		else
			write(1, &alpha[hex % 16 - 10], 1);
		return ;
	}
	ft_puthex(hex / 16, uppercase);
	if (hex % 16 <= 10)
		ft_putnbr(hex % 16);
	else
		write(1, &alpha[hex % 16 - 10], 1);
}

void	ft_found_percent(const char *str_char, va_list args)
{
	int	result;
	str_char++;

	if (!args)
		return ;
	if (*str_char == 'c')
	{
		result = va_arg(args, int);
		write(1, &result, 1);
	}
	else if (*str_char == 'u')
	{
		result = va_arg(args, int);
		if (result >= 0)
			ft_putnbr(result);
	}
	else if (*str_char == 'd' || *str_char == 'i')
		ft_putnbr(va_arg(args, int));
	else if (*str_char == 's')
		ft_putstr(va_arg(args, char *));
	else if (*str_char == 'x')
		ft_puthex(va_arg(args, unsigned int), 0);
	else if (*str_char == 'X')
		ft_puthex(va_arg(args, unsigned int), 1);
	else if (*str_char == 'p')
	{
		ft_putstr("0x7fff");
		ft_puthex(va_arg(args, unsigned int), 0);
	}
	return;
}

int	ft_printf(const char *str, ...)
{
    va_list args;
	unsigned int	i;

	// printf("Str is %s\n", str);
	if (!str)
		return (-1);
	i = 0;

	va_start(args, str);
	while (str[i] != '\0')
	{
		// printf(".%c.\n", str[i]);
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				write(1, "%", 1);
			else
				ft_found_percent(&str[i], args);
			i++;
		} else {
			write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
    return (i);
}
