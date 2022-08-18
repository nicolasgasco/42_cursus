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

void	ft_readline_asset_sizes(int fd, char *line, t_tdata *texture)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[1] >= '1' && line[1] <= '9')
		{
			ft_parse_asset_sizes(line, texture);
			free(line);
			break ;
		}
		free(line);
	}
}

void	ft_parse_asset_sizes(char *line, t_tdata *texture)
{
	int		i;
	int		len;
	char	*num_str;

	i = 1;
	ft_skip_to_non_space_char(line, &i);
	len = ft_calc_size_len(line, i);
	num_str = ft_substr(line, i, len);
	texture->texture_w = ft_atoi(num_str);
	free(num_str);
	i += len;
	ft_skip_to_non_space_char(line, &i);
	num_str = ft_substr(line, i, ft_calc_size_len(line, i));
	texture->texture_h = ft_atoi(num_str);
	free(num_str);
}

int	ft_calc_size_len(char *line, int iterator)
{
	int	i;

	i = iterator;
	while (line[i] != '\0')
	{
		if (line[i] <= '0' || line[i] >= '9')
			return (i);
		i++;
	}
	return (i);
}
