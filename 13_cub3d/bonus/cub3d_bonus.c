/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:15:12 by jsolinis          #+#    #+#             */
/*   Updated: 2022/07/19 12:54:38 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_map			map;
	t_rdata			rdata;
	t_projection	projection;
	t_vector		player;

	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&projection, 0, sizeof(t_projection));
	map.prj = &projection;
	ft_memset(&player, 0, sizeof(t_vector));
	map.prj->player = &player;
	ft_memset(&rdata, 0, sizeof(t_rdata));
	map.rdata = &rdata;
	ft_scene_desc_file_validation(argc, argv[1], &map);
	ft_post_validation_data_manip(&map);
	ft_render_view(&map);
	return (0);
}
