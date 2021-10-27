#include <stdio.h>
#include "get_next_line.h"
int	ft_strlen(char *str)
{
	int	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
char	*ft_join(char *s1, char *s2)
{
	int	i = 0;
	char	*res;

	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);	
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		res[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	res[ft_strlen(s1) + i] = '\0';
	free((char *)s1);
	return (res);
}

int	ft_find_nl(char *str)
{
	int i = 0;

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

char 	*ft_strdup(char *str)
{
	int i = 0;
	char *res;

	res = malloc(ft_strlen(str) + 1);
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);

}

char *ft_substr(char *s, int start, int end)
{
	int i = 0;
	char *res;

	res = malloc(end - start + 1);
	while (start < end)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_calc_line(char *str)
{
	char *line;
	int	index;

	if (ft_strlen(str) == 0)
		return (NULL);
	index = ft_find_nl(str);
	// printf("Index is %d\n", index);
	if (index == -1)
	{
		line = ft_strdup(str);
		// printf("LineX is .%s.\n", line);
		return (line);
	}
	line = ft_substr(str, 0, index + 1);
	return (line);
}

char *ft_substr_buf(char *str, int start)
{
	char *res;
	int i = 0;

	if (ft_strlen(str) == 0)
	{
		return (NULL);
	}
	res = malloc(ft_strlen(str) - start + 1);
	while (str[start] != '\0')
	{
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_calc_buf(char *str)
{
	char *res;
	if (!str)
		return (NULL);
	int index = ft_find_nl(str);
	if (index == -1)
	{
		free(str);
		return (NULL);
	}
	res = ft_substr_buf(str, index + 1);
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	char				*line;
	char				*buf;
	static char	*buf_stat;
	int					b_read;
	
	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	buf[0] = '\0';
	if (!buf_stat)
	{
		buf_stat = malloc(1);
		buf_stat[0] = '\0';
	}
	b_read = 1;
	while(ft_find_nl(buf) == -1)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read <= 0)
			break;	
		buf[b_read] = '\0';
		buf_stat = ft_join(buf_stat, buf);
		// printf("BUf is .%s.\n", buf);
		// printf("Buf_static is .%s.\n", buf_stat);
	}
	free(buf);
	if (b_read == -1)
		return (NULL);
	line = ft_calc_line(buf_stat);
	// printf("Line is .%s.\n", line);
	buf_stat = ft_calc_buf(buf_stat);
	return (line);
}
