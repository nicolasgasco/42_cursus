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

void	ft_eat_sleep_think(t_philo *philo, int i)
{
	if (!pthread_mutex_lock(&philo->c_data->f_mutex[ft_get_i(philo, i - 1)])
		&& !pthread_mutex_lock(&philo->c_data->f_mutex[i]))
	{
		gettimeofday(&philo->t_meal, NULL);
		ft_put_forks(philo);
		philo->meals++;
		ft_put_eat(philo);
		ft_msleep(philo, philo->c_data->t_eat);
		pthread_mutex_unlock(&philo->c_data->f_mutex[ft_get_i(philo, i - 1)]);
		pthread_mutex_unlock(&philo->c_data->f_mutex[i]);
		ft_put_sleep(philo);
		ft_msleep(philo, philo->c_data->t_sleep);
		ft_put_think(philo);
	}
}

void	ft_sleep(t_philo *philo)
{
	ft_put_sleep(philo);
	ft_msleep(philo, philo->c_data->t_sleep);
}

void	ft_death(t_philo *philo)
{
	int	elapsed_time;

	if (philo->c_data->end == 0)
	{
		elapsed_time = ft_calc_time(ft_now(), philo->t_meal);
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
