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

#include "philo_bonus.h"

void	ft_eat_sleep_think(t_philo *philo)
{
	int	*fork_l;
	int	*fork_r;

	fork_r = &philo->c_data->forks[philo->i_philo];
	fork_l = &philo->c_data->forks[ft_get_i(philo, philo->i_philo - 1)];
	// pthread_mutex_lock(&philo->c_data->e_mutex);
	// if (*fork_r == 1 && *fork_r == 1 && i)
	// {
		// pthread_mutex_unlock(&philo->c_data->e_mutex);	
		// pthread_mutex_lock(&philo->c_data->f_mutex[ft_get_i(philo, i - 1)]);
		// pthread_mutex_lock(&philo->c_data->f_mutex[i]);
		ft_eat(philo, fork_l, fork_r);
		// pthread_mutex_unlock(&philo->c_data->f_mutex[ft_get_i(philo, i - 1)]);
		// pthread_mutex_unlock(&philo->c_data->f_mutex[i]);
		ft_put_sleep(philo);
		ft_msleep(philo, philo->c_data->t_sleep);
		ft_put_think(philo);
	// }
	// else
	// 	pthread_mutex_unlock(&philo->c_data->e_mutex);	
}

void	ft_eat(t_philo *philo, int *fork_l, int *fork_r)
{
	ft_put_forks(philo);
	*fork_r = 0;
	*fork_l = 0;
	philo->meals++;
	gettimeofday(&philo->t_meal, NULL);
	ft_put_eat(philo);
	ft_msleep(philo, philo->c_data->t_eat);
	*fork_r = 1;
	*fork_l = 1;
}

void	ft_death(t_philo *philo)
{
	int	elapsed_time;

	// pthread_mutex_lock(&philo->c_data->d_mutex);
	if (philo->c_data->end == 0)
	{
		// pthread_mutex_unlock(&philo->c_data->d_mutex);
		elapsed_time = ft_calc_time(ft_now(), philo->t_meal);
		if (elapsed_time > (philo->c_data->t_death))
		{
			philo->c_data->end = 1;
			ft_put_death(philo);
		}
		if (philo->meals == philo->c_data->n_eats)
		{
			philo->c_data->finished_eating++;
			philo->meals++;
		}
		if (philo->c_data->finished_eating == philo->c_data->n_philos)
			philo->c_data->end = 1;
	}
	// else
	// 	pthread_mutex_unlock(&philo->c_data->d_mutex);
}

int	ft_get_i(t_philo *philo, int index)
{
	int	fork_index;

	if (index < 0)
		fork_index = index + philo->c_data->n_philos;
	else if (index >= philo->c_data->n_philos)
		fork_index = index - philo->c_data->n_philos;
	else
		fork_index = index;
	return (fork_index);
}
