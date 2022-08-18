/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_content_validation-map_content.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:45:16 by jsolinis          #+#    #+#             */
/*   Updated: 2022/07/11 13:45:18 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../Libft/libft.h"

void	ft_vertical_check_inner_void(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while ((i + 1) < map->height)
	{
		j = 0;
		while (map->map_content[i][j])
		{
			if (map->map_content[i][j] == ' ' &&
					map->map_content[i + 1][j] == '0')
				ft_print_error_exit(map,
					"Error. Incorrect map: not surrounded by walls.", 16);
			if (map->map_content[i][j] == '0' &&
					map->map_content[i + 1][j] == ' ')
				ft_print_error_exit(map,
					"Error. Incorrect map: not surrounded by walls.", 16);
			j++;
		}
		i++;
	}
}

void	ft_horizontal_check_inner_void(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map_content[i][j + 1])
		{
			if (map->map_content[i][j] == ' ' &&
					map->map_content[i][j + 1] == '0')
				ft_print_error_exit(map,
					"Error. Incorrect map: not surrounded by walls.", 16);
			if (map->map_content[i][j] == '0' &&
					map->map_content[i][j + 1] == ' ')
				ft_print_error_exit(map,
					"Error. Incorrect map: not surrounded by walls.", 16);
			j++;
		}
		i++;
	}
}

void	ft_validate_content(t_map *map)
{
	ft_vertical_check_inner_void(map);
	ft_horizontal_check_inner_void(map);
}
