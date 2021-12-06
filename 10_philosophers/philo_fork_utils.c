#include "philo.h"

void ft_start_eating(t_philo *philo, unsigned int index)
{
	printf("Philosopher %d is trying to eat\n", index);
	ft_take_forks(philo, index);
	sleep(1);
}

void	ft_take_forks(t_philo *philo, int index)
{
	printf("Philosopher %u is before mutex\n", philo->i_philo);
	pthread_mutex_lock(&philo->common_data->forks_mutex[philo->i_philo]);
	pthread_mutex_lock(&philo->common_data->forks_mutex[ft_check_fork_index(philo, philo->i_philo - 1)]);
	printf("Philosopher %u is inside mutex\n", philo->i_philo);
	ft_print_forks(philo);
	philo->common_data->forks[philo->i_philo] = 0;
	philo->common_data->forks[ft_check_fork_index(philo, ft_check_fork_index(philo, philo->i_philo - 1))] = 0;
	ft_print_forks(philo);
	int i = 0;
	while (i < 5)
	{
		printf("Philosopher %u is taking forks (%d/5)\n", philo->i_philo, i + 1);
		ft_print_forks(philo);
		sleep(2);
		i++;
	}
	philo->common_data->forks[philo->i_philo] = 1;
	philo->common_data->forks[ft_check_fork_index(philo, ft_check_fork_index(philo, philo->i_philo - 1))] = 1;
	ft_print_forks(philo);
	printf("Philosopher %u is done taking forks\n", philo->i_philo);
	pthread_mutex_unlock(&philo->common_data->forks_mutex[philo->i_philo]);
	pthread_mutex_unlock(&philo->common_data->forks_mutex[ft_check_fork_index(philo, philo->i_philo - 1)]);
	printf("Philosopher %u is after mutex\n", philo->i_philo);
}

pthread_mutex_t *ft_create_forks_mutex(int n_philos, t_data *common_data)
{
	pthread_mutex_t *result;

	result = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n_philos);
	return (result);
}

int    ft_check_fork_index(t_philo *philo, int index)
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

int *ft_create_forks(int n_philos)
{
	int *result;
	int i;

	i = 0;
	result = (int *)malloc(sizeof(int) * n_philos + 1);
	while (i < n_philos)
	{
		result[i] = 1;
		i++;
	}
	result[i] = -1;
	return (result);
}
