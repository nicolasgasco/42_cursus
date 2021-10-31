/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discarted_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:59:23 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/31 18:00:25 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insert_after(struct Node *Node, int value)
{
	struct Node	*new_node;

	new_node = malloc(sizeof(struct Node));
	if (new_node == NULL)
		exit(1);
	new_node->x = value;
	new_node->next = Node->next;
	Node->next = new_node;
}

void	ft_print_struct(num_list *number_list)
{
	printf("\n");
	ft_iterate_list(number_list->a_list, 'a');
	ft_iterate_list(number_list->b_list, 'b');
	printf("Num tot is %d\n", number_list->num_tot);
	printf("Num moves is %d\n", number_list->num_moves);
	printf("\n");
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

void	ft_print_int_array(int *arr, int n)
{
	int	i;

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
