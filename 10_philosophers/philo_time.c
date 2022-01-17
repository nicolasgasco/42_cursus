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
	struct timeval	now;

	gettimeofday(&now, NULL);
	result = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	result -= (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (result);
}

struct timeval	ft_now(void)
{
	struct timeval	t_now;

	gettimeofday(&t_now, NULL);
	return (t_now);
}

int	ft_calc_time(struct timeval now, struct timeval start)
{
	return (now.tv_sec * 1000 + now.tv_usec / 1000) - (start.tv_sec * 1000 + start.tv_usec / 1000);
}

void	ft_msleep(t_philo *philo, int interval)
{
	struct timeval	start;
	struct timeval	now;

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	while (ft_calc_time(now, start) < interval)
	{
		usleep(100);
		gettimeofday(&now, NULL);
		ft_death(philo);
	}
}
