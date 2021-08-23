#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *line;
	int i = 1;
	if (argc < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	printf("========== FILE NAME: '%s' ==========\n", argv[1]);
	printf("********** START file -> \n");
	while (1)
	{
		line = get_next_line(fd);
		printf("Line %d -->	.%s.\n", i, line);
		if (line == NULL)
		{
			free(line);
			break;
		}
		free(line);
		i++;
	}
	printf("\n<- END of file **********\n");
	free(line);
	close(fd);
	return (0);
}
