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

struct Node	*ft_populate_nodes(int *num_arr, int n)
{
	struct Node	*root;
	int		i;

	if (!num_arr)
		return (NULL);
	root = malloc(sizeof(struct Node));
	root->x = num_arr[0];
	i = 1;
	while (i < n)
	{
		ft_insert_end(&root, num_arr[i]);
		i++;
	}
	free(num_arr);
	return (root);
}

int *ft_create_num_arr(int argc, char *argv[])
{
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
	num_list->a_list = ft_populate_nodes(num_arr, num_list->num_tot);
	ft_iterate_list(num_list->a_list, 'a');
	printf("Adding 10 at the beginning\n");
	ft_insert_beginning(&num_list->a_list, 10);
	ft_iterate_list(num_list->a_list, 'a');
	printf("Inserting 1234 after double next\n");
	ft_insert_after(num_list->a_list->next->next, 1234);
	ft_iterate_list(num_list->a_list, 'a');
	printf("Removing new value\n");
	ft_remove_node(&num_list->a_list, 1234);
	ft_iterate_list(num_list->a_list, 'a');
	printf("Swapping index 0 and 1\n");
	ft_swap_nodes(&num_list->a_list, 4, 5);
	ft_iterate_list(num_list->a_list, 'a');
	num_list->b_list = ft_populate_nodes(NULL, 0);
	ft_iterate_list(num_list->b_list, 'b');
	ft_deallocate_list(&num_list->b_list);
	ft_deallocate_list(&num_list->a_list);
	return;
}
