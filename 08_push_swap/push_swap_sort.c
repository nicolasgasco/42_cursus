/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:06:52 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/13 14:05:26 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_three(t_list *n_list)
{
	// Smallest is on top
	if (n_list->a_list->x == n_list->lo_tot)
	{
		printf("Smallest is on top\n\n");
		ft_move(n_list, 'R', 'a');
		ft_move(n_list, 's', 'a');
	}
	// Smallest is at bottom
	if (ft_get_value(n_list->a_list, n_list->a_len - 1) == n_list->lo_tot)
	{
		printf("Smallest is at the bottom\n");
		// Biggest is on top
		if (n_list->a_list->x == n_list->hi_tot)
		{
			printf("Biggest is on top\n");
			ft_move(n_list, 'r', 'a');
			ft_move(n_list, 's', 'a');
		}
		else
		{
			// Biggest is not on top
			printf("Biggest is in the middle\n");
			ft_move(n_list, 'R', 'a');
		}
	}
}

void ft_sort_two(t_list *n_list)
{
	// Biggest is on top
	if (n_list->a_list->x == n_list->hi_tot)
	{
		printf("Biggest is on top\n");
		ft_move(n_list, 's', 'a');
	}
	else
	{
		printf("It's already sorted\n");
	}
}

void ft_radix_sort(t_list *n_list)
{
	struct s_node	*curr_a;
	struct s_node	*curr_b;
	int 			i;
	int				comp;
	int				y;

	y = 0;
	comp = 1;
	while (1)
	{
		curr_a = n_list->a_list;
		ft_iterate_list(curr_a, 'a');
		// ft_put_bin_list(n_list->a_list);
		if (y == 2)
			break ;
		while (curr_a != NULL)
		{
			i = curr_a->i;
			curr_a = curr_a->next;
			printf("\n");
			if ((i & comp) != comp)
			{
				// printf("Comp is %d\n", comp);
				// printf("Comp & i is %d\n", comp & i);	
				// printf("%d is 1\n", i);
				ft_move(n_list, 'r', 'a');
			}
			else
			{
				// printf("%d is 0\n", i);
				ft_move(n_list, 'p', 'b');
			}
			printf("\n");
		}
		// break ;
		curr_b = n_list->b_list;
		while (curr_b != NULL)
		{
			ft_move(n_list, 'p', 'a');
			curr_b = curr_b->next;
		}
		ft_iterate_list(n_list->b_list, 'b');

		comp = comp << 1;
		y++;
		// printf("Sorted: %d\n", ft_check_if_sorted(n_list->a_list, n_list->num_tot));
		// if (ft_check_if_sorted(n_list->a_list, n_list->num_tot) == 1)
		printf("Comp is %d\n", comp);
		printf("_______________\n");

	}
}