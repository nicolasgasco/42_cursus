/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:22:12 by nicolasg          #+#    #+#             */
/*   Updated: 2021/08/27 11:22:14 by nicolasg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char	res;

	if (n == -2147483648)
	{
		ft_putnbr(n / 10);
		write(1, "8", 1);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10);
		res = (n % 10) + '0';
		write(1, &res, 1);
	}
}

void	ft_puthex(unsigned long hex, char uppercase)
{
	char *alpha;

	if (uppercase == 'X')
		alpha = "ABCDEF";
	else
		alpha = "abcdef";
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
