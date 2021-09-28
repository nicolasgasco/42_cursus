/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:07:24 by ngasco            #+#    #+#             */
/*   Updated: 2021/09/28 20:34:07 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		file_size;
	t_map	map;

	file_size = 0;
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
		ft_open_for_validation(argv[1], &file_size);
		map.map = ft_create_bi_array(argv[1], file_size, &map);
		ft_render_map(&map);
		free(map.map);
	}
	return (1);
}
