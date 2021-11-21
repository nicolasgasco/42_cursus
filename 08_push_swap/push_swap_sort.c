/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:06:52 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/16 19:09:21 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_list *n_list)
{
	if (n_list->a_list->x == n_list->hi_a)
		ft_move(n_list, 's', 'a');
}

void	ft_sort_three(t_list *n_list)
{
	if (ft_check_if_sorted(n_list->a_list, n_list->a_len) == 1)
		return ;
	if (n_list->a_list->x == n_list->lo_a)
	{
		ft_move(n_list, 'R', 'a');
		ft_move(n_list, 's', 'a');
	}
	else if (ft_get_value(n_list->a_list, n_list->a_len - 1) == n_list->lo_a)
	{
		if (n_list->a_list->x == n_list->hi_a)
		{
			ft_move(n_list, 'r', 'a');
			ft_move(n_list, 's', 'a');
		}
		else
			ft_move(n_list, 'R', 'a');
	}
	else
	{
		if (n_list->a_list->x == n_list->hi_a)
			ft_move(n_list, 'r', 'a');
		else
			ft_move(n_list, 's', 'a');
	}
}

void	ft_sort_four(t_list *n_list)
{
	ft_choose_direction(n_list, n_list->a_list, n_list->hi_a);
	ft_move(n_list, 'p', 'b');
	ft_choose_direction(n_list, n_list->a_list, n_list->lo_a);
	ft_move(n_list, 'p', 'b');
	ft_sort_two(n_list);
	ft_move(n_list, 'p', 'a');
	ft_move(n_list, 'p', 'a');
	ft_move(n_list, 'r', 'a');
}

void	ft_sort_five(t_list *n_list)
{
	ft_choose_direction(n_list, n_list->a_list, n_list->hi_a);
	ft_move(n_list, 'p', 'b');
	ft_choose_direction(n_list, n_list->a_list, n_list->lo_a);
	ft_move(n_list, 'p', 'b');
	ft_sort_three(n_list);
	ft_move(n_list, 'p', 'a');
	ft_move(n_list, 'p', 'a');
	ft_move(n_list, 'r', 'a');
}

void	ft_radix_sort(t_list *n_list)
{
	struct s_node	*curr;
	int				i;
	int				x;
	int				comp;

	comp = 1;
	while (1)
	{
		curr = n_list->a_list;
		x = -1;
		while (x++ < (n_list->num_tot - 1))
		{
			i = curr->i;
			curr = curr->next;
			ft_radix_choose_direction(i, comp, n_list);
		}
		curr = n_list->b_list;
		while (curr != NULL)
		{
			curr = curr->next;
			ft_move(n_list, 'p', 'a');
		}
		comp = comp << 1;
		if (ft_check_if_sorted(n_list->a_list, n_list->num_tot) == 1)
			break ;
	}
}
