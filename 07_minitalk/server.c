#include "minitalk.h"

void msg_handler(int signum)
{
    ft_printf("Mierda\n")
    if (signum == SIGUSR1)
    {
        printf("Received SIGUSR1!\n");
    }
}

int main(void)
{
    int pid;
    struct sigaction msg_action;

    pid = getpid();
    ft_printf("Server's PID is %d\n", pid);


    // if (signal(SIGUSR1, msg_handler) < 0)
    // {
	// 	ft_printf("sigaction");
	// 	return (1);
	// }


  msg_action.sa_handler = msg_handler;
  sigemptyset (&msg_action.sa_mask);
  msg_action.sa_flags = 0;

    sigaction (SIGUSR1, NULL, &msg_action);
    while (1)
		sleep (10);
    return (0);
}