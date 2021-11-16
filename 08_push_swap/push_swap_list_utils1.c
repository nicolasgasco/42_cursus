/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:44:18 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/16 18:52:45 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_deallocate_list(struct s_node **root)
{
	struct s_node	*curr;
	struct s_node	*aux;

	curr = *root;
	if (curr == NULL)
		*root = NULL;
	else
	{
		aux = curr;
		ft_deallocate_list(&curr->next);
		free(aux);
	}
}

void	ft_insert_end(struct s_node **root, int value)
{
	struct s_node	*new_node;
	struct s_node	*curr;

	new_node = malloc(sizeof(struct s_node));
	if (new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->x = value;
	if (*root == NULL)
		*root = new_node;
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
	// free(new_node);
}

void	ft_insert_beginning(struct s_node **root, int value)
{
	struct s_node	*new_node;

	new_node = malloc(sizeof(struct s_node));
	if (new_node == NULL)
		exit(1);
	new_node->x = value;
	new_node->next = *root;
	*root = new_node;
}

void	ft_remove_node(struct s_node **root, int index)
{
	struct s_node	*curr;
	struct s_node	*to_remove;
	int				i;

	i = 1;
	curr = *root;
	if (*root == NULL)
		return ;
	if (index == 0)
	{
		to_remove = *root;
		*root = (*root)->next;
		free(to_remove);
		return ;
	}
	while (i < index)
	{
		curr = curr->next;
		i++;
	}
	to_remove = curr->next;
	curr->next = curr->next->next;
	free(to_remove);
}

void	ft_free_lists(t_list *n_list)
{
	ft_deallocate_list(&n_list->a_list);
	ft_deallocate_list(&n_list->b_list);
	ft_deallocate_list(&n_list->o_list);
}

