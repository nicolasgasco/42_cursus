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

#include "philo_bonus.h"

int	ft_calc_timestamp(struct timeval start)
{
	int				result;
	struct timeval	t_now;

	gettimeofday(&t_now, NULL);
	result = (t_now.tv_sec - start.tv_sec) * 1000;
	result += (t_now.tv_usec - start.tv_usec) / 1000;
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

	result = (now.tv_sec - start.tv_sec) * 1000;
	result += (now.tv_usec - start.tv_usec) / 1000;
	return (result);
}

int	ft_calc_time_micro(struct timeval now, struct timeval start)
{
	int	result;

	result = (now.tv_sec - start.tv_sec) * 10000;
	result += (now.tv_usec - start.tv_usec) / 100;
	return (result);
}

void	ft_msleep(t_philo *philo, int interval)
{
	struct timeval	t_now;

	interval *= 10;
	gettimeofday(&t_now, NULL);
	while (1)
	{
		usleep(100);
		// ft_death(philo);
		// pthread_mutex_lock(&philo->c_data->t_mutex);
		if (philo->c_data->end == 1)
		{
			// pthread_mutex_unlock(&philo->c_data->t_mutex);
			break;
		}
		// pthread_mutex_unlock(&philo->c_data->t_mutex);
		if (ft_calc_time_micro(ft_now(), t_now) >= interval)
			break ;
	}
}