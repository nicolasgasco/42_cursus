/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:07:18 by ngasco            #+#    #+#             */
/*   Updated: 2021/12/05 17:07:19 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(int fd, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
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
	if (i < ft_strlen(str))
		return (0);
	return ((int)result * negative);
}

void	ft_putnbr(long n)
{
	int	result;

	if (n < 10)
	{
		result = n + '0';
		write(1, &result, 1);
	}
	else
	{
		result = (n % 10) + '0';
		ft_putnbr(n / 10);
		write(1, &result, 1);
	}
}

int	*ft_create_forks(int n_philos)
{
	int	*result;
	int	i;

	i = 0;
	result = (int *)malloc(sizeof(int) * (n_philos + 1));
	while (i < n_philos)
	{
		result[i] = 1;
		i++;
	}
	result[i] = -1;
	return (result);
}