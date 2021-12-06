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

void	ft_init_common(t_data *common_data, int argc, char *argv[])
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

void	ft_init_philo(t_philo *philo, t_data *common_data, int i)
{
	philo->i_philo = i;
	// philo->fork = 1;
	philo->common_data = common_data;
}

int *ft_init_forks(int n_philos)
{
    int *result;
    int i;

    i = 0;
    result = (int *)malloc(sizeof(int) * n_philos + 1);
    while(i < n_philos)
    {
        result[i] = 1;
        i++;
    }
    result[i] = -1;
    return (result);
}