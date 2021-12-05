#include "philo.h"

int ft_get_x_fork(t_philo *philo, int index)
{
    if (index < 0)
        return (philo->forks[index + philo->n_philos]);
    else if (index >= philo->n_philos)
        return (philo->forks[index - philo->n_philos]);
    return (philo->forks[index]);
}

void    ft_take_fork(t_philo *philo, int index)
{
    if (index < 0)
        philo->forks[index + philo->n_philos] = 0;
    else if (index >= philo->n_philos)
        philo->forks[index - philo->n_philos] = 0;
    else
        philo->forks[index] = 0;
    ft_put_status(philo->t_start, philo->i_philo, 'f');
}

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