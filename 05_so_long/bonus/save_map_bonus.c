/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:28:06 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/02 12:35:25 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_open_file(char *file)
{
	int	fp;

	fp = open(file, O_RDONLY);
	if (fp == -1)
	{
		perror("Error\n");
		exit(0);
	}
	return (fp);
}

char	**ft_close_file(int fp, char **result[])
{
	if (close(fp) == 0)
		return (*result);
	else
	{
		free(*result);
		perror("Error\n");
		exit(0);
	}
}	

char	**ft_create_bi_array(char *file, int size, t_map *map)
{
	int		fp;
	char	**result;
	char	*line;
	int		i;

	i = 0;
	fp = ft_open_file(file);
	result = malloc(size + 1);
	while (1)
	{
		line = ft_get_next_line(fp, 2);
		if (line == NULL)
			break ;
		if (i == 0)
			map->n_cols = ft_map_line_length(line);
		result[i] = ft_strdup(line);
		free(line);
		i++;
	}
	map->n_rows = i;
	result[i] = "\n";
	return (ft_close_file(fp, &result));
}
