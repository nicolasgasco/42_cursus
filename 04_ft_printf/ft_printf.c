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

void	ft_found_percent(const char *str_char, va_list args, unsigned int *counter)
{
	int	result;

	if (*str_char == 'c')
	{
		result = va_arg(args, int);
		counter += write(1, &result, 1);
	}
	else if (*str_char == 'u')
	{
		result = va_arg(args, int);
		if (result >= 0)
			ft_putnbr(result, counter);
	}
	else if (*str_char == 'd' || *str_char == 'i')
		ft_putnbr(va_arg(args, int), counter);
	else if (*str_char == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (*str_char == 'x' || *str_char == 'X')
		ft_puthex(va_arg(args, unsigned int), *str_char, counter);
	else if (*str_char == 'p')
	{
		ft_putstr("0x7fff", counter);
		ft_puthex(va_arg(args, unsigned int), 'x', counter);
	}
	return ;
}

int	ft_printf(const char *str, ...)
{
    va_list args;
	unsigned int	i;
	unsigned int	result;

	if (!str)
		return (-1);
	i = 0;
	result = 0;

	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				result += write(1, "%", 1);
			else
				ft_found_percent(&str[i + 1], args, &result);
			i++;
		}
		else
			result += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
    return (result);
}
