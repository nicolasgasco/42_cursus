/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:10:12 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/16 19:14:30 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_choose_direction_util(t_list *n_list, int *i)
{
	ft_move(n_list, 'R', 'a');
	*i += 1;
}

void	ft_choose_direction(t_list *n_list, struct s_node *list, int value)
{
	struct s_node	*curr;
	int				i;

	curr = list;
	i = 0;
	while (curr->x != value)
	{
		i++;
		curr = curr->next;
	}
	curr = list;
	if (i >= (n_list->a_len / 2))
	{
		while (i < n_list->a_len)
			ft_choose_direction_util(n_list, &i);
	}
	else
	{
		while (i > 0)
		{
			ft_move(n_list, 'r', 'a');
			i--;
		}
	}
}

void	ft_sort_six(t_list *n_list)
{
	ft_choose_direction(n_list, n_list->a_list, n_list->hi_a);
	ft_move(n_list, 'p', 'b');
	ft_choose_direction(n_list, n_list->a_list, n_list->lo_a);
	ft_move(n_list, 'p', 'b');
	ft_sort_four(n_list);
	ft_move(n_list, 'p', 'a');
	ft_move(n_list, 'p', 'a');
	ft_move(n_list, 'r', 'a');
}

void	ft_sort_seven(t_list *n_list)
{
	ft_choose_direction(n_list, n_list->a_list, n_list->hi_a);
	ft_move(n_list, 'p', 'b');
	ft_choose_direction(n_list, n_list->a_list, n_list->lo_a);
	ft_move(n_list, 'p', 'b');
	ft_sort_five(n_list);
	ft_move(n_list, 'p', 'a');
	ft_move(n_list, 'p', 'a');
	ft_move(n_list, 'r', 'a');
}
