/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:40:26 by jsolinis          #+#    #+#             */
/*   Updated: 2022/07/11 13:40:27 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_is_map_start(char *line)
{
	int	i;

	i = 0;
	ft_skip_to_non_space_char(line, &i);
	if (line[i] && line[i] == '1')
		return (1);
	return (0);
}

void	ft_get_map_width(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		i++;
		if (i > map->width)
			map->width = i;
	}
}

char	*ft_skip_to_map_start(char *line, int fd)
{
	while (line)
	{
		if (ft_is_map_start(line) == 0)
		{
			free(line);
			line = get_next_line(fd);
		}
		else
			break ;
	}
	return (line);
}

void	ft_skip_to_non_space_char_backwards(char *line, int *iterator)
{
	while (*iterator != 0)
	{
		if (ft_isspace(line[*iterator]))
			*iterator -= 1;
		else
			return ;
	}
}

char	*ft_check_to_eof(char *line, int fd, t_map *map)
{
	int	i;

	i = 0;
	free(line);
	line = get_next_line(fd);
	ft_skip_to_content(line, &i);
	if (line && line[i] != '\n')
	{
		map->height = -1;
		free(line);
		ft_print_error_exit(map, "Error: newlines in between the map.", 26);
	}
	return (line);
}
