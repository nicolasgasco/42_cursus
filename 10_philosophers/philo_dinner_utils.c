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
	int				*fork_right;
	int				*fork_left;

	fork_right = &philo->c_data->forks[index];
	fork_left = &philo->c_data->forks[ft_get_i(philo, index - 1)];
	ft_death(philo);
	if (*fork_right == 1 && *fork_left == 1)
	{
		ft_eat(philo, index, fork_left, fork_right);
		ft_sleep(philo);
		ft_put_status(philo, 't');
	}
}

void	ft_eat(t_philo *philo, int i, int *fork_left, int *fork_right)
{
	pthread_mutex_lock(&philo->c_data->forks_mutex[i]);
	pthread_mutex_lock(&philo->c_data->forks_mutex[ft_get_i(philo, i - 1)]);
	gettimeofday(&philo->t_meal, NULL);
	*fork_right = 0;
	*fork_left = 0;
	ft_put_status(philo, 'e');
	philo->meals++;
	ft_msleep(philo, philo->c_data->t_eat);
	*fork_right = 1;
	*fork_left = 1;
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
		if (elapsed_time > philo->c_data->t_death)
		{
			ft_put_status(philo, 'd');
			exit(1);
		}
	}
	else
	{
		if (ft_calc_time(ft_now(), philo->t_meal) > philo->c_data->t_death)
		{
			ft_put_status(philo, 'd');
			exit(1);
		}
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
