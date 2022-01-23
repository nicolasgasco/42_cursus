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
	ft_eat(philo);
	ft_put_status(philo, 's');
	ft_msleep(philo, philo->c_data->t_sleep);
	ft_put_status(philo, 't');
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->c_data->forks_sem);
	ft_put_status(philo, 'f');
	ft_death(philo);
	sem_wait(philo->c_data->forks_sem);
	ft_put_status(philo, 'f');
	ft_death(philo);
	gettimeofday(&philo->t_meal, NULL);
	philo->meals++;
	ft_put_status(philo, 'e');
	ft_msleep(philo, philo->c_data->t_eat);
	sem_post(philo->c_data->forks_sem);
	sem_post(philo->c_data->forks_sem);
}

void	ft_death(t_philo *philo)
{
	sem_wait(philo->c_data->death_sem);
	if (ft_calc_time(ft_now(), philo->t_meal) > philo->c_data->t_death)
	{
		ft_put_death(philo);
		exit(1);
	}
	if (philo->c_data->n_eats > 0
		&& philo->meals == (philo->c_data->n_eats + 1))
		exit(1);
	sem_post(philo->c_data->death_sem);
}

