#ifndef FT_MINITALK_H
# define FT_MINITALK_H
# include <unistd.h>
# include "./ft_printf/ft_printf.h"
# include <stdio.h>
# include <signal.h>


struct sigaction {
    void (*sa_handler)(int);
    // void (*sa_sigaction)(int, siginfo_t *, void *);
    // sigset_t sa_mask;
    // int sa_flags;
    // void (*sa_restorer)(void);
} sigaction;

int	ft_atoi(const char *str);
int	ft_printf(const char *str, ...);
int ft_client(int argc, char *argv[]);
int ft_server(void);


#endif