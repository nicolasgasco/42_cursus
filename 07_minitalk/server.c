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
	
	i = ft_strlen(str);
	j = 0;
	result = 0;
	mult = 1;
	while (i > 0)
	{
		printf("%c\n", str[i -1]);
		if (str[i - 1] == '1')
			result = result | mult;
		else
			result = result & ~mult;
		mult *= 2;
		i--;
	}
	ft_printf("Number is %d\n", result);
	ft_printf("Character is %c\n", result);
}

void	msg_handler(int signo)
{
	int	counter_bit;

	// ft_printf("g_bin result is %d\n", g_bin);
	// ft_printf("counter_bit is %d\n", counter_bit / 256);
	counter_bit = g_bin & 65280; // clean first 8 bits
	if (signo == SIGUSR1)
	{
		// ft_printf("0");
		// ft_printf("g_bin before is %d\n", g_bin);
		// ft_printf("N bit is %d\n", counter_bit / 256);
		g_bin = g_bin & ~(counter_bit / 256);
		// ft_printf("g_bin after is %d\n", g_bin);

	}
	else if (signo == SIGUSR2)
	{
		// ft_printf("1");
		// ft_printf("g_bin before is %d\n", g_bin);
		// ft_printf("N bit is %d\n", counter_bit / 256);
		g_bin = g_bin | (counter_bit / 256);
		// ft_printf("g_bin after is %d\n", g_bin);
	}
	counter_bit <<= 1; // shift one
	g_bin = (g_bin & 255) | counter_bit;
	// ft_printf("counter_bit is %d\n", counter_bit / 256);
	if ((counter_bit / 256) == 256)
	{
		// printf("\n");
		// ft_printf("Mierda\n");
		ft_printf("%c", g_bin & 255);
		g_bin = 256;
	} 
	// ft_printf("counter_bit is %d\n", counter_bit);

	// ft_printf("counter_bit shifted is %d\n", counter_bit);
}

int	main(void)
{
	int		pid;

	g_bin = 256;
	pid = getpid();
	ft_printf("Server's PID is %d\n", pid);
	signal(SIGUSR1, msg_handler);
	signal(SIGUSR2, msg_handler);
	while (1)
	{
		// if (g_bin_str[0] != '\0' && (ft_strcmp(g_bin_str, comp_str) == 0))
		// {
		// 	ft_printf("Result is %s\n", g_bin_str);
		// 	ft_store_bin(g_bin_str);
		// }
		// comp_str = ft_strdup(g_bin_str);
		sleep (3);
	}
	return (0);
}
