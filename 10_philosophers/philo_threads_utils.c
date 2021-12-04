#include "philo.h"

void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}
  
void    ft_create_threads(philo *philo, int argc, char *argv[])
{
	pthread_t		*philos;
	unsigned int	i;
	
	philos = malloc(sizeof(pthread_t) * philo->n_philos + 1);

	ft_putstr("Creating threads...\n");
	i = 0;
	while (i < philo->n_philos)
	{
		if (pthread_create(&philos[i], NULL, myThreadFun, NULL) != 0)
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