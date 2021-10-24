#include <unistd.h>
#include <stdio.h>

int	ft_check_unique(char *str, char c, int index)
{
	int i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_str(char *str, char c)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int i = 0;	
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		if (ft_check_unique(argv[1], argv[1][i], i) == 1)
		{
			if (ft_check_str(argv[2], argv[1][i]) == 1)
				write(1, &argv[1][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
