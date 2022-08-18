/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_content_validation-map_walls.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:46:13 by jsolinis          #+#    #+#             */
/*   Updated: 2022/07/11 13:46:16 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../Libft/libft.h"

void	ft_check_vertical_wall(int wall, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = wall;
		if (wall == 0)
			ft_skip_to_non_space_char(map->map_content[i], &j);
		else
			ft_skip_to_non_space_char_backwards(map->map_content[i], &j);
		if (map->map_content[i][j] != '1' && map->map_content[i][j] != '\0' &&
				map->map_content[i][j] != ' ')
		{
			ft_print_error_exit(map,
				"Error. Incorrect map: not surrounded by walls.", 13);
		}
		i++;
	}
}

void	ft_check_horizontal_wall(int wall, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width - 1)
	{
		j = wall;
		ft_skip_to_non_space_char(map->map_content[wall], &i);
		if (map->map_content[j][i] == '\0')
			break ;
		while (map->map_content[j][i] == ' ')
		{
			if (wall == 0)
				j++;
			else
				j--;
		}
		if (map->map_content[j][i] != '1')
			ft_print_error_exit(map,
				"Error. Incorrect map: not surrounded by walls.", 13);
		i++;
	}
}

void	ft_validate_walls(t_map *map)
{
	ft_check_vertical_wall(0, map);
	ft_check_vertical_wall((map->width - 1), map);
	ft_check_horizontal_wall(0, map);
	ft_check_horizontal_wall((map->height - 1), map);
}
