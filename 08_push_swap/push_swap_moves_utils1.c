/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_utils1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:43:54 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/31 18:05:02 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_move(t_list *number_list, char move, char list)
{
	if (move == 'R')
		ft_putstr_fd("rr", 1);
	else
		ft_putchar_fd(move, 1);
	ft_putchar_fd(list, 1);
	ft_putchar_fd('\n', 1);
	number_list->num_moves += 1;
}

void	ft_ss(t_list *number_list)
{
	struct s_node	*root1;
	struct s_node	*root2;

	root1 = number_list->a_list;
	root2 = number_list->b_list;
	if (root1 == NULL || root1->next == NULL || root1->next->next == NULL)
		return ;
	if (root2 == NULL || root2->next == NULL || root2->next->next == NULL)
		return ;
	ft_swap_nodes(&root1, 0, 1);
	ft_swap_nodes(&root2, 0, 1);
}

void	ft_s(t_list *number_list, char c)
{
	struct s_node	*root;

	if (c == 's')
	{
		ft_ss(number_list);
		ft_put_move(number_list, 's', 'a');
		ft_put_move(number_list, 's', 'b');
		return ;
	}
	else
	{
		if (c == 'a')
			root = number_list->a_list;
		else
			root = number_list->b_list;
		if (root == NULL || root->next == NULL || root->next->next == NULL)
			return ;
		ft_swap_nodes(&root, 0, 1);
		ft_put_move(number_list, 's', c);
	}
}

void	ft_p(t_list *number_list, char c)
{
	int	value;

	if (c == 'a')
	{
		value = number_list->b_list->x;;
		ft_remove_node(&number_list->b_list, 0);
		ft_insert_beginning(&number_list->a_list, value);
	}
	else
	{
		value = number_list->a_list->x;
		ft_remove_node(&number_list->a_list, 0);
		ft_insert_beginning(&number_list->b_list, value);
	}
	ft_put_move(number_list, 'p', c);
}
