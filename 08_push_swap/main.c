#include <stdio.h>
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	*nums;
	char 	**nums_arr;
	int		*result;

	i = 1;
	nums = malloc(1);
	while (i < argc)
	{
		nums = ft_strjoin(nums, argv[i]);
		nums = ft_strjoin(nums, ",");
		i++;
	}
	printf("%s\n", nums);
	i = 0;
	nums_arr = ft_split(nums, ',');
	result = (int *)malloc(sizeof(int) * (argc - 1));
	while (i < (argc - 1))
	{
		result[i] = ft_atoi(nums_arr[argc - 1 - 1 - i]);
		printf(".%d.\n", result[i]);
		i++;
	}

	system("leaks a.out");
	return (0);
}