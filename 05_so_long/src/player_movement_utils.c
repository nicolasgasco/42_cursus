/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:27:26 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/02 12:36:42 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap_tiles(char *tile1, char *tile2)
{
	char	temp;

	temp = *tile1;
	*tile1 = *tile2;
	*tile2 = temp;
}

void	ft_remove_collect(char *player, char *collect)
{
	char	temp;

	*collect = *player;
	*player = '0';
}

void	ft_found_exit(char *player, char *collect)
{
	char	temp;

	*collect = *player;
	*player = '0';
}

void	ft_check_if_end(t_map *map)
{
	long	i;

	i = 0;
	if (map->end_game == 1 || map->p_death == 1)
	{
		while (i != 222222222)
			i++;
		ft_put_str("So long, child...\n");
		mlx_destroy_window(map->mlx, map->win);
		free(map->map);
		free(map->b_tile);
		free(map->r_tile);
		exit(0);
	}
}

void	ft_print_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		ft_put_str(map[y]);
		y++;
	}
}
