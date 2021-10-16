#include "minitalk.h"

int main(int argc, char *argv[])
{
    int     pid;
    char    *message;

    if (argc != 3)
    {
        printf("Number of arguments is not correct\n");
        return (1);
    }
    pid = ft_atoi(argv[1]);
    message = argv[2];
    ft_printf("PID is %d\n", pid);
    ft_printf("String is %s\n", message);
    kill(pid, SIGUSR1);
    return (0);
}