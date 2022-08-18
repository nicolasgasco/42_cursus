/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_content_validation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:47:13 by jsolinis          #+#    #+#             */
/*   Updated: 2022/07/11 13:47:14 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#include "../../Libft/libft.h"

void	ft_set_map_line(char *line, t_map *map, int *iterator, int *player)
{
	int	j;

	j = 0;
	map->map_content[*iterator] = (char *) malloc ((map->width + 1)
			* sizeof(char));
	while (line[j] && line[j] != '\n')
	{
		if (ft_is_player_char(line[j]))
		{
			*player = (*player) + 1;
			ft_set_player_data(map, iterator, &j, line[j]);
		}
		else
			map->map_content[*iterator][j] = line[j];
		j++;
	}
	while (j < map->width)
	{
		map->map_content[*iterator][j] = ' ';
		j++;
	}
	map->map_content[*iterator][j] = '\0';
}

void	ft_set_map_content(char *file_path, t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	int		player;

	i = 0;
	player = 0;
	fd = ft_open_file(file_path);
	map->map_content = (char **) malloc (map->height * sizeof(char *));
	line = get_next_line(fd);
	line = ft_skip_to_map_start(line, fd);
	while (i < map->height)
	{
		ft_set_map_line(line, map, &i, &player);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	ft_check_player_number(map, player);
}

void	ft_get_map_size(char *file_path, t_map *map)
{
	int		fd;
	char	*line;

	fd = ft_open_file(file_path);
	line = get_next_line(fd);
	line = ft_skip_to_map_start(line, fd);
	while (line)
	{
		ft_get_map_width(line, map);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	ft_check_newlines(char *file_path, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	map->height = 0;
	fd = ft_open_file(file_path);
	line = get_next_line(fd);
	line = ft_skip_to_map_start(line, fd);
	i = 0;
	while (line)
	{
		if (line[i] == '\n')
			line = ft_check_to_eof(line, fd, map);
		free(line);
		map->height++;
		line = get_next_line(fd);
		i = 0;
		ft_skip_to_content(line, &i);
	}
	free(line);
	close(fd);
}

void	ft_map_content_validation(char *file_path, t_map *map)
{
	ft_check_newlines(file_path, map);
	ft_get_map_size(file_path, map);
	ft_set_map_content(file_path, map);
	ft_validate_size(map);
	ft_check_characters(map);
	ft_validate_walls(map);
	ft_validate_content(map);
}
