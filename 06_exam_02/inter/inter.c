#include <unistd.h>

int	ft_check_if_present(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_unique(int pos, char *str)
{
	int	i;

	i = 0;
	while (i != pos)
	{
		if (str[i] == str[pos])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	i;
	
	i = 0;
	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		while (argv[1][i] != '\0')
		{
			if (ft_check_unique(i, argv[1]))
			{
				if (ft_check_if_present(argv[1][i], argv[2]) == 1)
					write(1, &argv[1][i], 1);
			}
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
