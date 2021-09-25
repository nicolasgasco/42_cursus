#include "so_long.h"

void    ft_strcpy(char **dst, const char *src)
{
	unsigned int	i;

	i = 0;
	if (!src)
		return ;
	while (src[i] != '\0')
    {
        **dst = src[i];
        **dst++;
		i++;
    }
	*(dst + i) = '\0';
	return ;
}
