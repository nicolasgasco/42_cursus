#include "push_swap.h"
#include <stdio.h>

int *ft_create_num_arr(char **num_str, int argc)
{
	char	**str_arr;
	int		*result;
	int		i;

	i = 0;
	result = (int *)malloc(sizeof(int) * (argc - 1));
	if (!result)
	{	
		free(result);
		return (NULL);
	}
	while (i < (argc - 1))
	{
		result[i] = ft_atoi(num_str[(argc - 1) - 1 - i]);
		i++;
	}
	return (result);
}

void	ft_create_nodes(int *num_arr, int n)
{
	int		i;
	node	*root;

	root.x = num_arr[0];
	// i = i;
	// while (i < num_list->num_tot)
	// {
	// 	root.next = malloc(sizeof(node));

	// 	i++;
	// }
}

char **ft_create_str_arr(int argc, char *argv[])
{
	int		i;
	char	*res;

	i = 1;
	res = "";
	if (!res)
		free(res);
	while (i < argc)
	{
		res = ft_strjoin(res, argv[i]);
		res = ft_strjoin(res, ",");
		i++;
	}
	return (ft_split(res, ','));
}

void	ft_print_int_array(int *arr, int n)
{
	int i;
	i = 0;
	printf("Int array: [");
	while (i < n)
	{
		if (i == (n - 1))
			printf("%d", arr[i]);
		else
			printf("%d, ", arr[i]);
		i++;
	}
	printf("]\n");
}

void	ft_print_str_array(char **arr, int n)
{
	int i;
	i = 0;
	printf("String array: [");
	while (i < n)
	{
		if (i == (n - 1))
			printf("%s", arr[i]);
		else
			printf("%s, ", arr[i]);
		i++;
	}
	printf("]\n");
}

void	ft_create_linked_list(int argc, char **args, num_list *num_list)
{
	char	**str_arr;
	int		*num_arr;	

	str_arr = ft_create_str_arr(argc, args);
	num_arr = ft_create_num_arr(str_arr, argc);
	// ft_print_str_array(str_arr, argc - 1);
	ft_print_int_array(num_arr, argc - 1);
	num_list->num_tot = argc - 1;
	ft_populate_nodes(num_list, num_arr);
	free(str_arr);
	free(num_arr);
	return;
}

	// i = 0;
