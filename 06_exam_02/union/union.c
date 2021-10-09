#include <unistd.h>

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

int	ft_check_first_str(char c, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	if (count > 0)
		return (0);
	else
		return (1);
}

int main(int argc, char **argv)
{
	int		i;
	
	i = 0;
	if (argc != 3)
		write(1, "\n", 1);	
	else
	{
		while(argv[1][i] != '\0')
		{
			if (ft_check_unique(i, argv[1]) == 1)
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while(argv[2][i] != '\0')
		{
			if (ft_check_unique(i, argv[2]) == 1)
			{
				if (ft_check_first_str(argv[2][i], argv[1]) == 1)
						write(1, &argv[2][i], 1);
			}
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
