#include "so_long.h"

void	ft_put_str(char *str)
{
	int	i;
	
    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}	