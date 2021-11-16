#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str, int *counter)
{
	//int	i; 
	
	printf("Str is %s\n", str);
	//i = 0;
	//while (str[i] != '\0')
	//{
		// *counter += write(1, &str[i], 1);
	//	i++;
	//}
}

void	ft_flags(char c, va_list args, int *counter)
{
	if (c == 'c')
		counter += write(1, &c, 1);
	else if (c == 's')
	{
		ft_putstr(va_arg(args, char *), counter);
	}
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
			i += 2;
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
