#include "get_next_line.h"
#include <stdio.h>

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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	char	*result;
	int		size;
	
	k = 0;
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(size + 1);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	while (k != ft_strlen(s1))
	{
		result[i] = s1[k];
		k++;
		i++;
	}
	k = 0;
	while (k != ft_strlen(s2))
	{
		result[i] = s2[k];
		k++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_find_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (-1);
	else
		return (1);
}

char	*get_next_line(int fd)
{
	char				*buf;
	static char	*buf_stat;
	char				*line;
	int					b_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while	(ft_find_nl(buf_stat) == -1)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read <= 0)
			break;
		buf[b_read] = '\0';
		buf_stat = ft_strjoin(buf_stat, buf);
	}
	free(buf);
	if (b_read == -1)
		return (NULL);
	// printf("Buf now is %s\n", buf);
	return (buf_stat);	
}
