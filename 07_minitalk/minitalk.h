#ifndef FT_MINITALK_H
# define FT_MINITALK_H
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

int    g_bin;
// Utils
int     ft_atoi(const char *str);
int     ft_printf(const char *str, ...);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int     ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);

// Scripts
int     ft_client(int argc, char *argv[]);
int     ft_server(void);
void	ft_put_bin(int n, int pid);
void	ft_inttobin(int	n, int	pid);

#endif