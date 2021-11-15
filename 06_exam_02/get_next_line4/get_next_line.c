#include "get_next_line.h"
#include <stdio.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_find_nl(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	if (line[i] == '\0')
		return (-1);
	return (i);
}

char	*ft_strjoin(char *line, char buf)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(ft_strlen(line) + 1 + 1);
	while (line[i] != '\0')
	{
		result[i] = line[i];
		i++;
	}
	result[i] = buf;
	result[i + 1] = '\0';
	free (line);
	return (result);
}

char	*get_next_line(int fd)
{
	int	bytes_read;
	char	buf;
	char	*line;
	if (fd <0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	line = malloc(1);
	line[0] = '\0';
	while(ft_find_nl(line) == -1)
	{
		bytes_read = read(fd, &buf, 1);
		if (bytes_read == 0)
		{
			if (line[0] == '\0')
			{
				free(line);
				return (NULL);
			}
			else
			{
				return (line);
			}
		}
		line = ft_strjoin(line, buf);
		if (buf == '\n')
			return (line);
	}
	return (line);
}
