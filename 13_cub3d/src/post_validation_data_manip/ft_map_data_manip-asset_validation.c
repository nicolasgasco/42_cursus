/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_data_manip-asset_validation.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/08/07 20:23:51 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../Libft/libft.h"

void	ft_validate_texture_files(t_map *map)
{
	void	*mlx;
	int		is_error;

	is_error = 0;
	mlx = mlx_init();
	if (!ft_xpm_file_is_valid(map, map->no_path, mlx))
		is_error = 1;
	if (!ft_xpm_file_is_valid(map, map->ea_path, mlx))
		is_error = 1;
	if (!ft_xpm_file_is_valid(map, map->so_path, mlx))
		is_error = 1;
	if (!ft_xpm_file_is_valid(map, map->we_path, mlx))
		is_error = 1;
	if (is_error == 1)
		ft_texture_file_invalid(map, mlx);
	free(mlx);
}

int	ft_xpm_file_is_valid(t_map *map, char *path, void *mlx)
{
	void	*img;
	int		width;
	int		height;

	ft_get_texture_sizes(map, path, &width, &height);
	if (width < TEXTURE_MIN_SIZE || width > TEXTURE_MAX_SIZE)
		ft_texture_file_invalid(map, mlx);
	else if (width != height)
		ft_texture_file_invalid(map, mlx);
	if (map->texture_size && width != map->texture_size)
		ft_texture_file_invalid(map, mlx);
	else
		map->texture_size = width;
	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (img == NULL)
		return (0);
	else
		mlx_destroy_image(mlx, img);
	return (1);
}
