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

void	ft_readline_char_map(int fd, char *line, t_tdata *texture)
{
	int	i;

	i = 0;
	texture->texture_columns = (int **)malloc(sizeof(sizeof(int)
				* texture->texture_w) * texture->texture_h);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (i < texture->texture_h)
			ft_fill_int_matrix_line(texture, line, i);
		i++;
		free(line);
	}
}

void	ft_fill_int_matrix_line(t_tdata *texture, char *line, int y)
{
	int				i;
	struct s_cinfo	*curr;
	int				*matrix_line;

	i = 1;
	matrix_line = (int *)malloc(sizeof(int) * texture->texture_w);
	while (line[i] != '\0' && line[i] != '\"')
	{
		curr = texture->col_info_list;
		while (curr)
		{
			if (curr->col_char == line[i])
			{
				matrix_line[i - 1] = curr->col_int;
				break ;
			}
			if (curr->next)
				curr = curr->next;
			else
				break ;
		}
		i++;
	}
	texture->texture_columns[y] = matrix_line;
}
