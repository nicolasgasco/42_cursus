#include "philo.h"

void	ft_putstr(int fd, char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int i;
	unsigned long result;
	int negative;

	i = 0;
	result = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)result * negative);
}

void	ft_putnbr(long n)
{
	int	result;

	if (n < INT_MIN || n > INT_MAX)
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		result = n + '0';
		write(1, &result, 1); 
	}
	else
	{
		result = (n % 10) + '0';
		ft_putnbr(n / 10);
		write(1, &result, 1);	
	}
}