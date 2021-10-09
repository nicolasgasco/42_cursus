#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

#include <stdio.h>

void	ft_put_str(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_put_int(int	n)
{
	char 					result;
	
	if (n < 0)
		write(1, "-", 1);
	if ((unsigned int)n < 9)
	{
		result = (unsigned int)n + '0';
		write(1, &result, 1);
	}
	else
	{
		result = ((unsigned int)n % 10) + '0';
		ft_put_int((unsigned int)n / 10);
		write(1, &result, 1);
	}
}

void	ft_put_hex(unsigned int n)
{
	char	result;

	if (n <= 9)
	{
		result = n + '0';
		write(1, &result, 1);
	}
	else
	{
		result = n % 16;
		ft_put_hex(n / 16);
		if (result <= 9)
		{
			result = result + '0';
			write(1, &result, 1);
		}
		else
		{
			result = ((n % 16 - 9) + '0') + 48;
			write(1, &result, 1);
		}
	}	
}

void	ft_flags(char c, va_list args)
{
	if (c == 's')
		ft_put_str(va_arg(args, const char *));
	else if (c == 'd')
	{
		ft_put_int(va_arg(args, int));
	}
	else if (c == 'x')
	{
		ft_put_hex(va_arg(args, unsigned int));
	}
}

int	ft_printf(const char *s, ...)
{
	int			i;
	va_list	args;

	i = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
				write(1, "%", 1);
			else
				ft_flags(s[i + 1], args);
			i++;
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	printf("%s\n", "toto");
	ft_printf("%s\n", "toto");
	printf("\n");
	printf("Magic %s is %d\n", "number", 42);
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("\n");
	printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("\n");
	printf("Int min is %d\n", INT_MIN);
	ft_printf("Int min is %d\n", INT_MIN);
	printf("\n");
	printf("Int max is %d\n", INT_MAX);
	ft_printf("Int max is %d\n", INT_MAX);
}
