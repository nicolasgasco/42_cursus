/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 11:27:07 by ngasco            #+#    #+#             */
/*   Updated: 2021/09/25 11:30:58 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_line_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	ft_check_middle_line(char *line)
{
	if (line[0] != '1' || line[ft_map_line_length(line) - 1] != '1')
	{
		perror("Map error (breach in the side walls)");
		exit(0);
	}
}

void	ft_check_horizontal_border(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			perror("Map error (breach in the top walls)");
			exit(0);
		}
		i++;
	}
}

void	ft_check_foreign_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'E'
			&& line[i] != 'C' && line[i] != 'P' && line[i] != '\n')
		{
			perror("Map error (foreign character)");
			exit(0);
		}
		i++;
	}
}

void	ft_check_map_length(char *line)
{
	static int	line_lenght;

	if (!line_lenght)
		line_lenght = ft_map_line_length(line);
	else
	{
		if (ft_map_line_length(line) != line_lenght)
		{
			perror("Map error (not rectangular)");
			exit(0);
		}
	}
}
