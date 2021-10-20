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

void	ft_store_bin(char *str)
{
	int	i;
	int	result;
	int	mult;
	int	j;
	
	i = 0;
	j = 0;
	result = 0;
	mult = 2;
	while (str[i] != '\0')
	{
		if (i == 0)
		{
			if (str[i] == '1')
				result = result | 1;
			else
				result = result & ~1;
		}
		else
		{
			mult *= 2;
			if (str[i] == '1')
				result = result | mult;
			else
				result = result & ~1;
		}
		i++;
	}
	printf("Number is %d\n", result);
}

void	msg_handler(int signum)
{
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
}

int	main(void)
{
	int		pid;
	char	*comp_str;

	pid = getpid();
	g_bin_str = malloc(1);
	g_bin_str = ft_strjoin(g_bin_str, "");
	g_bin_str = malloc(1);
	comp_str = ft_strjoin(g_bin_str, "");
	ft_printf("Server's PID is %d\n", pid);
	signal(SIGUSR1, msg_handler);
	signal(SIGUSR2, msg_handler);
	while (1)
	{
		if (g_bin_str[0] != '\0' && (ft_strcmp(g_bin_str, comp_str) == 0))
		{
			ft_printf("Result is %s\n", g_bin_str);
			ft_store_bin(g_bin_str);
		}
		comp_str = ft_strdup(g_bin_str);
		usleep (500);
	}
	return (0);
}
