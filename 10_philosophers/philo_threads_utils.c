#include "philo.h"

void *ft_thread_action(void *vargp)
{
	struct timeval	current_time;
	t_data	*philo_cpy;
	
	philo_cpy = vargp;
	usleep(50);
	ft_calc_elapsed_time(philo_cpy);
    usleep(100000);
	printf("NUmber of philosophers inside of thread is %d\n", philo_cpy->n_philos);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}
  
void    ft_create_threads(t_data *philo, int argc, char *argv[])
{
	pthread_t		*philos;
	unsigned int	i;
	
	philos = malloc(sizeof(pthread_t) * philo->n_philos + 1);

	ft_putstr("Creating threads...\n");
	i = 0;
	while (i < philo->n_philos)
	{
		printf("NUmber of philosophers is %d\n", philo->n_philos);
		if (pthread_create(&philos[i], NULL, ft_thread_action, philo) != 0)
		{
			ft_putstr("Failed to created thread\n");
			exit (1);
		}
		printf("Thread %d has started\n", i + 1);
		i++;
	}
	i = 0;
	while (i < philo->n_philos)
	{
		if (pthread_join(philos[i], NULL) != 0)
		{
			ft_putstr("Failed to join thread\n");
			exit (2);
		}
		printf("Thread %d has finished execution\n", i + 1);
	
		i++;
	}
	printf("After Threads\n");
}