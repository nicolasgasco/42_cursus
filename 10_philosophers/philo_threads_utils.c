#include "philo.h"

void *ft_thread_action(void *vargp)
{
	// struct timeval	current_time;
	t_philo	*philo_cpy;
	
	philo_cpy = vargp;
	usleep(100000);
	printf("Tstart %ld\n", philo_cpy->t_start.tv_sec);
	printf("Index inside: %d\n", philo_cpy->i_philo);
	ft_put_status(philo_cpy->t_start, philo_cpy->i_philo, 'f');
	printf("\n\n");
    return NULL;
}
  
void    ft_create_threads(t_data *common_data, int argc, char *argv[])
{
	pthread_t		*philos;
	unsigned int	i;
	t_philo			*philo;
	
	
	philos = malloc(sizeof(pthread_t) * common_data->n_philos + 1);
	ft_putstr(2, "Creating threads...\n");
	i = 0;
	while (i < common_data->n_philos)
	{
		philo = malloc(sizeof(t_philo));
		philo->i_philo = i + 1;
		philo->t_start = common_data->t_start;
		if (pthread_create(&philos[i], NULL, ft_thread_action, philo) != 0)
		{
			ft_putstr(2, "Failed to created thread\n");
			exit (1);
		}
		printf("Thread %d has started\n", i + 1);
		usleep(50000);
		i++;
	}
	i = 0;
	while (i < common_data->n_philos)
	{
		if (pthread_join(philos[i], NULL) != 0)
		{
			ft_putstr(2, "Failed to join thread\n");
			exit (2);
		}
		i++;
	}
	printf("After Threads\n");
}