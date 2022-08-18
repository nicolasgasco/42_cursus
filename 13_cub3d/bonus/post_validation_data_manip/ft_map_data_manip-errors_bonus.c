/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_desc_file_validation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/06/09 13:14:58 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#include "../../Libft/libft.h"

void	ft_color_not_valid_error(void)
{
	ft_putendl_fd("Error: color code not valid", STDERR_FILENO);
	exit(13);
}

void	ft_texture_file_invalid(t_map *map, void *mlx)
{
	ft_free_allocated_map_data(map);
	if (mlx)
		free(mlx);
	ft_putendl_fd("Error: texture file is invalid", STDERR_FILENO);
	exit(14);
}
