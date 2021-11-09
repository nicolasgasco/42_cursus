#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putint(long n, int *counter)
{
	char result;
	if (n < 0)
	{
		*counter += write(1, "-", 1);
		n *= -1;
	}
	if (n <= 9)
	{
		result = n + '0';
		*counter += write(1, &result, 1);
	}
	else
	{
		result = n % 10 + '0';
		ft_putint(n / 10, counter);
		*counter += write(1, &result, 1);
	
	}		
}

void	ft_puthex(long hex, int *counter)
{
	char	*alpha;


	alpha = "abcdef";
	if ((hex / 16) == 0)
	{
		if ((hex % 16) < 10)
			ft_putint((long)(hex % 16), counter);
		else
			*counter += write(1, &alpha[hex % 16 - 10], 1);
		return ;
	}
	ft_puthex(hex / 16, counter);
	if (hex % 16 < 10)
		ft_putint((long)(hex % 16), counter);
	else
		*counter += write(1, &alpha[hex % 16 - 10], 1);
}

void	ft_putstr(char *s, int *counter)
{
	int	i;

	i = 0;
	if (!s)
	{
		*counter += write(1, "(null)", 6);
		return;
	}
	while (s[i] != '\0')
	{
		*counter += write(1, &s[i], 1);
		i++;
	}
}

void	ft_putchar(char c, int *counter)
{	
	*counter += write(1, &c, 1);
}

void	ft_flags(va_list args, char flag, int	*counter)
{
	if (flag == 'c')
		ft_putchar(va_arg(args, int), counter);
	else if (flag == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (flag == 'd')
		ft_putint(va_arg(args, int), counter);
	else if (flag == 'x')
		ft_puthex(va_arg(args, int), counter);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int			i;
	int			counter;

	va_start(args, s);
	i = 0;
	counter = 0;
	while(s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if(s[i + 1] == '%')
			{
				counter += write(1, &s[i], 1);
				i += 2;
			}
			else
			{
				ft_flags(args, s[i + 1], &counter);
				i += 2;
			}
		}
		else
		{
			counter += write(1, &s[i], 1);
			i++;
		}
	}
	va_end(args);
	return (counter);
}
