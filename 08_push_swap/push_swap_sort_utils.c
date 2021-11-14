#include "push_swap.h"

void    ft_choose_direction(t_list *n_list, struct s_node *list, int value)
{
    struct s_node	*curr;
    int             i;

    curr = list;
    i = 0;
	while (curr->x != value)
	{
		i++;
		curr = curr->next;
	}
	curr = list;
	if (i >= (n_list->a_len / 2))
	{
		while (i < n_list->a_len)
		{
			ft_move(n_list, 'R', 'a');
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			ft_move(n_list, 'r', 'a');
			i--;
		}

	}
}