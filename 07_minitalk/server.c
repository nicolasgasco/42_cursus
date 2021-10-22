/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:42:21 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/22 17:46:41 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_handler(int signo)
{
	int			counter_bit;
	static int	g_bin;

	if (!g_bin)
		g_bin = 256;
	counter_bit = g_bin & 65280;
	if (signo == SIGUSR1)
		g_bin = g_bin & ~(counter_bit / 256);
	else if (signo == SIGUSR2)
		g_bin = g_bin | (counter_bit / 256);
	counter_bit <<= 1;
	g_bin = (g_bin & 255) | counter_bit;
	if ((counter_bit / 256) == 256)
	{
		ft_printf("%c", g_bin & 255);
		g_bin = 256;
	}
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_printf("Pid is %d\n", pid);
	signal(SIGUSR1, msg_handler);
	signal(SIGUSR2, msg_handler);
	while (1)
	{
		sleep (1);
	}
	return (0);
}
