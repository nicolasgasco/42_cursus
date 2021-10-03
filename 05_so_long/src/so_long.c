/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:07:24 by ngasco            #+#    #+#             */
/*   Updated: 2021/09/28 20:34:07 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_validate_filename(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '.' && file[i] != '\0')
		i++;
	if (file[i] == '\0')
		return (-1);
	if (file[i + 1] == 'b' && file[i + 2] == 'e' && file[i + 3] == 'r' && file[i + 4] == '\0')
		return (0);
	return (-1);
}

int	ft_check_file_extension(char *file)
{
	if (ft_validate_filename(file) == -1)
	{
		ft_put_str("Error\n");
		ft_put_str("Provide a .ber file.\n");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		file_size;
	t_map	map;

	file_size = 0;
	if (argc < 2)
	{
		ft_put_str("Error\n");
		ft_put_str("Please provide a map.\n");
		return (-1);
	}
	if (argc > 2)
	{
		ft_put_str("Error\n");
		ft_put_str("Please provide only one map.\n");
		return (-1);
	}
	if (argc == 2)
	{
		if (ft_check_file_extension(argv[1]) == -1)
			return (-1);
		ft_open_for_validation(argv[1], &file_size);
		map.map = ft_create_bi_array(argv[1], file_size, &map);
		ft_render_map(&map);
		free(map.map);
	}
	return (1);
}
