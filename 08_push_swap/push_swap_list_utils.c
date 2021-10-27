#include "push_swap.h"
#include <stdio.h>

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

void	ft_insert_end(node **root, int value)
{
	node	*new_node;
	node	*curr;

	new_node = malloc(sizeof(node));
	if (new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->x = value;
	curr = *root;
	while(curr->next != NULL)
	{

	}
}

void	ft_populate_nodes(int *num_arr, int n)
{
	node	root;

	root.x = num_arr[0];
	root.next = malloc(sizeof(node));
	if (root.next == NULL)
		exit(1);
	root.next = NULL;
	free(root.next);
}

int *ft_create_num_arr(int argc, char *argv[])
{
	char	**str_arr;
	int		*result;
	int		i;

	i = 1;
	result = (int *)malloc(sizeof(int) * (argc - 1));
	if (result == NULL)
		exit(1);
	while (i < argc)
	{
		result[argc - 1 - i] = ft_atoi(argv[i]);
		i++;
	}
	return (result);
}

void	ft_create_linked_list(int argc, char **args, num_list *num_list)
{
	int		*num_arr;	

	num_arr = ft_create_num_arr(argc, args);
	ft_print_int_array(num_arr, argc - 1);
	num_list->num_tot = argc - 1;
	// ft_populate_nodes(num_arr, num_list->num_tot);
	free(num_arr);
	return;
}
