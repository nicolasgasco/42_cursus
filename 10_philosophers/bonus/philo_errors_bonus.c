/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:21:50 by ngasco            #+#    #+#             */
/*   Updated: 2021/12/12 18:21:51 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_common_error(t_data *c_data, int argc)
{
	if (c_data->n_philos <= 0 || c_data->n_philos > 200)
		return (0);
	if (c_data->t_death <= 0 || c_data->t_sleep <= 0 || c_data->t_eat <= 0)
	{
		ft_free_c_data(c_data);
		return (0);
	}
	if (argc == 6 && c_data->n_eats <= 0)
	{
		ft_free_c_data(c_data);
		return (0);
	}
	return (1);
}
