#include "philo.h"

int main(int argc, char *argv[])
{
	if (argc < 4 || argc > 6)
	{
		ft_putstr(2, "Error: arguments\n");
		return (1);
	}
	t_data			common_data;
	pthread_t		*philos;
	unsigned int	i;
	
	ft_init_struct(&common_data, argc, argv);
	ft_print_struct(&common_data);
	ft_create_threads(&common_data, argc, argv);
	return (0);
}