#include "push_swap.h"

int ft_list_len(struct s_node *root)
{
    struct s_node	*curr;
    int             i;

    i = 0;
	curr = root;
	if (curr == NULL)
        return (0);
	while(curr != NULL)
	{
        i++;
        curr = curr->next;
	}
    return (i);
}

int ft_find_hilo(struct s_node *root, char flag)
{
    struct s_node	*curr;
    int             result;

    curr = root;
	if (curr == NULL)
        return (0);
    result = curr->x;
	while(curr != NULL)
	{
        if (flag == 'h')
        {
            if (curr->x > result)
                result = curr->x;
        }
        else
        {
            if (curr->x < result)
                result = curr->x;
        }
        curr = curr->next;
	}
    return (result);
}

void    ft_update_stats(t_list *n_list)
{
    n_list->a_len = ft_list_len(n_list->a_list);
    n_list->b_len = ft_list_len(n_list->b_list);
    n_list->hi_a = ft_find_hilo(n_list->a_list, 'h');
    n_list->hi_b = ft_find_hilo(n_list->b_list, 'h');
    n_list->lo_a = ft_find_hilo(n_list->a_list, 'l');
    n_list->lo_b = ft_find_hilo(n_list->b_list, 'l');
}