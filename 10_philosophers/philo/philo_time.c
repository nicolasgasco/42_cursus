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
	int	result;

	result = (now.tv_sec * 1000 + now.tv_usec / 1000);
	result -= (start.tv_sec * 1000 + start.tv_usec / 1000);
	return (result);
}

void	ft_msleep(t_philo *philo, int interval)
{
	struct timeval	t_target;
	struct timeval	now;
	int				target;

	gettimeofday(&t_target, NULL);
	target = ft_calc_time(t_target, philo->c_data->t_start);
	target += interval;
	gettimeofday(&now, NULL);
	while (ft_calc_time(now, philo->c_data->t_start) < target)
	{
		ft_death(philo);
		usleep(100);
		gettimeofday(&now, NULL);
	}
}
