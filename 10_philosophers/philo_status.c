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

void	ft_put_status(t_philo *philo, char flag)
{
	if (philo->c_data->end == 0)
	{
		pthread_mutex_lock(&philo->c_data->status_mutex);
		ft_put_timestamp(philo);
		ft_put_id(philo->i_philo + 1);
		ft_put_action(philo, flag);
		pthread_mutex_unlock(&philo->c_data->status_mutex);
	}
}

void	ft_put_timestamp(t_philo *philo)
{
	ft_putnbr(ft_calc_timestamp(philo->c_data->t_start));
}

void	ft_put_id(int id)
{
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, " ", 1);
}

void	ft_put_action(t_philo *philo, char flag)
{
	if (flag == 'f')
		ft_putstr(1, "has taken a fork\n");
	if (flag == 'e')
		ft_putstr(1, "is eating\n");
	else if (flag == 's')
		ft_putstr(1, "is sleeping\n");
	else if (flag == 't')
		ft_putstr(1, "is thinking\n");
	else if (flag == 'd')
	{
		ft_putstr(1, "died\n");
		philo->c_data->end = 1;
	}
}
