/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:40:30 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/22 17:14:19 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int		pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("Number of arguments is not correct\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	ft_printf("PID is %d\n", pid);
	ft_printf("String is %s\n", message);
	i = 0;
	while (message[i] != '\0')
	{
		ft_inttobin((int)message[i], pid);
		i++;
	}
	return (0);
}
