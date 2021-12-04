#include "philo.h"

int main(int argc, char *argv[])
{
	if (argc < 4 || argc > 6)
	{
		ft_putstr("Error: arguments\n");
		return (1);
	}
	t_data			philo;
	pthread_t		*philos;
	unsigned int	i;
	
	ft_init_struct(&philo, argc, argv);
	ft_print_struct(&philo);
	ft_create_threads(&philo, argc, argv);
	return (0);
}