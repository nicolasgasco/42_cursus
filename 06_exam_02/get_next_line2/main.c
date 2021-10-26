#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int 	i = 0;
	int	fd;
	char 	*str;
		
	fd = open("file.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		if (i == 10)
			break;
		free(str);
		i++;
	}
	if (str)
		free(str);	
	return (1);

}
