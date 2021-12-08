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
	
	if (philo->c_data->end == 1)
	{
		ft_free_mallocs(philo);
		exit(1);
	}
	fork_r = &philo->c_data->forks[index];
	fork_l = &philo->c_data->forks[ft_get_i(philo, index - 1)];
	ft_death(philo);
	if (*fork_r == 1 && *fork_l == 1)
	{
		ft_eat(philo, index, fork_l, fork_r);
		ft_think(philo);
	}
}

void	ft_free_mallocs(t_philo *philo)
{
	free(philo->c_data->forks_mutex);
	free(philo->c_data->forks);
	free(philo);
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
