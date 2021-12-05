/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:07:18 by ngasco            #+#    #+#             */
/*   Updated: 2021/12/05 17:07:19 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data			common_data;
	pthread_t		*philos;
	unsigned int	i;

	if (argc < 4 || argc > 6)
	{
		ft_putstr(2, "Error: arguments\n");
		return (1);
	}
	ft_init_common(&common_data, argc, argv);
	ft_print_common(&common_data);
	ft_init_threads(&common_data, argc, argv);
	return (0);
}
