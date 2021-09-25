/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:07:24 by ngasco            #+#    #+#             */
/*   Updated: 2021/09/25 12:32:05 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_create_bi_array(char *file, int size)
{
	int		fp;
	char	**result;
	char	*line;
	int		i;

	i = 0;
	fp = open(file, O_RDONLY);
	if (fp == -1)
	{
		perror("An error ocurred while reading the file");
		exit(0);
	}
	else
	{
		printf("File opened. Fd is %d.\n", fp);
		result = malloc(size);
		while (1)
		{
			line = ft_get_next_line(fp, 1);
			if (line == NULL)
				break ;
			result[i] = line;
			free(line);
			i++;
		}
		result[i] = NULL;
		if (close(fp) == 0)
		{
			printf("File closed successfully.\n");
			return (result);
		}
		else
		{
			free(result);
			perror("Error while closing file");
			exit(0);
		}
	}
}

int	main(int argc, char **argv)
{
	int		file_size;
	char	**map;

	file_size = 0;
	if (argc < 2)
	{
		perror("Not enough arguments");
		return (-1);
	}
	if (argc > 2)
	{
		perror("Too many arguments");
		return (-1);
	}
	if (argc == 2)
	{
		printf("File is: '%s'\n", argv[1]);
		ft_open_for_validation(argv[1], &file_size);
		map = ft_create_bi_array(argv[1], file_size);
		printf("File is %s\n", map[0]);
		free(map);
	}
	return (1);
}