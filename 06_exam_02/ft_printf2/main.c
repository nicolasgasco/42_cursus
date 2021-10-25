#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

void	ft_putstr(const char *str, int *counter)
{
	int i = 0;
	
	while (str[i] != '\0')
	{
		counter += write(1, &str[i], 1);
		i++;
	}
}

void	ft_puthex(unsigned int n, int *counter)
{
	char *alpha = "abcdef";
	char result;
	
	if (n <= 15)
	{
		if (n <= 9)
		{
			result = n + '0';
			counter += write(1, &result, 1);
		}
		else
		{
			result = alpha[n - 9 - 1];
			counter += write(1, &result, 1);
		}	
	}
	else
	{
		ft_puthex(n / 16, counter);
		result = (n % 16);
		if (result <= 9)
		{
			result = result + '0';
			counter += write(1, &result, 1);
		}
		else
		{
			result = alpha[result - 9 - 1];
			counter += write(1, &result, 1);
		}
	}
}

void	ft_putnbr(long n, int *counter)
{
	char				result;

	if (n < 0)
	{
		counter += write(1, "-", 1);
		n *= -1;
	}
	if (n <= 9)
	{
		result = n + '0';
		counter += write(1, &result, 1);
	}
	else
	{
		ft_putnbr(n / 10, counter);
		result = (n % 10) + '0';
		counter += write(1, &result, 1);
	}
}

void	ft_flags(char c, va_list args, int *counter)
{
	if (c == 's')
	{
		ft_putstr(va_arg(args, const char*), counter);
	}
	else if (c == 'd')
		ft_putnbr(va_arg(args, int), counter);
	else if (c == 'x')
	{
		ft_puthex(va_arg(args, unsigned int), counter);
	}	
	
}

int	ft_printf(const char *str, ...)
{
	int 		i = 0;
	va_list	args;
	int			counter;
	
	counter = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
			{
				counter += write(1, &str[i], 1);
			}
			else if (str[i + 1] == 'c')
			{
				int result = va_arg(args, int);
				counter += write(1, &result, 1);
			}
			else
				ft_flags(str[i + 1], args, &counter);
			i += 2;
		}
		counter += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (1);
}

int	main(void)
{
	ft_printf("%x\n", 3248902348);
	return (0);
}
