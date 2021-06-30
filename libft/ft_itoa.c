#include <stdio.h>
#include "libft.h"
#include <bsd/string.h>


char	*ft_itoa(int n)
{
	int		mult;
	char	*res;
	int		counter;
	int		dummy;

	dummy = n;
	mult = 1;
	while (dummy > 1)
	{
		dummy /= 10;
		mult *= 10;
	}
	res = malloc((counter + 1) * sizeof(char));
	res = "";
	while (n > 0)
	{
		printf("N is %d\n", n%10);
		ft_strlcat("1", res, 1);
		n /= 10;
	}
	return "ciao";
}
