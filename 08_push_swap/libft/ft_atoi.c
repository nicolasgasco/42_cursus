/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:18:01 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/01 17:43:57 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_limits(int negative, unsigned long result)
{
	if ((negative == 1 && result > (unsigned long)INT_MAX)
	|| (negative == -1 && result > (unsigned long)INT_MAX + 1))
		ft_put_err(0);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	result;
	int				negative;

	i = 0;
	result = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	ft_check_limits(negative, result);
	return ((int)result * negative);
}
