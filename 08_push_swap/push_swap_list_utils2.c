/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:02:31 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/13 12:03:50 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_i_linked(struct s_node *list, struct s_node *ordered)
{
	struct s_node	*curr_l;
	struct s_node	*curr_o;

	curr_l = list;
	while (curr_l != NULL)
	{
		curr_o = ordered;
		while (curr_o != NULL)
		{
			if (curr_o->x == curr_l->x)
				curr_l->i = curr_o->i;
			curr_o = curr_o->next;
		}
		curr_l = curr_l->next;
	}
}

void	ft_assign_i(struct s_node *linked, int *array, int limit)
{
	struct s_node	*curr;
	int				i;

	i = 0;
	while (i < limit)
	{
		curr = linked;
		while (curr != NULL)
		{
			if (array[i] == curr->x)
				curr->i = i + 1;
			curr = curr->next;
		}
		i++;
	}
}

int	*ft_bubble_sort(int *num_arr, int limit)
{
	int	i;
	int	temp;
	int	sorted;

	while (1)
	{
		sorted = 1;
		i = 0;
		while (i < (limit - 1))
		{
			if (num_arr[i] > num_arr[i + 1])
			{
				sorted = 0;
				temp = num_arr[i];
				num_arr[i] = num_arr[i + 1];
				num_arr[i + 1] = temp;
			}
			i++;
		}
		if (sorted == 1)
			break ;
	}
	return (num_arr);
}
