/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/07/19 12:25:54 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#include "../../Libft/libft.h"

void	ft_render_view(t_map *map)
{
	t_view	view;
	t_data	plane_data;

	ft_memset(&view, 0, sizeof(t_view));
	view.title = ft_strdup(GAME_TITLE);
	view.mlx = mlx_init();
	view.mlx_win = mlx_new_window(view.mlx, WIN_WIDTH,
			WIN_HEIGHT, view.title);
	ft_memset(&plane_data, 0, sizeof(t_data));
	plane_data.img = NULL;
	view.plane_data = &plane_data;
	map->view = &view;
	ft_render_game_scene(map);
	ft_view_events(map);
	mlx_loop(map->view->mlx);
}
