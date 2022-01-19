/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:55:34 by ngasco            #+#    #+#             */
/*   Updated: 2021/12/12 17:55:35 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_put_timestamp(t_philo *philo)
{
	ft_putnbr(ft_calc_timestamp(philo->c_data->t_start));
}

void	ft_put_id(int id)
{
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, " ", 1);
}
