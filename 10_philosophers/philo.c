#include "philo.h"

int main(int argc, char *argv[])
{
    if (argc < 4 || argc > 6)
    {
        ft_putstr("Error: arguments\n");
        return (1);
    }
    philo philo;

    if (argv[0])
    {
        // Continue
    }
    printf("%s %s %s %s\n", argv[1], argv[2], argv[3], argv[4]);
    ft_init_struct(&philo, argc, argv);
    ft_print_struct(&philo);
    return (0);
}