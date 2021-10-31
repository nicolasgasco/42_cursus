/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:56:10 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/31 18:01:36 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r_aux(struct Node **root, char list, num_list *num_list)
{
	int	moved_node;

	if (root == NULL)
		return ;
	if ((*root)->next == NULL || (*root)->next->next == NULL)
		return ;
	moved_node = (*root)->x;
	ft_remove_node(root, 0);
	ft_insert_end(root, moved_node);
	ft_put_move(num_list, 'r', list);
}

void	ft_r(num_list *num_list, char c)
{
	if (c == 'r')
	{
		ft_r_aux(&num_list->a_list, 'a', num_list);
		ft_r_aux(&num_list->b_list, 'b', num_list);
		return ;
	}
	if (c == 'a')
		ft_r_aux(&num_list->a_list, 'a', num_list);
	else
		ft_r_aux(&num_list->b_list, 'b', num_list);
}

void	ft_rr_aux(struct Node *root, char list, num_list *num_list)
{
	int	moved_node;
	int	i;

	i = 0;
	while (root->next != NULL)
	{
		i++;
		root = root->next;
	}
	moved_node = root->x;
	ft_remove_node(&num_list->a_list, i);
	ft_insert_beginning(&num_list->a_list, moved_node);
	ft_put_move(num_list, 'R', list);
}

void	ft_rr(num_list *num_list, char c)
{
	if (c == 'r')
	{
		ft_rr_aux(num_list->a_list, 'a', num_list);
		ft_rr_aux(num_list->b_list, 'b', num_list);
		return ;
	}
	if (c == 'a')
		ft_rr_aux(num_list->a_list, 'a', num_list);
	else
		ft_rr_aux(num_list->b_list, 'b', num_list);
}
