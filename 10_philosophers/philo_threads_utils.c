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

void	ft_init_threads(t_data *c_data)
{
	pthread_t		*philos;

	philos = malloc(sizeof(pthread_t) * c_data->n_philos);
	ft_create_threads(c_data, philos);
	free(philos);
}

void	*ft_routine(void *vargp)
{
	t_philo	*philo_cpy;

	philo_cpy = vargp;
	if (philo_cpy->c_data->n_forks > 1)
	{
		while (1)
			ft_start_dinner(philo_cpy, philo_cpy->i_philo);
	}
	else
	{
		ft_msleep(philo_cpy, philo_cpy->c_data->t_death);
		ft_put_status(philo_cpy, 'd');
		ft_free_mallocs(philo_cpy);
	}
	return (NULL);
}

void	ft_create_threads(t_data *c_data, pthread_t *philos)
{
	t_philo	*philo;
	int		i;

	i = 0;
	pthread_mutex_init(&c_data->status_mutex, NULL);
	while (i < c_data->n_philos)
	{
		philo = malloc(sizeof(t_philo));
		ft_init_philo(philo, c_data, i);
		pthread_mutex_init(&c_data->forks_mutex[i], NULL);
		if (pthread_create(&philos[i], NULL, ft_routine, philo) != 0)
		{
			ft_putstr(2, "Failed to created thread\n");
			exit (1);
		}
		i++;
	}
	ft_join_threads(c_data, philos);
}

void	ft_join_threads(t_data *c_data, pthread_t *philos)
{
	int	i;

	i = 0;
	while (i < c_data->n_philos)
	{
		if (pthread_join(philos[i], NULL) != 0)
		{
			ft_putstr(2, "Failed to join thread\n");
			exit (2);
		}
		pthread_mutex_destroy(&c_data->forks_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&c_data->status_mutex);
}
