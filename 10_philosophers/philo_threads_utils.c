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

void	*ft_thread_routine(void *vargp)
{
	t_philo	*philo_cpy;

	philo_cpy = vargp;

	// ft_start_eating(philo_cpy, philo_cpy->i_philo);
	ft_print_philo(philo_cpy);
	return (NULL);
}

void	ft_create_threads(t_data *common_data, pthread_t *philos)
{
	t_philo			*philo;
	unsigned int	i;

	i = 0;
	while (i < common_data->n_philos)
	{
		philo = malloc(sizeof(t_philo));
		ft_init_philo(philo, common_data, i);
		if (pthread_create(&philos[i], NULL, ft_thread_routine, philo) != 0)
		{
			ft_putstr(2, "Failed to created thread\n");
			exit (1);
		}
		// printf("Thread %d has started\n", i + 1);
		usleep(50000);
		i++;
	}
	ft_join_threads(common_data, philos);
}

void	ft_join_threads(t_data *common_data, pthread_t *philos)
{
	unsigned int	i;

	i = 0;
	while (i < common_data->n_philos)
	{
		if (pthread_join(philos[i], NULL) != 0)
		{
			ft_putstr(2, "Failed to join thread\n");
			exit (2);
		}
		i++;
	}
	// pthread_mutex_destroy(&common_data->fork_mutex);
}

void	ft_init_threads(t_data *common_data, int argc, char *argv[])
{
	pthread_t		*philos;

	philos = malloc(sizeof(pthread_t) * common_data->n_philos + 1);
	ft_putstr(2, "Creating threads...\n");
	ft_create_threads(common_data, philos);
	printf("After Threads\n");
	free(philos);
}
