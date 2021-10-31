/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:56:10 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/31 18:05:02 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r_aux(struct s_node **root, char list, t_list *t_list)
{
	int	moved_node;

	if (root == NULL)
		return ;
	if ((*root)->next == NULL || (*root)->next->next == NULL)
		return ;
	moved_node = (*root)->x;
	ft_remove_node(root, 0);
	ft_insert_end(root, moved_node);
	ft_put_move(t_list, 'r', list);
}

void	ft_r(t_list *t_list, char c)
{
	if (c == 'r')
	{
		ft_r_aux(&t_list->a_list, 'a', t_list);
		ft_r_aux(&t_list->b_list, 'b', t_list);
		return ;
	}
	if (c == 'a')
		ft_r_aux(&t_list->a_list, 'a', t_list);
	else
		ft_r_aux(&t_list->b_list, 'b', t_list);
}

void	ft_rr_aux(struct s_node *root, char list, t_list *t_list)
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
	ft_remove_node(&t_list->a_list, i);
	ft_insert_beginning(&t_list->a_list, moved_node);
	ft_put_move(t_list, 'R', list);
}

void	ft_rr(t_list *t_list, char c)
{
	if (c == 'r')
	{
		ft_rr_aux(t_list->a_list, 'a', t_list);
		ft_rr_aux(t_list->b_list, 'b', t_list);
		return ;
	}
	if (c == 'a')
		ft_rr_aux(t_list->a_list, 'a', t_list);
	else
		ft_rr_aux(t_list->b_list, 'b', t_list);
}
