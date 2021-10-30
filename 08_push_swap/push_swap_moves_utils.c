#include "push_swap.h"

void	ft_ss(num_list *number_list)
{
	struct Node	*root1;
	struct Node	*root2;

	root1 = number_list->a_list;
	root2 = number_list->b_list;
	if (root1 == NULL || root1->next == NULL || root1->next->next == NULL)
		return;
	if (root2 == NULL || root2->next == NULL || root2->next->next == NULL)
		return;

	ft_putstr_fd("ss", 0);
	ft_putchar_fd('\n', 0);
	ft_swap_nodes(&root1, 0, 1);
	ft_swap_nodes(&root2, 0, 1);
	number_list->num_moves += 2;
}

void	ft_s(num_list *number_list, char c)
{
	if (c == 's')
	{
		ft_ss(number_list);
		return;
	}
	struct Node	*root;
	if (c == 'a')
		root = number_list->a_list;
	else
		root = number_list->b_list;
	
	if (root == NULL || root->next == NULL || root->next->next == NULL)
		return;
	
	ft_putchar_fd('s', 0);
	ft_putchar_fd(c, 0);
	ft_putchar_fd('\n', 0);
	ft_swap_nodes(&root, 0, 1);
	number_list->num_moves += 1;
}