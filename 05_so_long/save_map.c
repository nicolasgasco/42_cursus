#include "so_long.h"

int	ft_open_file(char *file)
{
	int	fp;

	fp = open(file, O_RDONLY);
	if (fp == -1)
	{
		perror("An error ocurred while reading the file");
		exit(0);
	}
	return (fp);
}

char	**ft_close_file(int fp, char **result[])
{
	if (close(fp) == 0)
	{
		// printf("File closed successfully\n");
		return (*result);
	}
	else
	{
		free(*result);
		perror("Error while closing file");
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
	// printf("File opened. Fd is %d.\n", fp);
	result = malloc(size);
	while (1)
	{
		line = ft_get_next_line(fp, 1);
		if (line == NULL)
			break ;
		result[i] = line;
		map->n_rows = i + 1;
		map->n_cols = ft_map_line_length(line);
		free(line);
		i++;
	}
	result[i] = NULL;
	return (ft_close_file(fp, &result));
}