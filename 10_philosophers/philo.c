/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:07:18 by ngasco            #+#    #+#             */
/*   Updated: 2021/12/08 13:52:24 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	c_data;

	if (argc < 4 || argc > 6)
	{
		ft_putstr(2, "Error: arguments\n");
		return (1);
	}
	ft_init_common(&c_data, argc, argv);
	if (!ft_common_error(&c_data, argc))
	{
		ft_putstr(2, "Error: arguments\n");
		return (1);
	}
	ft_init_threads(&c_data);
	return (0);
}
