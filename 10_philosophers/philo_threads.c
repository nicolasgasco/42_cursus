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
	usleep(500000);
	gettimeofday(&philo_cpy->c_data->t_start, NULL);
	gettimeofday(&philo_cpy->t_meal, NULL);
	if (philo_cpy->c_data->n_philos > 1)
		ft_valid_sym(philo_cpy);
	else
	{
		ft_msleep(philo_cpy, philo_cpy->c_data->t_death);
		ft_put_death(philo_cpy);
		ft_free_philo(philo_cpy);
	}
	return (NULL);
}

void	ft_valid_sym(t_philo *philo_cpy)
{
	while (philo_cpy->c_data->end == 0)
		ft_eat_sleep_think(philo_cpy, philo_cpy->i_philo);
	ft_free_philo(philo_cpy);
}

void	ft_init_threads(t_data *c_data)
{
	pthread_t		*philos;

	philos = malloc(sizeof(pthread_t) * c_data->n_philos);
	ft_create_threads(c_data, philos);
}

void	ft_create_threads(t_data *c_data, pthread_t *philos)
{
	t_philo	*philo;
	int		i;

	i = 0;
	ft_init_c_mutex(c_data);
	while (i < c_data->n_philos)
	{
		if (i == c_data->n_philos - 1)
			gettimeofday(&c_data->t_start, NULL);
		philo = malloc(sizeof(t_philo));
		ft_init_philo(philo, c_data, i);
		pthread_mutex_init(&c_data->f_mutex[i], NULL);
		pthread_create(&philos[i], NULL, ft_routine, philo);
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
		pthread_join(philos[i], NULL);
		i++;
	}
	i = 0;
	while (i < c_data->n_philos)
	{
		pthread_mutex_destroy(&c_data->f_mutex[i]);
		i++;
	}
	ft_destroy_c_mutex(c_data);
	ft_free_c_data(c_data);
	ft_free_philos(philos);
}
