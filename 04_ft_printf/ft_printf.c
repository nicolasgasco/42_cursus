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

void	ft_found_percent(const char *str_char, int arg)
{
	str_char++;

	if (!arg)
		return ;
	if (*str_char == 'c')
		write(1, &arg, sizeof(char));
	else if (*str_char == 'd')
		ft_putnbr(arg);
	else if (*str_char == 's')
		ft_putstr(arg);
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
	write(1, ".", 1);
	while (str[i] != '\0')
	{
		// printf(".%c.\n", str[i]);
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				write(1, "%", 1);
			else
				ft_found_percent(&str[i], va_arg(args, int));
			i++;
		} else {
			write(1, &str[i], 1);
		}
		i++;
	}
	write(1, ".", 1);
	write(1, "\n", 1);
	va_end(args);
    return (i);
}
