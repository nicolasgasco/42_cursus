#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void	ft_putchar(char c, int *counter)
{	
	counter += write(1, &c, 1);
}

void	ft_putstr(char *str, int *counter)
{
	int	i; 
	
	i = 0;
	while (str[i] != '\0')
	{
		*counter += write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(long n, int *counter)
{
	int	result;

	if (n < INT_MIN || n > INT_MAX)
		return ;
	if (n < 0)
	{
		*counter += write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		result = n + '0';
		*counter += write(1, &result, 1); 
	}
	else
	{
		result = (n % 10) + '0';
		ft_putnbr(n / 10, counter);
		*counter += write(1, &result, 1);	
	}
}

void	ft_puthex(long n, int *counter)
{
	char	*alpha = "abcedf";
	char	result;
	
	if (n < 0)
	{
		*counter += write(1, "-", 1);
		n *= -1;
	}
	if (n < 16)
	{
		if (n <= 9)
		{
			result = n + '0';
			*counter += write(1, &result, 1);
		}
		else
		{
			result = alpha[n - 9 - 1];
			*counter += write(1, &result, 1);
		}
	}
	else
	{
		ft_puthex(n / 16, counter);
		if (n % 16 < 10)
		{
			result = n + '0';
			*counter += write(1, &result, 1);
		}
		else
		{
			result = alpha[(n % 16) - 9 - 1];
			*counter += write(1, &result, 1);
		}
	}
}

void	ft_flags(char c, va_list args, int *counter)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), counter);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (c == 'd')
		ft_putnbr(va_arg(args, int), counter);
	else if (c == 'x')
		ft_puthex(va_arg(args, int), counter);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	i;
	int	counter;

	va_start(args, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
				counter += write(1, "%", 1);
			else
				ft_flags(s[i + 1], args, &counter);
			i +=2;
		}
		else
		{
			counter += write(1, &s[i], 1);
			i++;
		}
	}
	va_end(args);
	return (1);
}
