/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/07/19 12:33:57 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../Libft/libft.h"

void	ft_free_allocated_map_data(t_map *map)
{
	if (map->map_content)
		ft_free_map_content(map);
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->we_path)
		free(map->we_path);
	if (map->f_color)
		free(map->f_color);
	if (map->c_color)
		free(map->c_color);
	if (map->rdata)
		ft_free_allocated_render_data(map);
}

void	ft_free_map_content(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->map_content[i])
			free(map->map_content[i]);
		i++;
	}
	free(map->map_content);
}

void	ft_free_allocated_render_data(t_map *map)
{
	int		i;
	t_tdata	*texture;

	i = 0;
	if (!map->rdata->textures)
		return ;
	while (i < NUM_OF_TEXTURES)
	{
		texture = &map->rdata->textures[i];
		ft_free_col_info_list(texture);
		ft_free_texture_columns(map, texture);
		i++;
	}
	free(map->rdata->textures);
}

void	ft_free_col_info_list(t_tdata *texture)
{
	struct s_cinfo	*curr;
	struct s_cinfo	*temp;

	curr = texture->col_info_list;
	while (curr)
	{
		if (curr->next)
		{
			temp = curr;
			curr = temp->next;
			free(temp);
		}
		else
		{
			free(curr);
			break ;
		}
	}
}

void	ft_free_texture_columns(t_map *map, t_tdata *texture)
{
	int	j;

	j = 0;
	while (j < map->texture_size)
	{
		if (texture->texture_columns[j])
			free(texture->texture_columns[j]);
		else
			break ;
		j++;
	}
	free(texture->texture_columns);
}
