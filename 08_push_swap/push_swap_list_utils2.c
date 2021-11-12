#include "push_swap.h"

void    ft_assign_index(struct s_node *linked, int *array, int limit)
{
    struct s_node   *curr;
    int             i;


    i = 1;
    while (i < limit)
    {
        curr = linked;
        while (curr != NULL)
        {
            if (array[i] == curr->x)
                curr->i = i;
            // printf("%d\n", array[i]);
            curr = curr->next;
        }
        i++;
    }
}

int *ft_bubble_sort(int *num_arr, int limit)
{
    int i;
    int temp;
    int sorted;

    // printf("Int arrayu at first\n");
    // ft_print_int_array(num_arr, limit);
    while (1)
    {
        sorted = 1;
        i = 0;
        while (i < (limit - 1))
        {
            if (num_arr[i] > num_arr[i + 1])
            {
                sorted = 0;
                temp = num_arr[i];
                num_arr[i] = num_arr[i + 1];
                num_arr[i + 1] = temp;
            }
            i++;
        }
        // printf("Int arrayu after bubble\n");
        // ft_print_int_array(num_arr, limit);
        if (sorted == 1)
            break;
    }
    return (num_arr);
}