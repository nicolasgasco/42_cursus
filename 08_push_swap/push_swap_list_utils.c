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

void	ft_iterate_list(struct Node *root, char c)
{
	struct Node	*curr;
	
	curr = root;
	printf("Nodes list %c: {", c);
	while (curr != NULL)
	{
		if (!curr->next)
			printf("%d", curr->x);
		else
			printf("%d, ", curr->x);
		curr = curr->next;
	}
	printf("}\n");
}

void	ft_insert_end(struct Node **root, int value)
{
	struct Node	*new_node;
	struct Node	*curr;

	new_node = malloc(sizeof(struct Node));
	if (new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->x = value;
	if (*root == NULL)
	{
		*root = new_node;
	}
	curr = *root;
	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;
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
	num_list->a_arr = ft_populate_nodes(num_arr, num_list->num_tot);
	ft_iterate_list(num_list->a_arr, 'a');
	num_list->b_arr = ft_populate_nodes(NULL, 0);
	ft_iterate_list(num_list->b_arr, 'b');
	free(num_arr);
	return;
}
