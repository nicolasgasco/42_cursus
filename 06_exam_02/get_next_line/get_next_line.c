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
	free(s1);
	return (result);
}

int	ft_find_nl(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (-1);
	else
		return (i);
}

char	*ft_substr(char *s)
{
	int		i;
	char	*result;

	i = 0;
	if (!s)
		return(NULL);
	if (ft_strlen(s) == 1)
	{
		result = malloc(2);
		result[0] = '\n';
		result[1] = '\0';
		return (result);
	}
result = malloc((ft_find_nl(s) + 1) + 1);
	while (i != (ft_find_nl(s) + 1))
	{
			result[i] = s[i];
			i++;
	}
	result[i] = '\0';
	return (result);
}

char *ft_trim(char *s)
{
	char *result;
	int		i;
	int		k;

	i = 0;
	k = ft_find_nl(s) + 1;
	result = malloc(ft_strlen(s) - ft_find_nl(s) -1 + 1);
	while (s[k] != '\0')
	{
		result[i] = s[k];
		i++;
		k++;
	}
	result[i] = '\0';
	free(s);
	return (result);
}

char *ft_strdup(char *s1)
{
	int		i;
	char	*result;
	
	if (!s1)
		return (NULL);
	result = malloc(ft_strlen(s1) + 1);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_calc_line(char *buf_static)
{
	char	*result;
	int		index;
	
	if (!buf_static)
		return (NULL);
	index = ft_find_nl(buf_static);
	if (index == -1 || buf_static[0] == '\n')
	{
		result = ft_strdup(buf_static);
		return (result);
	}
	else
	{
		result = ft_substr(buf_static);
		return (result);
	}
}

char	*ft_calc_buf(char *buf_static)
{
	char	*result;
	int		index;

	index = ft_find_nl(buf_static);
	if (index == -1)
	{
		free(buf_static);
		return (NULL);
	}
	result = ft_trim(buf_static);
	return (result);
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
	line = ft_calc_line(buf_stat);
	buf_stat = ft_calc_buf(buf_stat);
	return (line);	
}
