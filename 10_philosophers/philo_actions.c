/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:56:35 by ngasco            #+#    #+#             */
/*   Updated: 2021/12/08 13:56:36 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo, int i, int *fork_l, int *fork_r)
{
	if (philo->c_data->end == 0)
	{
		pthread_mutex_lock(&philo->c_data->forks_mutex[i]);
		*fork_r = 0;
		ft_put_status(philo, 'f');
		pthread_mutex_lock(&philo->c_data->forks_mutex[ft_get_i(philo, i - 1)]);
		*fork_l = 0;
		ft_put_status(philo, 'f');
		philo->meals++;
		gettimeofday(&philo->t_meal, NULL);
		ft_put_status(philo, 'e');
		ft_msleep(philo, philo->c_data->t_eat);
		*fork_l = 1;
		pthread_mutex_unlock(&philo->c_data->forks_mutex[i]);
		*fork_r = 1;
		pthread_mutex_unlock(&philo->c_data->forks_mutex[ft_get_i(philo, i - 1)]);
	}
}

void	ft_think(t_philo *philo)
{
	if (philo->c_data->end == 0)
		ft_put_status(philo, 't');
}

void	ft_sleep(t_philo *philo)
{
	if (philo->c_data->end == 0)
	{
		ft_put_status(philo, 's');
		ft_msleep(philo, philo->c_data->t_sleep);
	}
}

void	ft_death(t_philo *philo)
{
	int	elapsed_time;

	if (philo->c_data->end == 0)
	{
		if (elapsed_time > (philo->c_data->t_death))
				ft_put_status(philo, 'd');
		if (philo->meals == philo->c_data->n_eats)
		{
			philo->c_data->finished_eating++;
			philo->meals++;
		}
		if (philo->c_data->finished_eating == philo->c_data->n_philos)
			philo->c_data->end = 1;
	}
}