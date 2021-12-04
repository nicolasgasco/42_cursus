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

void	ft_init_struct(philo *philo, int argc, char *argv[])
{
	if (argc == 6)
		philo->n_eats = ft_atoi(argv[5]);
	else
		philo->n_eats = -1;
	philo->n_philos = ft_atoi(argv[1]);
	philo->t_death = ft_atoi(argv[2]);
	philo->t_eat = ft_atoi(argv[3]);
	philo->t_sleep = ft_atoi(argv[4]);
}
