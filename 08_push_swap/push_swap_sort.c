/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:06:52 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/13 14:15:05 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_two(t_list *n_list)
{
	if (n_list->a_list->x == n_list->hi_a)
	{
		// ft_putstr_fd("Biggest is on top\n", 0);
		ft_move(n_list, 's', 'a');
	}
	else
	{
		// ft_putstr_fd("It's already sorted\n", 0);
	}
}

void ft_sort_three(t_list *n_list)
{
	if (ft_check_if_sorted(n_list->a_list, n_list->a_len) == 1)
		return ;
	if (n_list->a_list->x == n_list->lo_a)
	{
		// ft_putstr_fd("Smallest is on top\n", 0);
		ft_move(n_list, 'R', 'a');
		ft_move(n_list, 's', 'a');
	}
	else if (ft_get_value(n_list->a_list, n_list->a_len - 1) == n_list->lo_a)
	{
		// ft_putstr_fd("Smallest is at the bottom\n", 0);
		if (n_list->a_list->x == n_list->hi_a)
		{
			// ft_putstr_fd("Biggest is on top\n", 0);
			ft_move(n_list, 'r', 'a');
			ft_move(n_list, 's', 'a');
		}
		else
		{
			// ft_putstr_fd("Biggest is in the middle\n", 0);
			ft_move(n_list, 'R', 'a');
		}
	}
	else
	{
		// ft_putstr_fd("Smallest is in the middle\n", 0);
		if (n_list->a_list->x == n_list->hi_a)
		{
			// ft_putstr_fd("Biggest is on top\n", 0);
			ft_move(n_list, 'r', 'a');
		}
		else
		{
			// ft_putstr_fd("Biggest is at bottom\n", 0);
			ft_move(n_list, 's', 'a');
		}

	}
}

void ft_sort_four(t_list *n_list)
{
	ft_choose_direction(n_list, n_list->a_list, n_list->hi_tot);
	ft_move(n_list, 'p', 'b');
	ft_choose_direction(n_list, n_list->a_list, n_list->lo_tot);
	ft_move(n_list, 'p', 'b');
	ft_sort_two(n_list);
	ft_move(n_list, 'p', 'a');
	ft_move(n_list, 'p', 'a');
	ft_move(n_list, 'r', 'a');
}

void ft_sort_five(t_list *n_list)
{
	ft_choose_direction(n_list, n_list->a_list, n_list->hi_tot);
	ft_move(n_list, 'p', 'b');
	ft_choose_direction(n_list, n_list->a_list, n_list->lo_tot);
	ft_move(n_list, 'p', 'b');
	ft_sort_three(n_list);
	ft_move(n_list, 'p', 'a');
	ft_move(n_list, 'p', 'a');
	ft_move(n_list, 'r', 'a');
}

void ft_radix_sort(t_list *n_list)
{
	struct s_node	*curr_a;
	struct s_node	*curr_b;
	int 			i;
	int				x;
	int				comp;

	comp = 1;
	// ft_iterate_list(n_list->a_list, 'a');
	// ft_iterate_list(n_list->b_list, 'b');
	while (1)
	{
		curr_a = n_list->a_list;
		// ft_put_bin_list(n_list->a_list);
		x = 0;
		while (x < n_list->num_tot)
		{
			i = curr_a->i;
			curr_a = curr_a->next;
			// printf("\n");
			// printf("I is %d\n", i);
			if ((i & comp) == comp)
			{
				// printf("Comp is %d\n", comp);
				// printf("Comp & i is %d\n", comp & i);	
				// printf("%d is 1\n", i);
				// printf("ra\n");
				ft_move(n_list, 'r', 'a');
				// ft_iterate_list(n_list->a_list, 'a');
				// ft_iterate_list(n_list->b_list, 'b');
			}
			else
			{
				// printf("%d is 0\n", i);
				// printf("pb\n");
				ft_move(n_list, 'p', 'b');
				// ft_iterate_list(n_list->a_list, 'a');
				// ft_iterate_list(n_list->b_list, 'b');
			}
			// printf("\n");
			x++;
		}
		curr_b = n_list->b_list;
		while (curr_b != NULL)
		{
			// printf("pa\n");
			curr_b = curr_b->next;
			ft_move(n_list, 'p', 'a');
			// ft_iterate_list(n_list->a_list, 'a');
			// ft_iterate_list(n_list->b_list, 'b');
			x++;
		}
		comp = comp << 1;
		// ft_iterate_list(n_list->a_list, 'a');
		// ft_iterate_list(n_list->b_list, 'b');
		// printf("Sorted: %d\n", ft_check_if_sorted(n_list->a_list, n_list->num_tot));
		if (ft_check_if_sorted(n_list->a_list, n_list->num_tot) == 1)
			break;
		// if (ft_check_if_sorted(n_list->a_list, n_list->num_tot) == 1)
		// printf("Comp is %d\n", comp);
		// printf("\n-_-_-_-_-_-\n");
		// printf("\n-_-_-_-_-_-\n");
	}
}