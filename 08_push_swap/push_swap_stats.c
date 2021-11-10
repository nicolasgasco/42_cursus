#include "push_swap.h"

int ft_list_len(struct s_node **root)
{
    struct s_node	*curr;
    int             i;

    i = 0;
	curr = *root;
	if (curr == NULL)
        return (0);
	else
	{
        curr = curr->next;
        i++;
	}
    return (i);
}