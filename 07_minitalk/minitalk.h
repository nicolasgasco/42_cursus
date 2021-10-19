#ifndef FT_MINITALK_H
# define FT_MINITALK_H
# include <unistd.h>
# include "./ft_printf/ft_printf.h"
# include <stdio.h>
# include <signal.h>

// Utils
int     ft_atoi(const char *str);
void    ft_put_bin(int n, int pid);
int     ft_printf(const char *str, ...);
// Scripts
int     ft_client(int argc, char *argv[]);
int     ft_server(void);


#endif