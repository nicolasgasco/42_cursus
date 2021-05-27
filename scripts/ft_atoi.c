/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:18:01 by ngasco            #+#    #+#             */
/*   Updated: 2021/05/25 10:27:07 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		while (str[i] < 48 && str[i] > 57)
		{
			if (str[i] < 9 && str[i] > 13)
			{
				return (result);
			}
			i++;
		}
		while (str[i] >= 48 && str[i] <= 57)
		{
			result = (result * 10) + (str[i] - '0');
			i++;
		}
		i++;
	}
	return (result);
}
