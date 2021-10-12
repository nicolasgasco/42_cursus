#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	main(int argc, char *argv[])
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	printf("Fd is %d\n", fd);
	while (1)	
	{	
		line = get_next_line(fd);
		printf("%s\n", line);
		if (line == NULL || i == 3)
			break;
		i++;
	}
	close(fd);
	return (1);	
}
