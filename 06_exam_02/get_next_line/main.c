#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	main(int argc, char *argv[])
{
	char	*line;
	int		fd;

	fd = open("gnlTester/files/41_with_nl", O_RDONLY);
	while (1)	
	{	
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break;
		}
		free(line);
	}
	close(fd);
	return (1);	
}
