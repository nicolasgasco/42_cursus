/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:32:42 by jsolinis          #+#    #+#             */
/*   Updated: 2022/08/07 20:22:09 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

/*ft_is_facing_down returns 1 if the angle is facing down or 0 if 
 * the angle is facing up*/

int	ft_is_facing_down(double angle)
{
	if (angle > ft_transform_angle(180))
		return (1);
	else
		return (0);
}

/*ft_is_facing_right returns 1 if the angle is facing right or 0 if 
 * the angle is facing left*/

int	ft_is_facing_right(double angle)
{
	if (angle < ft_transform_angle(270) && angle > ft_transform_angle(90))
		return (0);
	else
		return (1);
}

/*ft_convert_to_cube_position sets the player position in the 
 * projection dimension*/

void	ft_convert_to_cube_position(t_map *map)
{
	static int	i = 0;

	if (i == 0)
	{
		map->prj->player->y = (map->prj->player->y * map->texture_size)
			+ (map->texture_size / 2);
		map->prj->player->x = (map->prj->player->x * map->texture_size)
			+ (map->texture_size / 2);
	}
	i++;
}

/*ft_set_viewing_angle returns the angle of the view based on 
 * the player orientation*/

void	ft_set_viewing_angle(t_map *map)
{
	char	c;

	c = map->prj->player_orientation;
	if (c == 'E')
		map->prj->view_angle = 0;
	else if (c == 'N')
		map->prj->view_angle = 90;
	else if (c == 'W')
		map->prj->view_angle = 180;
	else
		map->prj->view_angle = 270;
}

/*ft_set_player_data creates and fills the structure for the 
 * projection with the data from the given map*/

void	ft_set_player_data(t_map *map, int *iterator, int *j, char c)
{
	map->prj->player->y = (*iterator);
	map->prj->player->x = (*j);
	map->prj->player_orientation = c;
	ft_set_viewing_angle(map);
	map->prj->distance_to_pp = (WIN_WIDTH / 2)
		/ tan((FIELD_OF_VIEW / 2) * (PI / 180));
	map->map_content[*iterator][*j] = '0';
}
