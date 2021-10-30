/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:43:54 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/30 18:55:19 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_move(num_list *number_list, char move, char list)
{
	ft_putchar_fd(move, 0);
	ft_putchar_fd(list, 0);
	ft_putchar_fd('\n', 0);
	number_list->num_moves += 1;
}

void	ft_ss(num_list *number_list)
{
	struct Node *root1;
	struct Node *root2;

	root1 = number_list->a_list;
	root2 = number_list->b_list;
	if (root1 == NULL || root1->next == NULL || root1->next->next == NULL)
		return;
	if (root2 == NULL || root2->next == NULL || root2->next->next == NULL)
		return;
	ft_swap_nodes(&root1, 0, 1);
	ft_swap_nodes(&root2, 0, 1);
}

void	ft_s(num_list *number_list, char c)
{
	struct Node *root;

	if (c == 's')
	{
		ft_ss(number_list);
		ft_put_move(number_list, 's', 's');
		return;
	}
	else
	{
		if (c == 'a')
			root = number_list->a_list;
		else
			root = number_list->b_list;
		if (root == NULL || root->next == NULL || root->next->next == NULL)
			return;
		ft_swap_nodes(&root, 0, 1);
		ft_put_move(number_list, 's', c);
	}
}

void	ft_p(num_list *number_list, char c)
{
	struct Node *node;

	if (c == 'a')
	{
		node = number_list->b_list;
		ft_remove_node(&number_list->b_list, 0);
		ft_insert_beginning(&number_list->a_list, node->x);
	}
	else
	{
		node = number_list->a_list;
		ft_remove_node(&number_list->a_list, 0);
		ft_insert_beginning(&number_list->b_list, node->x);
	}
	ft_put_move(number_list, 'p', c);
}

void	ft_rr(num_list *number_list)
{
	struct Node	*moved_node;
	
	if (number_list->a_list == NULL || number_list->a_list->next == NULL || number_list->a_list->next->next == NULL)
		return;
	moved_node = number_list->a_list;
	ft_remove_node(&number_list->a_list, 0);
	ft_insert_end(&number_list->a_list, moved_node->x);
	if (number_list->b_list == NULL || number_list->b_list->next == NULL || number_list->b_list->next->next == NULL)
		return;
	moved_node = number_list->b_list;
	ft_remove_node(&number_list->b_list, 0);
	ft_insert_end(&number_list->b_list, moved_node->x);
}

void	ft_r(num_list *number_list, char c)
{
	struct Node	*moved_node;

	if (c == 'r')
	{
		ft_rr(number_list);
		ft_put_move(number_list, 'r', 'r');
		return;
	}
	if (c == 'a')
	{
		if (number_list->a_list == NULL || number_list->a_list->next == NULL || number_list->a_list->next->next == NULL)
			return;
		moved_node = number_list->a_list;
		ft_remove_node(&number_list->a_list, 0);
		ft_insert_end(&number_list->a_list, moved_node->x);
	}
	else
	{
		if (number_list->b_list == NULL || number_list->b_list->next == NULL || number_list->b_list->next->next == NULL)
			return;
		moved_node = number_list->b_list;
		ft_remove_node(&number_list->b_list, 0);
		ft_insert_end(&number_list->b_list, moved_node->x);
	}
	ft_put_move(number_list, 'r', c);
}