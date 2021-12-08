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
    pthread_mutex_lock(&philo->c_data->forks_mutex[i]);
    // ft_put_status(philo, 'f');
    pthread_mutex_lock(&philo->c_data->forks_mutex[ft_get_i(philo, i - 1)]);
    ft_put_status(philo, 'f');
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

void	ft_think(t_philo *philo)
{
	ft_sleep(philo);
	ft_put_status(philo, 't');
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
		if (elapsed_time > (philo->c_data->t_death))
			ft_put_status(philo, 'd');
	}
	else if (philo->meals < philo->c_data->n_eats)
	{
		if (ft_calc_time(ft_now(), philo->t_meal) > (philo->c_data->t_death))
			ft_put_status(philo, 'd');
	}
	else
	{
		if (ft_calc_time(ft_now(), philo->t_meal) > (philo->c_data->t_death))
			ft_put_status(philo, 'd');
        if (philo->meals == philo->c_data->n_eats)
		{
			philo->c_data->finished_eating++;
			philo->meals++;
		}
		if (philo->c_data->finished_eating == philo->c_data->n_philos)
		{
			ft_put_status(philo, 'z');
			exit(3);
		}
	}
}