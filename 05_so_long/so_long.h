/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:07:44 by ngasco            #+#    #+#             */
/*   Updated: 2021/09/25 12:33:21 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlx/mlx.h"

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	Maps {
	char    **map;
    int     n_rows;
    int     n_cols;
    int     x;
    int     y;
}				map;

typedef struct  Windows {
    void	*mlx;
    void	*win;
}               win;

typedef struct Imgs {
    char    *path;
	int		width;
	int		height;
} img;


// Get next line
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strrchr(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_next_line(int fd, int buffer_size);

// Map validation
int     ft_map_line_length(char *str);
void    ft_check_middle_line(char *line);
void    ft_check_horizontal_border(char *line);
void    ft_check_foreign_chars(char *line);
void    ft_check_min_chars(char *line);
void    ft_check_map_length(char *line);
void	ft_validate_map(int file, int *size);
void	ft_open_for_validation(char	*file, int *size);

// Saving map
char	**ft_create_bi_array(char *file, int size, map *map);

// Rendering map
void    ft_render_map(map *map);
void    ft_populate_map(win *window, map *map);

#endif
