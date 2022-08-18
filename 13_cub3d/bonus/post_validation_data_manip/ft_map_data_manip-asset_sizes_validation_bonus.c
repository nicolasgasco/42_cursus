/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_data_manip-asset_sizes_validation.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/08/07 20:25:49 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#include "../../Libft/libft.h"

void	ft_get_texture_sizes(t_map *map, char *path, int *width, int *height)
{
	int		file_fd;
	char	*line;

	file_fd = open(path, O_RDONLY);
	ft_asset_file_error(file_fd, map);
	while (1)
	{
		line = get_next_line(file_fd);
		if (line == NULL)
		{
			close(file_fd);
			return ;
		}
		if (line[1] >= '1' && line[1] <= '9')
			break ;
		free(line);
	}
	ft_parse_texture_sizes(line, width, height);
	free(line);
	close(file_fd);
}

void	ft_parse_texture_sizes(char *line, int *width, int *height)
{
	int		i;
	char	*num_str;
	int		len;

	i = 1;
	ft_skip_to_non_space_char(line, &i);
	len = ft_calc_size_len(line, i);
	num_str = ft_substr(line, i, len);
	*width = ft_atoi(num_str);
	free(num_str);
	i += len;
	ft_skip_to_non_space_char(line, &i);
	num_str = ft_substr(line, i, ft_calc_size_len(line, i));
	*height = ft_atoi(num_str);
	free(num_str);
	return ;
}

void	ft_asset_file_error(int file_fd, t_map *map)
{
	if (file_fd == -1)
	{
		ft_free_allocated_map_data(map);
		ft_open_file_error();
	}
}
