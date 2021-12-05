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

void	ft_init_struct(t_data *common_data, int argc, char *argv[])
{
	if (argc == 6)
		common_data->n_eats = ft_atoi(argv[5]);
	else
		common_data->n_eats = -1;
	common_data->n_philos = ft_atoi(argv[1]);
	common_data->t_death = ft_atoi(argv[2]);
	common_data->t_eat = ft_atoi(argv[3]);
	common_data->t_sleep = ft_atoi(argv[4]);
	common_data->forks = ft_init_forks(common_data->n_philos);
	gettimeofday(&common_data->t_start, NULL);
}
