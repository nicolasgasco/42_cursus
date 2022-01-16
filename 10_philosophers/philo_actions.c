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
	int	*fork_l;
	int	*fork_r;

	fork_r = &philo->c_data->forks[philo->i_philo];
	fork_l = &philo->c_data->forks[ft_get_i(philo, philo->i_philo - 1)];
	if (*fork_l == 1 && *fork_r == 1)
	{
		pthread_mutex_lock(&philo->c_data->f_mutex[i]);
		*fork_r = 0;
		ft_put_forks(philo);
		pthread_mutex_lock(&philo->c_data->f_mutex[ft_get_i(philo, i - 1)]);
		*fork_l = 0;
		ft_put_forks(philo);
		gettimeofday(&philo->t_meal, NULL);
		philo->meals++;
		ft_put_eat(philo);
		ft_msleep(philo, philo->c_data->t_eat);
		*fork_l = 1;
		*fork_r = 1;
		pthread_mutex_unlock(&philo->c_data->f_mutex[ft_get_i(philo, i - 1)]);
		pthread_mutex_unlock(&philo->c_data->f_mutex[i]);
		ft_put_sleep(philo);
		ft_msleep(philo, philo->c_data->t_sleep);
		ft_put_think(philo);
	}
}

void	ft_death(t_philo *philo)
{
	if (philo->c_data->end == 0)
	{
		if (ft_calc_time(ft_now(), philo->t_meal) > philo->c_data->t_death)
		{
			ft_put_death(philo);
			philo->c_data->end = 1;
		}
		if (philo->c_data->finished_eating == philo->c_data->n_philos)
			philo->c_data->end = 1;
	}
}

int	ft_get_i(t_philo *philo, int index)
{
	if (index < 0)
		return (philo->c_data->n_philos - 1);
	return (index);
}

void	ft_lock_mutexes(t_philo *philo, int i)
{
	if ((philo->i_philo + 1) % 2 != 0)
	{
		pthread_mutex_lock(&philo->c_data->f_mutex[ft_get_i(philo, i - 1)]);
		pthread_mutex_lock(&philo->c_data->f_mutex[i]);
	}
	else
	{
		pthread_mutex_lock(&philo->c_data->f_mutex[i]);	
		pthread_mutex_lock(&philo->c_data->f_mutex[ft_get_i(philo, i - 1)]);
	}
}