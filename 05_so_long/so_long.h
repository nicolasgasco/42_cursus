// #include "minilibx_opengl_20191021/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


#ifndef SO_LONG_H
# define SO_LONG_H


// Get next line
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strrchr(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_next_line(int fd, int buffer_size);
// Map validation
void    ft_validate_map(int file);
int     ft_str_length(char *str);

#endif
