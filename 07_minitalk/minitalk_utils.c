/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:50:12 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/22 20:07:17 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	result;
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
	return ((int)result * negative);
}

void	ft_sleep(void)
{
	usleep(195);
}

void	ft_put_bin(int n, int pid)
{
	int	counter;

	counter = 0;
	while (n / 2 >= 1)
	{
		if ((n % 2) == 0)
			kill(pid, SIGUSR1);
		else if ((n % 2) == 1)
			kill(pid, SIGUSR2);
		ft_sleep();
		n = n / 2;
		counter++;
	}
	if (n == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	ft_sleep();
	counter++;
	while (counter < 8)
	{
		kill(pid, SIGUSR1);
		ft_sleep();
		counter++;
	}
}


