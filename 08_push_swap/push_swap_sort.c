/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:06:52 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/13 12:07:07 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list *n_list)
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

void	ft_sort_two(t_list *n_list)
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
