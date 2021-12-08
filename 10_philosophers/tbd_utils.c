#include "philo.h"

void    ft_put_forks(int *forks)
{
    int i = 0;

    while (forks[i] != -1)
    {
        if (forks[i + 1] == -1)
            printf("%d", forks[i]);
        else
            printf("%d, ", forks[i]);
        i++;
    }
    printf("\n");
}

void    ft_print_common(t_data *c_data)
{
    printf("\n==================================\n");
    printf("            COMMON                \n");       
    printf("==================================\n");
    printf("Number of philosophers: %d\n", c_data->n_philos);
    printf("Time to death: %d\n", c_data->t_death);
    printf("Time to eat: %d\n", c_data->t_eat);
    printf("Time to sleep: %d\n", c_data->t_sleep);
    printf("Number of eats: %d\n", c_data->n_eats);
    printf("Forks are: ");
    ft_put_forks(c_data->forks);
    // printf("seconds : %ld\nmicro seconds : %d\n\n", c_data->t_start.tv_sec, c_data->t_start.tv_usec);
    printf("__________________________________\n\n");
}

void    ft_print_philo(t_philo *philo)
{
    printf("\n==================================\n");
    printf("|            PHILO %d             |\n", philo->i_philo);       
    printf("==================================\n");
    // printf("Philo index is %d\n", philo->i_philo);
    printf("| Fork is %d                      |\n", philo->c_data->forks[philo->i_philo]);
    // ft_put_forks(philo->forks);
    // printf("seconds : %ld\nmicro seconds : %d\n\n", c_data->t_start.tv_sec, c_data->t_start.tv_usec);
    printf("__________________________________\n\n");
}

void    ft_print_forks(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->c_data->n_philos)
    {
        printf("________________.");
        i++;
    }
    printf("\n");
    i = 0;
    while (philo->c_data->forks[i] != -1)
    {
        printf("|| P%d: fork %d || ", i, philo->c_data->forks[i]);
        i++;
    }
    i = 0;
    printf("\n");
    while (i < philo->c_data->n_philos)
    {
        printf("________________.");
        i++;
    }
    printf("\n");
}