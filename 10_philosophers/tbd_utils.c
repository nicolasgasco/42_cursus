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

void    ft_print_common(t_data *common_data)
{
    printf("\n==================================\n");
    printf("            COMMON                \n");       
    printf("==================================\n");
    printf("Number of philosophers: %d\n", common_data->n_philos);
    printf("Time to death: %d\n", common_data->t_death);
    printf("Time to eat: %d\n", common_data->t_eat);
    printf("Time to sleep: %d\n", common_data->t_sleep);
    printf("Number of eats: %d\n", common_data->n_eats);
    printf("Forks are: ");
    ft_put_forks(common_data->forks);
    // printf("seconds : %ld\nmicro seconds : %d\n\n", common_data->t_start.tv_sec, common_data->t_start.tv_usec);
    printf("__________________________________\n\n");
}

void    ft_print_philo(t_philo *philo)
{
    printf("\n==================================\n");
    printf("            PHILO                \n");       
    printf("==================================\n");
    printf("Philo index is %d\n", philo->i_philo);
    printf("Forks are: ");
    ft_put_forks(philo->forks);
    // printf("seconds : %ld\nmicro seconds : %d\n\n", common_data->t_start.tv_sec, common_data->t_start.tv_usec);
    printf("__________________________________\n\n");
}