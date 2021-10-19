#ifndef FT_MINITALK_H
# define FT_MINITALK_H
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

char    *g_bin_str;
// Utils
int     ft_atoi(const char *str);
void	ft_stobin(int n, int pid);
int     ft_printf(const char *str, ...);
char	*ft_strjoin(char const *s1, char const *s2);
// Scripts
int     ft_client(int argc, char *argv[]);
int     ft_server(void);


#endif