#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*line;
	int		fd;

	fd = open("gnlTester/files/multiple_nlx5", O_RDONLY);
	while (1)	
	{	
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break;
		}
		printf(".%s.\n", line);
		free(line);
	}
	close(fd);
	return (1);	
}
