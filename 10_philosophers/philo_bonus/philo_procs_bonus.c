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

void	ft_routine(t_philo *philo)
{
	printf("Inside routine (%d)\n", philo->i_philo);
	// while (philo->c_data->t_start.tv_sec == 0)
	// 	usleep(10);
	// usleep(1000);
	gettimeofday(&philo->c_data->t_start, NULL);
	gettimeofday(&philo->t_meal, NULL);
	if (philo->c_data->n_philos > 1)
	{
		printf("Inside normal case (%d)\n", philo->i_philo);
		while (philo->c_data->end == 0)
		{ 
			ft_death(philo);
			if (philo->c_data->end == 0)
				ft_eat_sleep_think(philo);
		}
		ft_free_philo(philo);
	}
	else
	{
		printf("One philosopher (%d)\n", philo->i_philo);
		ft_msleep(philo, philo->c_data->t_death);
		ft_put_death(philo);
		// ft_free_philo(philo);
	}
	return;
}

// void	ft_init_threads(t_data *c_data)
// {
// 	// pthread_t		*philos;

// 	// philos = malloc(sizeof(pthread_t) * c_data->n_philos);
// 	// ft_create_threads(c_data, philos);
// }

void	ft_create_procs(t_data *c_data)
{
	t_philo	*philo;
	int		i;
	int		id;

	i = 0;
	id = fork();
	if (id == 0)
	{
		// waitpid(id, NULL, 0);
		while (i < c_data->n_philos)
		{
			if (id == 0)
			{
				id = fork();
				// waitpid(id, NULL, 0);
				if (id != 0)
				{
					philo = malloc(sizeof(t_philo));
					ft_init_philo(philo, c_data, i);
					if (i == c_data->n_philos - 1)
						gettimeofday(&c_data->t_start, NULL);
					printf("%d (%d)\n", id, philo->i_philo);
					ft_routine(philo);
				}
			}
			i++;
		}
	}
}

void	ft_join_threads(t_data *c_data, pthread_t *philos)
{
	int	i;

	i = 0;
	while (i < c_data->n_philos)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
	i = 0;
	while (i < c_data->n_philos)
	{
		pthread_mutex_destroy(&c_data->f_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&c_data->status_mutex);
	pthread_mutex_destroy(&c_data->d_mutex);
	pthread_mutex_destroy(&c_data->e_mutex);
	pthread_mutex_destroy(&c_data->t_mutex);
	ft_free_c_data(c_data);
	ft_free_philos(philos);
}
