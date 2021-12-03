#include "philo.h"

void    ft_putstr(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        write(1, &s[i], 1);
        i++;
    }
}