#include "get_next_line.h"

int	ft_find_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_calc_line(char *line, char buf)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(ft_strlen(line) + 1 + 1);
	while (line[i] != '\0')
	{
		res[i] = line[i];
		i++;
	}
	res[i] = buf;
	i++;
	res[i] = '\0';
	free(line);
	return (res);
}

char	*get_next_line(int fd)
{
	char	buf;
	int		bytes_read;
	char	*line;
		

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	line = malloc(1);
	line[0] = '\0';
	while(ft_find_nl(line) == -1 && bytes_read != 0)
	{	
		bytes_read = read(fd, &buf, 1);
		if (bytes_read <= 0)
		{
			if (line[0] == '\0')
			{
				free(line);
				return (NULL);
			}
			return (line);
		}
		else if (bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
		line = ft_calc_line(line, buf);
	}
	return (line);
}
