/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:27:36 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/02 12:52:20 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_tile(t_map *map, char *path, int off)
{
	t_img		tile;
	static void	*r_tile;
	static char	*previous_path;
	int			i_x;
	int			i_y;

	tile.w = 32;
	tile.h = 32;
	i_x = map->x * 32 + off;
	i_y = map->y * 32 + off;
	if (!previous_path)
		previous_path = ft_strdup(path);
	if (!r_tile || ft_compare_strings(previous_path, path) == 0)
		r_tile = mlx_xpm_file_to_image(map->mlx, path, &tile.w, &tile.h);
	mlx_put_image_to_window(map->mlx, map->win, r_tile, i_x, i_y);
	free(previous_path);
	previous_path = ft_strdup(path);
}

void	ft_populate_map(t_map *map, int offset, int start)
{
	map->x = 0;
	map->y = 0;
	while (map->map[map->y][0] != '\n')
	{
		map->x = 0;
		while (map->map[map->y][map->x] != '\0')
		{
			if (map->map[map->y][map->x] == '0')
				ft_render_tile(map, "./img/water.xpm", offset);
			else if (map->map[map->y][map->x] == '1')
				ft_render_rocks(map, offset, map->y + map->x);
			else if (map->map[map->y][map->x] == 'P')
				ft_render_player(map, offset, map->x, map->y);
			else if (map->map[map->y][map->x] == 'E')
				ft_render_exit(map, offset, start);
			else if (map->map[map->y][map->x] == 'C')
				ft_render_collectible(map, offset, start);
			map->x += 1;
		}
		map->y += 1;
	}
}

void	ft_initialize_stats(t_map *map)
{
	map->end_game = 0;
	map->moves = 0;
	map->n_collect = 0;
	map->enem_n = 0;
	map->p_death = 0;
	map->p_direction = 2;
}

void	ft_welcome_player(void)
{
	ft_put_str("Hello, child! Welcome to 42 Escape.\n");
	ft_put_str("Your goal is escaping in the smallest number of moves.\n");
	ft_put_str("Don't forget to collect all the objects, though...\n");
}

void	ft_render_map(t_map *map)
{
	int	offset;
	int	screen_w;
	int	screen_h;

	offset = 40;
	screen_w = map->n_cols * 32 + offset * 2;
	screen_h = map->n_rows * 32 + offset * 2;
	if (screen_w > 2048 || screen_h > 1080)
	{
		ft_put_str("Error\n");
		ft_put_str("Map is too big.\n");
		exit(0);
	}
	else
	{
		ft_welcome_player();
		map->mlx = mlx_init();
		map->win = mlx_new_window(map->mlx, screen_w, screen_h, "42 Escape");
		ft_initialize_stats(map);
		ft_populate_map(map, offset, 1);
		ft_listen_events(map);
		mlx_loop(map->mlx);
	}
}
