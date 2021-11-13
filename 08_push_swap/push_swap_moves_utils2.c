/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:56:10 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/13 12:06:12 by ngasco           ###   ########.fr       */
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
	if (list == 'a')
	{
		ft_remove_node(&t_list->a_list, i);
		ft_insert_beginning(&t_list->a_list, moved_node);
		ft_put_move(t_list, 'R', 'a');
	}
	else
	{
		ft_remove_node(&t_list->b_list, i);
		ft_insert_beginning(&t_list->b_list, moved_node);
		ft_put_move(t_list, 'R', 'b');
	}
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

int	ft_get_value(struct s_node *list, int index)
{
	struct s_node	*curr;
	int				i;

	i = 0;
	curr = list;
	if (curr == NULL)
	{
		printf("Trying to read empty array\n");
		exit(10);
	}
	while (curr != NULL)
	{
		if (i == index)
			return (curr->x);
		i++;
		curr = curr->next;
	}
	return (i);
}
