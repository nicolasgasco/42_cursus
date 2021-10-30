#include "push_swap.h"

int	ft_s(struct Node **root, char c)
{
	if (root == NULL || (*root)->next == NULL || (*root)->next->next == NULL)
		return;
	
	ft_putchar_fd('s', 0);
	ft_putchar_fd(c, 0);
	ft_putchar_fd('\n', 0);
	ft_swap_nodes(root, 0, 1);
}