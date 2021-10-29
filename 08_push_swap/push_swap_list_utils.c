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