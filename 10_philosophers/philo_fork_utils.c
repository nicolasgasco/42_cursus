#include "philo.h"

int *ft_init_forks(int n_philos)
{
    int *result;
    int i;

    i = 0;
    result = (int *)malloc(sizeof(int) * n_philos + 1);
    while(i < n_philos)
    {
        result[i] = 1;
        i++;
    }
    result[i] = -1;
    return (result);
}