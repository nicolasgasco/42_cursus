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

void	ft_putnbr(int n, unsigned int *counter)
{
	char res;

	if (n == -2147483648)
	{
		ft_putnbr(n / 10, counter);
		*counter += write(1, "8", 1);
	}
	else if (n < 0)
	{
		*counter += write(1, "-", 1);
		ft_putnbr(-n, counter);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10, counter);
		res = (n % 10) + '0';
		*counter += write(1, &res, 1);
	}
}