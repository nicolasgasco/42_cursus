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

#include "philo.h"

void	*ft_routine(void *vargp)
{
	t_philo	*philo_cpy;

	philo_cpy = vargp;
	while (philo_cpy->c_data->t_start.tv_sec == 0)
		usleep(10);
	usleep(1000);
	gettimeofday(&philo_cpy->c_data->t_start, NULL);
	gettimeofday(&philo_cpy->t_meal, NULL);
	if (philo_cpy->c_data->n_philos > 1)
	{
		while (philo_cpy->c_data->end == 0)
		{ 
			ft_death(philo_cpy);
			if (philo_cpy->c_data->end == 0)
				ft_eat_sleep_think(philo_cpy, philo_cpy->i_philo);
		}
		ft_free_philo(philo_cpy);
	}
	else
	{
		ft_msleep(philo_cpy, philo_cpy->c_data->t_death);
		ft_put_death(philo_cpy);
		ft_free_philo(philo_cpy);
	}
	return (NULL);
}

// void	ft_init_threads(t_data *c_data)
// {
// 	// pthread_t		*philos;

// 	// philos = malloc(sizeof(pthread_t) * c_data->n_philos);
// 	// ft_create_threads(c_data, philos);
// }

void	ft_create_procs(t_data *c_data)
{
	// t_philo	*philo;
	int		i;
	int		id;

	i = 0;
	// pthread_mutex_init(&c_data->status_mutex, NULL);
	// pthread_mutex_init(&c_data->d_mutex, NULL);
	// pthread_mutex_init(&c_data->e_mutex, NULL);
	// pthread_mutex_init(&c_data->t_mutex, NULL);
	id = fork();
	if (id != 0)
	{
		printf("%d\n", id);
		while (i < c_data->n_philos)
		{
			if (id != 0)
				id = fork();
			if (id != 0)
				printf("Process %d\n", id);
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
