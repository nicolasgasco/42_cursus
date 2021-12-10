/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:52:52 by ngasco            #+#    #+#             */
/*   Updated: 2021/12/08 13:52:53 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_calc_timestamp(struct timeval start)
{
	int				result;
	struct timeval	t_now;

	gettimeofday(&t_now, NULL);
	result = (t_now.tv_sec - start.tv_sec) * 1000;
	result += (t_now.tv_usec - start.tv_usec) / 1000;
	return (result);
}

int	ft_calc_time(struct timeval now, struct timeval start)
{
	int	result;

	result = (now.tv_sec - start.tv_sec) * 1000;
	result += (now.tv_usec - start.tv_usec) / 1000;
	return (result);
}

struct timeval	ft_now(void)
{
	struct timeval	t_now;

	gettimeofday(&t_now, NULL);
	return (t_now);
}

void	ft_msleep(t_philo *philo, int interval)
{
	int	i;
	
	i = 0;
	while (i < 10)
	{
		usleep(interval * 100);
		i++:	
	}
	ft_death(philo);
}
