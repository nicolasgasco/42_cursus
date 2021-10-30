/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:44:18 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/30 18:11:02 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_iterate_list(struct Node *root, char c)
{
	struct Node	*curr;
	
	curr = root;
	printf("Nodes list %c: {", c);
	while (curr != NULL)
	{
		if (!curr->next)
			printf("%d", curr->x);
		else
			printf("%d, ", curr->x);
		curr = curr->next;
	}
	printf("}\n");
}

void	ft_deallocate_list(struct Node **root)
{
	struct Node	*curr;
	struct Node	*aux;

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

void	ft_insert_end(struct Node **root, int value)
{
	struct Node	*new_node;
	struct Node	*curr;

	new_node = malloc(sizeof(struct Node));
	if (new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->x = value;
	if (*root == NULL)
		*root = new_node;
	curr = *root;
	while(curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	ft_insert_beginning(struct Node **root, int value)
{
	struct Node	*new_node;

	new_node = malloc(sizeof(struct Node));
	if (new_node == NULL)
		exit(1);
	new_node->x = value;
	new_node->next = *root;
	*root = new_node;
}

void	ft_insert_after(struct Node *node, int value)
{
	struct Node	*new_node;

	new_node = malloc(sizeof(struct Node));
	if (new_node == NULL)
		exit(1);
	new_node->x = value;
	new_node->next = node->next;
	node->next = new_node;
}

void	ft_swap_nodes(struct Node **root, int i1, int i2)
{
	int			i;
	struct Node	*curr;
	struct Node *temp;
	struct Node	*node1;

	curr = *root;
	node1 = malloc(sizeof(struct Node));
	temp = malloc(sizeof(struct Node));
	i = 0;
	while (i < i1)
	{
		curr = curr->next;
		i++;
	}
	node1 = curr;
	while (i < i2)
	{
		curr = curr->next;
		i++;
	}
	temp->x = curr->x;
	curr->x = node1->x;
	node1->x = temp->x;
}

void	ft_remove_node(struct Node **root, int index)
{
	struct Node *curr;
	struct Node	*to_remove;
	int			i;
	
	i = 1;
	curr = *root;
	if (*root == NULL)
		return;
	if (index == 0)
	{
		to_remove = *root;
		*root = (*root)->next;
		free(to_remove);
		return;
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
