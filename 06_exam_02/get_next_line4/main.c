#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	int	i;
	int	fd;
	char	*line;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (0);
		else
		{
			printf("Line %d: %s\n", i + 1,  line);
		}
		i++;
	}
	return (0);
}
