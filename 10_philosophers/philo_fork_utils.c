#include "philo.h"

void ft_start_dinner(t_philo *philo, unsigned int index)
{
	int				*fork_right;
	int				*fork_left;

	fork_right = &philo->common_data->forks[index];
	fork_left = &philo->common_data->forks[ft_get_i(philo, index - 1)];
	// printf("Philosopher %u is before mutex\n", index);
	if (*fork_right == 1 && *fork_left == 1)
	{
		ft_take_forks(philo, index, fork_left, fork_right);
		sleep(philo->common_data->t_sleep);
	}
}

void	ft_take_forks(t_philo *philo, int index, int *fork_left, int *fork_right)
{
	pthread_mutex_lock(&philo->common_data->forks_mutex[index]);
	pthread_mutex_lock(&philo->common_data->forks_mutex[ft_get_i(philo, index - 1)]);
	// printf("Philosopher %u is inside mutex\n", index);
	// ft_print_forks(philo);
	*fork_right = 0;
	*fork_left = 0;
	printf("%u started eating\n", philo->i_philo);
	ft_print_forks(philo);
	sleep(philo->common_data->t_eat);
	// printf("%u finished eating\n", philo->i_philo);
	*fork_right = 1;
	*fork_left = 1;
	// ft_print_forks(philo);
	// printf("Philosopher %u is done taking forks\n", index);
	pthread_mutex_unlock(&philo->common_data->forks_mutex[index]);
	pthread_mutex_unlock(&philo->common_data->forks_mutex[ft_get_i(philo, index - 1)]);
}

int    ft_get_i(t_philo *philo, int index)
{
	int	fork_index;

    if (index < 0)
        fork_index = index + philo->common_data->n_philos;
    else if (index >= philo->common_data->n_philos)
		fork_index = index - philo->common_data->n_philos;
    else
		fork_index = index;
	return (fork_index);
}
