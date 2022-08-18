/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_data_manip-texture_files.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/08/07 20:24:59 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#include "../../Libft/libft.h"

void	ft_parse_all_texture_files(t_map *map)
{
	map->rdata->textures = (t_tdata *)malloc(sizeof(t_tdata) * NUM_OF_TEXTURES);
	ft_memset(map->rdata->textures, 0, sizeof(t_tdata *));
	map->rdata->textures[NO_TEXTURE_I] = ft_parse_texture_file(map->no_path);
	map->rdata->textures[EA_TEXTURE_I] = ft_parse_texture_file(map->ea_path);
	map->rdata->textures[SO_TEXTURE_I] = ft_parse_texture_file(map->so_path);
	map->rdata->textures[WE_TEXTURE_I] = ft_parse_texture_file(map->we_path);
	ft_write_debug_msg_int("All textures parsed ", 0);
}

t_tdata	ft_parse_texture_file(char *texture_path)
{
	t_tdata	texture;
	int		fd;
	char	*line;

	fd = open(texture_path, O_RDONLY);
	if (fd == -1)
		ft_open_file_error();
	ft_memset(&texture, 0, sizeof(t_tdata));
	line = NULL;
	ft_readline_asset_sizes(fd, line, &texture);
	ft_readline_color_codes(fd, line, &texture);
	ft_readline_char_map(fd, line, &texture);
	close(fd);
	return (texture);
}
