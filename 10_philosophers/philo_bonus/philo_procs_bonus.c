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
		usleep(100);
	if (philo->c_data->n_philos > 1)
		ft_multiple_philos(philo);
	else
	{
		ft_msleep(philo, philo->c_data->t_death);
		ft_put_death(philo);
		exit(1);
	}
}

void	*ft_death_routine(void *vargp)
{
	t_philo	*philo_cpy;

	philo_cpy = vargp;
	while (1)
	{
		usleep(100);
		ft_death(philo_cpy);
	}
}

void	ft_multiple_philos(t_philo *philo)
{
	while (1)
	{
		ft_death(philo);
		ft_eat_sleep_think(philo);
	}
}

void	ft_create_procs(t_data *c_data)
{
	t_philo	*philo;
	int		i;
	int		id;

	i = 0;
	id = 1;
	while (i < c_data->n_philos)
	{
		id = fork();
		if (id != 0)
			ft_add_pid(c_data, id, i);
		else
		{
			philo = malloc(sizeof(t_philo));
			ft_init_philo(philo, c_data, i);
			pthread_create(&philo->death_check, NULL, ft_death_routine, philo);
			ft_routine(philo);
			pthread_join(philo->death_check, NULL);
		}
		i++;
	}
	ft_wait_procs(c_data, philo);
}

void	ft_wait_procs(t_data *c_data, t_philo *philo)
{
	int	i;
	int	y;
	int	status;

	i = 0;
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
	ft_free_all(c_data);
}
