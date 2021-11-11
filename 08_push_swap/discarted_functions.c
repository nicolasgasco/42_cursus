/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discarted_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:59:23 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/31 18:05:02 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insert_after(struct s_node *s_node, int value)
{
	struct s_node	*new_node;

	new_node = malloc(sizeof(struct s_node));
	if (new_node == NULL)
		exit(1);
	new_node->x = value;
	new_node->next = s_node->next;
	s_node->next = new_node;
}

void	ft_print_struct(t_list *number_list)
{
	static int	n_moves;

	if (!n_moves)
		n_moves = 0;
	printf("\n");
	printf("%d)_ _ _ _ _ _ _ _ _ _ _\n", n_moves);
	printf("\n");
	printf("Num tot is: %d\n", number_list->hi_tot);
	printf("Num moves is: %d\n", number_list->num_moves);
	printf("\n");
	printf("Low tot is: %d\n", number_list->lo_tot);
	printf("Hi tot is: %d\n", number_list->hi_tot);
	printf("\n");
	ft_iterate_list(number_list->a_list, 'a');
	printf("A len is: %d\n", number_list->a_len);
	printf("Low a is: %d\n", number_list->lo_a);
	printf("Hi a is: %d\n", number_list->hi_a);
	printf("\n");
	ft_iterate_list(number_list->b_list, 'b');
	printf("B len is: %d\n", number_list->b_len);
	printf("Low b is: %d\n", number_list->lo_b);
	printf("Hi b is: %d\n", number_list->hi_b);
	printf("_ _ _ _ _ _ _ _ _ _ _\n");
	printf("\n");
	n_moves++;
}

void	ft_iterate_list(struct s_node *root, char c)
{
	struct s_node	*curr;

	curr = root;
	printf("s_nodes list %c: {", c);
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
