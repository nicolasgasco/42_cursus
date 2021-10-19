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
	ft_printf("String is %s\n", g_bin_str);
	if (signum == SIGUSR1)
	{
		ft_printf("Received SIGUSR1!\n\n");
		g_bin_str = ft_strjoin(g_bin_str, "0");
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("Received SIGUSR2!\n\n");
		g_bin_str = ft_strjoin(g_bin_str, "1");
	}
	ft_printf("String is %s\n", g_bin_str);
}

int	main(void)
{
	int		pid;

	pid = getpid();
	g_bin_str = malloc(1);
	ft_printf("Server's PID is %d\n", pid);
	signal(SIGUSR1, msg_handler);
	signal(SIGUSR2, msg_handler);
	while (1)
		sleep (10);
	return (0);
}
