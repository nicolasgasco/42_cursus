/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:07:34 by ngasco            #+#    #+#             */
/*   Updated: 2021/09/25 11:51:36 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_var_counter(char line_c, int *e_count, int *c_count, int *p_count)
{
	if (line_c == 'E')
		*e_count += 1;
	else if (line_c == 'C')
		*c_count += 1;
	else if (line_c == 'P')
		*p_count += 1;
}

void	ft_check_min_chars(char *line)
{
	static int	e_count;
	static int	c_count;
	static int	p_count;
	int			i;

	if (!e_count)
		e_count = 0;
	if (!c_count)
		c_count = 0;
	if (!p_count)
		p_count = 0;
	if (line[0] == '\0' && (e_count == 0 || c_count == 0 || p_count == 0))
	{
		if (e_count == 0)
			perror("Map error (exit missing)");
		if (p_count == 0)
			perror("Map error (player missing)");
		if (c_count == 0)
			perror("Map error (collectible missing)");
		exit(0);
	}
	i = 0;
	while (line[i] != '\0')
	{	
		ft_var_counter(line[i], &e_count, &c_count, &p_count);
		i++;
	}
}

void	ft_validate_map(int file)
{
	char	*line;
	char	*previous_line;

	previous_line = NULL;
	while (1)
	{
		line = ft_get_next_line(file, 1);
		if (line == NULL)
		{
			ft_check_min_chars("");
			break ;
		}
		if (!previous_line)
			ft_check_horizontal_border(line);
		else
			ft_check_middle_line(line);
		ft_check_map_length(line);
		ft_check_min_chars(line);
		ft_check_foreign_chars(line);
		previous_line = line;
	}
	ft_check_horizontal_border(previous_line);
	printf("Map is legit.\n");
}
