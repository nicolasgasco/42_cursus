#include <stdio.h>
#include "libft.h"
#include <bsd/string.h>

static int	ft_cal_number_digits(int n)
{
	int	res;

	res = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	else if (n == 0)
		return 1;
	while (n > 0)
	{
		res++;
		n /= 10;
	}
	return res;
}

char	*ft_itoa(int n)
{
	char	*res;
	int		num_digits;
	int		j;

	num_digits = ft_cal_number_digits(n);
	res = malloc((num_digits + 1) * sizeof(char));
	if (n == -2147483648)
	{
		res = "-2147483648";
		return (res) ;
	}
	if (res == NULL)
		return (NULL);
	j = num_digits - 1;
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	do
	{
		res[j] = (n % 10) + '0';
		n = n / 10;
		j--;
	}
	while (j >= 0 && n > 0);
	res[num_digits] = '\0';
	return res;
}
