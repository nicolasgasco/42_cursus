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

#include "philo_bonus.h"

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
	if (c_data->n_philos > 0 && c_data->n_philos <= 200)
	{
		c_data->pids = malloc(sizeof(int) * c_data->n_philos);
	}
	c_data->finished_eating = 0;
	c_data->end = 0;
	c_data->t_start.tv_sec = 0;
	c_data->t_start.tv_usec = 0;
}

void	ft_init_philo(t_philo *philo, t_data *c_data, int i)
{
	philo->i_philo = i;
	philo->t_meal = c_data->t_start;
	philo->meals = 0;
	philo->c_data = c_data;
}

void	ft_add_pid(t_data *c_data, int pid, int i)
{
	c_data->pids[i] = pid;
}

void	ft_put_pids(t_data *c_data)
{
	int	i;

	i = 0;
	printf("\n");
	while (i < c_data->n_philos)
	{
		printf("%d , ", c_data->pids[i]);
		i++;
	}
	printf("\n");
}