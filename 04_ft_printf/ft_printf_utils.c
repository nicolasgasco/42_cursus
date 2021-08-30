/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:22:12 by nicolasg          #+#    #+#             */
/*   Updated: 2021/08/30 13:07:03 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *s, unsigned int *counter)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		*counter += write(1, &s[i], 1);
		i++;
	}
	return ;
}

void	ft_putnbr(int n, unsigned int *counter)
{
	char	res;

	if (n == -2147483648)
	{
		ft_putnbr(n / 10, counter);
		*counter += write(1, "8", 1);
	}
	else if (n < 0)
	{
		*counter += write(1, "-", 1);
		ft_putnbr(-n, counter);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10, counter);
		res = (n % 10) + '0';
		*counter += write(1, &res, 1);
	}
}

void	ft_putunbr(unsigned int n, unsigned int *counter)
{
	char	res;

	if (n > 9)
		ft_putnbr(n / 10, counter);
	res = (n % 10) + '0';
	*counter += write(1, &res, 1);
}

void	ft_puthex(unsigned int hex, char uppercase, unsigned int *counter)
{
	char	*alpha;

	if (uppercase == 'X')
		alpha = "ABCDEF";
	else
		alpha = "abcdef";
	if ((hex / 16) == 0)
	{
		if ((hex % 16) < 10)
			ft_putnbr(hex % 16, counter);
		else
			*counter += write(1, &alpha[hex % 16 - 10], 1);
		return ;
	}
	ft_puthex(hex / 16, uppercase, counter);
	if (hex % 16 < 10)
		ft_putnbr(hex % 16, counter);
	else
		*counter += write(1, &alpha[hex % 16 - 10], 1);
}

void	ft_puthexp(unsigned long hex, char upp, unsigned int *counter)
{
	char	*alpha;

	if (upp == 'X')
		alpha = "ABCDEF";
	else
		alpha = "abcdef";
	if ((hex / 16) == 0)
	{
		if ((hex % 16) < 10)
			ft_putnbr(hex % 16, counter);
		else
			*counter += write(1, &alpha[hex % 16 - 10], 1);
		return ;
	}
	ft_puthexp(hex / 16, upp, counter);
	if (hex % 16 < 10)
		ft_putnbr(hex % 16, counter);
	else
		*counter += write(1, &alpha[hex % 16 - 10], 1);
}
