/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:07:24 by ngasco            #+#    #+#             */
/*   Updated: 2021/09/25 12:32:05 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		perror("Not enough arguments");
		return (-1);
	}
	if (argc > 2)
	{
		perror("Too many arguments");
		return (-1);
	}
	if (argc == 2)
	{
		printf("File is: '%s'\n", argv[1]);
		ft_open_for_validation(argv[1]);
		events();
	}
	return (1);
}