#include "push_swap.h"
#include <stdio.h>

char *ft_create_num_str(int argc, char *argv[])
{
	int		i;
	char	*res;

	i = 1;
	res = malloc(1);
	if (!res)
		free(res);
	while (i < argc)
	{
		res = ft_strjoin(res, argv[i]);
		res = ft_strjoin(res, ",");
		i++;
	}
	return (res);
}

void	ft_create_linked_list(int argc, char **args)
{
	char *num_str;

	num_str = ft_create_num_str(argc, args);
	printf("Num_str is '%s'\n", num_str);
	free(num_str);
	return;
}

	// i = 0;
	// nums_arr = ft_split(nums, ',');
	// result = (int *)malloc(sizeof(int) * (argc - 1));