/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:50:10 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/01 18:34:30 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_err(int code)
{
	ft_putstr_fd("Error\n", 0);
	exit(code);
}

int	ft_check_if_num(char *s)
{
	int	i;

	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32 || s[i] == '-'
		|| s[i] == '+')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_repetition(int *nums, int limit)
{
	int	i;
	int	y;

	i = 0;
	while (i < limit)
	{
		y = 0;
		while (y < limit)
		{
			if (nums[y] == nums[i] && y != i)
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}