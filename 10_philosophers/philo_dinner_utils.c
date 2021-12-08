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

void	ft_start_dinner(t_philo *philo, unsigned int index)
{
	int				*fork_r;
	int				*fork_l;

	fork_r = &philo->c_data->forks[index];
	fork_l = &philo->c_data->forks[ft_get_i(philo, index - 1)];
	ft_death(philo);
	if (*fork_r == 1 && *fork_l == 1)
	{
		ft_eat(philo, index, fork_l, fork_r);
		ft_sleep(philo);
		ft_put_status(philo, 't');
	}
}

void	ft_eat(t_philo *philo, int i, int *fork_l, int *fork_r)
{
	pthread_mutex_lock(&philo->c_data->forks_mutex[i]);
	pthread_mutex_lock(&philo->c_data->forks_mutex[ft_get_i(philo, i - 1)]);
	gettimeofday(&philo->t_meal, NULL);
	*fork_r = 0;
	*fork_l = 0;
	ft_put_status(philo, 'e');
	philo->meals++;
	ft_msleep(philo, philo->c_data->t_eat);
	*fork_r = 1;
	*fork_l = 1;
	pthread_mutex_unlock(&philo->c_data->forks_mutex[i]);
	pthread_mutex_unlock(&philo->c_data->forks_mutex[ft_get_i(philo, i - 1)]);
}

void	ft_sleep(t_philo *philo)
{
	ft_put_status(philo, 's');
	ft_msleep(philo, philo->c_data->t_sleep);
}

void	ft_death(t_philo *philo)
{
	int	elapsed_time;

	if (philo->meals == 0)
	{
		elapsed_time = ft_calc_time(ft_now(), philo->c_data->t_start);
		if (elapsed_time > (philo->c_data->t_death + 5))
			ft_put_status(philo, 'd');
	}
	else
	{
		if (ft_calc_time(ft_now(), philo->t_meal) > (philo->c_data->t_death + 5))
			ft_put_status(philo, 'd');
	}
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
