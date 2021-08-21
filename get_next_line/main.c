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
	line= (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (argc < 2)
		printf("File name missing.\n");
	else if (argc > 2)
		printf("Too many arguments.\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			// printf("Error, cannot open file\n");
			return (1);
		}
		// printf("========== FILE NAME: '%s' ==========\n", argv[1]);
		printf("********** START file -> \n");
		while (line != NULL)
			{
			line = get_next_line(fd);
			printf("Line %d -->	.%s.\n", i, line);
			i++;
			free(line);
		}
		printf("\n<- END of file **********\n");
		close(fd);
	}
	return (0);
}