/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:27:36 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/02 12:35:30 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_welcome_player(void)
{
	ft_put_str("Hello, child! Welcome to 42 Escape.\n");
	ft_put_str("Your goal is escaping in the smallest number of moves.\n");
	ft_put_str("Don't forget to collect all the objects, though...\n");
}

void	ft_render_initial_text(t_map *map, int col, int t_y)
{
	char	*str1;
	char	*str2;

	str1 = "Hello, child!";
	str2 = "Moves: ";
	mlx_string_put(map->mlx, map->win, 40, 25, col, str1);
	mlx_string_put(map->mlx, map->win, map->n_cols * 32 - 30, t_y, col, str2);
}

void	ft_render_black_box(t_map *map)
{
	t_img	b;
	int		n_cols;
	void	*mlx;

	mlx = map->mlx;
	n_cols = map->n_cols * 32;
	b.w = 20;
	b.w = 30;
	map->b_tile = mlx_xpm_file_to_image(mlx, "./img/black.xpm", &b.w, &b.h);
	mlx_put_image_to_window (mlx, map->win, map->b_tile, n_cols + 30, 10);
}

void	ft_render_ui(t_map *map, int start)
{
	t_img	b;
	char	*mvs;
	int		col;
	int		t_y;

	t_y = 25;
	col = 0x00FFFFFF;
	b.w = 20;
	b.w = 30;
	mvs = ft_itoa(map->moves);
	if (start)
		ft_render_initial_text(map, 0x00FFFFFF, t_y);
	ft_render_black_box(map);
	mlx_string_put(map->mlx, map->win, map->n_cols * 32 + 30, t_y, col, mvs);
	free(mvs);
}
