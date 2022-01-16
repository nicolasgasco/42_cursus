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
	int	timestamp;

	timestamp = ft_calc_timestamp(philo->c_data->t_start);
	pthread_mutex_lock(&philo->c_data->death_mutex);
	if (philo->c_data->end == 1 && flag != 'd')
	{
		pthread_mutex_unlock(&philo->c_data->death_mutex);
		return ;
	}
	else
		pthread_mutex_unlock(&philo->c_data->death_mutex);
	pthread_mutex_lock(&philo->c_data->status_mutex);
	if (flag == 'f')
		printf("%d %d has taken a fork\n", timestamp, philo->i_philo + 1);
	else if (flag == 'e')
		printf("%d %d is eating\n", timestamp, philo->i_philo + 1);
	else if (flag == 's')
		printf("%d %d is sleeping\n", timestamp, philo->i_philo + 1);
	else if (flag == 't')
		printf("%d %d is thinking\n", timestamp, philo->i_philo + 1);
	else if (flag == 'd')
		printf("%d %d died\n", timestamp, philo->i_philo + 1);
	pthread_mutex_unlock(&philo->c_data->status_mutex);
}