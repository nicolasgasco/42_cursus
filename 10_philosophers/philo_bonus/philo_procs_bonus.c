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
	gettimeofday(&philo->c_data->t_start, NULL);
	gettimeofday(&philo->t_meal, NULL);
	if ((philo->i_philo + 1) % 2 == 0)
	{
		usleep(50);
	}
	if (philo->c_data->n_philos > 1)
	{
		ft_multiple_philos(philo);
	}
	else
	{
		ft_msleep(philo, philo->c_data->t_death);
		ft_put_status(philo, 'd');
		ft_free_philo(philo);
	}
}

void	*ft_death_check_routine(void *vargp)
{
	t_philo	*philo_cpy;

	philo_cpy = vargp;
	while (1)
	{
		usleep(100);
		ft_death(philo_cpy);	
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
	// ft_free_philo(philo);
}

void ft_create_procs(t_data *c_data)
{
	t_philo *philo;
	int i;
	int id;
	int	status;

	i = 0;
	id = 1;
	sem_unlink("/forks");
	c_data->forks_sem = sem_open("/forks", O_CREAT, 0, c_data->n_philos);
	sem_unlink("/death");
	c_data->death_sem = sem_open("/death", O_CREAT, 0, 1);
	while (i < c_data->n_philos)
	{
		if (id != 0)
		{
			id = fork();
			if (id != 0)
				ft_add_pid(c_data, id, i);
			else
			{
				philo = malloc(sizeof(t_philo));
				ft_init_philo(philo, c_data, i);
				pthread_create(&philo->death_check, NULL, ft_death_check_routine, philo);
				ft_routine(philo);
			}
		}
		i++;
	}
	i = 0;
	int y = 0;
	while (i < c_data->n_philos)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			y = 0;
			while (y < c_data->n_philos)
			{
				kill(c_data->pids[y], SIGKILL);
				y++;
			}
		}
		i++;
	}
	sem_destroy(c_data->forks_sem);
	sem_destroy(c_data->death_sem);
}