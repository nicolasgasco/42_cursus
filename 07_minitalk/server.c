/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:42:21 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/19 19:44:02 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Received SIGUSR1!\n\n");
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("Received SIGUSR2!\n\n");
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server's PID is %d\n", pid);
	if (signal(SIGUSR1, msg_handler))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (signal(SIGUSR2, msg_handler))
	{
		ft_printf("Error\n");
		return (1);
	}
	while (1)
		sleep (10);
	return (0);
}
