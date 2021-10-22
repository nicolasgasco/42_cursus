/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:42:21 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/22 20:00:48 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_handler(int signo)
{
	unsigned int		counter_bit;
	static int			bin;

	if (!bin)
		bin = 256;
	counter_bit = bin & 65280;
	if (signo == SIGUSR1)
		bin = bin & ~(counter_bit / 256);
	else if (signo == SIGUSR2)
		bin = bin | (counter_bit / 256);
	counter_bit <<= 1;
	bin = (bin & 255) | counter_bit;
	if ((counter_bit / 256) >= 256)
	{
		if ((bin & 255) == 0)
			ft_printf("\n");
		else
			ft_printf("%c", bin & 255);
		bin = 256;
	}
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_printf("Pid is %d.\n", pid);
	signal(SIGUSR1, msg_handler);
	signal(SIGUSR2, msg_handler);
	while (1)
		pause();
	return (0);
}
