/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:40:30 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/22 19:20:55 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

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
	usleep(200);
}

void	ft_put_bin(unsigned int n, int pid)
{
	int	counter;

	counter = 0;
	write(1, &n, 1);
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
	while (counter < 16)
	{
		// printf("Counter is %d\n", counter);
		kill(pid, SIGUSR1);
		ft_sleep();
		counter++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("Number of arguments is not correct\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i] != '\0')
	{
		ft_put_bin((unsigned int)message[i], pid);
		i++;
	}
	ft_put_bin((int)message[i], pid);
	return (0);
}
