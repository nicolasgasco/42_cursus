/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:27:36 by ngasco            #+#    #+#             */
/*   Updated: 2021/09/28 20:39:07 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_welcome_player()
{
	ft_put_str("Hello, child! Welcome to 42 Escape.\n");
	ft_put_str("The aim of the game is escaping in the smallest number of moves.\n");
	ft_put_str("Don't forget to collect all the objects, though...\n");
}

void	ft_put_moves(t_map *map)
{		
	ft_put_str("Moves: ");
	ft_putnbr_fd(map->moves, 1);
	ft_put_str("\n");
	ft_render_ui(map, 40);
}

void	ft_render_ui(t_map *map, int start)
{
	int		text_y;
	int		width;
	int		height;
	t_img	black;

	text_y = 25;
	black.width = 20;
	black.height = 30;
	if (start)
	{
		mlx_string_put(map->mlx, map->win, 40, 25, 0x00FFFFFF, "Hello, child!");
		mlx_string_put(map->mlx, map->win, map->n_cols * 32 - 30, text_y, 0x00FFFFFF, "Moves: ");
	}
	black.rendered_tile = mlx_xpm_file_to_image(map->mlx, "./img/black.xpm", &black.width, &black.height);
	mlx_put_image_to_window (map->mlx, map->win, black.rendered_tile, map->n_cols * 32 + 30, 10);
	mlx_string_put(map->mlx, map->win, map->n_cols * 32 + 30, text_y, 0x00FFFFFF, ft_itoa(map->moves));
}