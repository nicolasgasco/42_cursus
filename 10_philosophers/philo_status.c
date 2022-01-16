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

void	ft_put_forks(t_philo *philo)
{
	int	timestamp;

	timestamp = ft_calc_timestamp(philo->c_data->t_start);
	if (philo->c_data->end == 0)
	{
		pthread_mutex_lock(&philo->c_data->status_mutex);
		printf("%d %d has taken a fork\n", timestamp, philo->i_philo + 1);
		pthread_mutex_unlock(&philo->c_data->status_mutex);
	}
}

void	ft_put_eat(t_philo *philo)
{
	int	timestamp;

	timestamp = ft_calc_timestamp(philo->c_data->t_start);
	if (philo->c_data->end == 0)
	{
		pthread_mutex_lock(&philo->c_data->status_mutex);
		printf("%d %d is eating\n", timestamp, philo->i_philo + 1);
		pthread_mutex_unlock(&philo->c_data->status_mutex);
	}
}

void	ft_put_sleep(t_philo *philo)
{
	int	timestamp;

	timestamp = ft_calc_timestamp(philo->c_data->t_start);
	if (philo->c_data->end == 0)
	{
		pthread_mutex_lock(&philo->c_data->status_mutex);
		printf("%d %d is sleeping\n", timestamp, philo->i_philo + 1);
		pthread_mutex_unlock(&philo->c_data->status_mutex);
	}
}

void	ft_put_think(t_philo *philo)
{
	int	timestamp;

	timestamp = ft_calc_timestamp(philo->c_data->t_start);
	if (philo->c_data->end == 0)
	{
		pthread_mutex_lock(&philo->c_data->status_mutex);
		printf("%d %d is thinking\n", timestamp, philo->i_philo + 1);
		pthread_mutex_unlock(&philo->c_data->status_mutex);
	}
}

void	ft_put_death(t_philo *philo)
{
	if (philo->c_data->end == 0)
	{
		pthread_mutex_lock(&philo->c_data->status_mutex);
		printf("%d %d died\n", ft_calc_timestamp(philo->c_data->t_start), philo->i_philo + 1);
		pthread_mutex_unlock(&philo->c_data->status_mutex);
	}
}
