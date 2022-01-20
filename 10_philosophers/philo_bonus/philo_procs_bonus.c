/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:07:18 by ngasco            #+#    #+#             */
/*   Updated: 2021/12/05 17:30:23 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void ft_routine(t_philo *philo)
{
	while (philo->c_data->t_start.tv_usec == 0)
		usleep(100);
	gettimeofday(&philo->c_data->t_start, NULL);
	gettimeofday(&philo->t_meal, NULL);
	if ((philo->i_philo + 1) % 2 != 0)
		usleep(500);
	if (philo->c_data->n_philos > 1)
		ft_multiple_philos(philo);
	else
	{
		ft_msleep(philo, philo->c_data->t_death);
		ft_put_status(philo, 'd');
		ft_free_philo(philo);
	}
}

void ft_multiple_philos(t_philo *philo)
{
	while (philo->c_data->end == 0)
	{
		ft_death(philo);
		if (philo->c_data->end == 0)
			ft_eat_sleep_think(philo);
	}
	ft_free_philo(philo);
}

void ft_create_procs(t_data *c_data)
{
	t_philo *philo;
	int i;
	int id;

	i = 0;
	id = 1;
	while (i < c_data->n_philos)
	{
		if (id != 0)
		{
			id = fork();
			if (id != 0)
			{
				ft_add_pid(c_data, id, i);
				printf("%d (%d)\n", id, i);
			}
			else
			{
				philo = malloc(sizeof(t_philo));
				ft_init_philo(philo, c_data, i);
				// if (i == c_data->n_philos - 1)
				// 	gettimeofday(&c_data->t_start, NULL);
				printf("%d (%d)\n", id, philo->i_philo);
				// ft_routine(philo);
			}
		}
		i++;
	}
	// i = 0;
	// while (i < c_data->n_philos)
	// {
	// 	waitpid(c_data->pids[i], &status, 0);
	// 	i++;
	// }
	// ft_put_pids(c_data);
}