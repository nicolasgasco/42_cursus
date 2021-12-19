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

#include "philo_bonus.h"

void	ft_put_forks(t_philo *philo)
{
	int	timestamp;
	int	id;

	pthread_mutex_lock(&philo->c_data->status_mutex);
	if (philo->c_data->end == 0)
	{
		id = philo->i_philo + 1;
		timestamp = ft_calc_timestamp(philo->c_data->t_start);
		ft_putnbr(timestamp);
		ft_put_id(id);
		ft_putstr(1, "has taken a fork\n");
		ft_putnbr(timestamp);
		ft_put_id(id);
		ft_putstr(1, "has taken a fork\n");
	}
	pthread_mutex_unlock(&philo->c_data->status_mutex);

}

void	ft_put_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->c_data->status_mutex);
	if (philo->c_data->end == 0)
	{
		ft_put_timestamp(philo);
		ft_put_id(philo->i_philo + 1);
		ft_putstr(1, "is eating\n");
	}
	pthread_mutex_unlock(&philo->c_data->status_mutex);
}

void	ft_put_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->c_data->status_mutex);
	if (philo->c_data->end == 0)
	{
		ft_put_timestamp(philo);
		ft_put_id(philo->i_philo + 1);
		ft_putstr(1, "is sleeping\n");
	}
	pthread_mutex_unlock(&philo->c_data->status_mutex);
}

void	ft_put_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->c_data->status_mutex);
	if (philo->c_data->end == 0)
	{
		ft_put_timestamp(philo);
		ft_put_id(philo->i_philo + 1);
		ft_putstr(1, "is thinking\n");
	}
	pthread_mutex_unlock(&philo->c_data->status_mutex);
}

void	ft_put_death(t_philo *philo)
{
	// pthread_mutex_lock(&philo->c_data->status_mutex);
	ft_put_timestamp(philo);
	ft_put_id(philo->i_philo + 1);
	ft_putstr(1, "died\n");
	// pthread_mutex_unlock(&philo->c_data->status_mutex);
}
