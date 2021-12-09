/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:52:46 by ngasco            #+#    #+#             */
/*   Updated: 2021/12/04 13:52:47 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_common(t_data *c_data, int argc, char *argv[])
{
	if (argc == 6)
		c_data->n_eats = ft_atoi(argv[5]);
	else
		c_data->n_eats = -1;
	c_data->n_philos = ft_atoi(argv[1]);
	c_data->t_death = ft_atoi(argv[2]);
	c_data->t_eat = ft_atoi(argv[3]);
	c_data->t_sleep = ft_atoi(argv[4]);
	c_data->forks = ft_create_forks(c_data->n_philos);
	c_data->forks_mutex = ft_create_forks_mutex(c_data->n_philos);
	c_data->finished_eating = 0;
	c_data->end = 0;
	gettimeofday(&c_data->t_start, NULL);
}

void	ft_init_philo(t_philo *philo, t_data *c_data, int i)
{
	philo->i_philo = i;
	philo->t_meal = c_data->t_start;
	philo->meals = 0;
	philo->c_data = c_data;
}

pthread_mutex_t	*ft_create_forks_mutex(int n_philos)
{
	pthread_mutex_t	*result;

	result = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n_philos);
	return (result);
}

int	*ft_create_forks(int n_philos)
{
	int	*result;
	int	i;

	i = 0;
	result = (int *)malloc(sizeof(int) * n_philos + 1);
	while (i < n_philos)
	{
		result[i] = 1;
		i++;
	}
	result[i] = -1;
	return (result);
}
