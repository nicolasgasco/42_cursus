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
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "mlx/mlx.h"

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	Maps {
	char    **map;
	void	*mlx;
	void	*win;
	int     n_rows;
	int     n_cols;
	int     moves;
	int     end_game;
	int		enem_n;
	int		p_death;
	int     n_collect;
	int		p_direction;
	int     x;
	int     y;
	int     p_x;
	int     p_y;
	int		e_x;
	int		e_y;
}				t_map;

typedef struct Imgs {
	char    *path;
	int		w;
	int		h;
	void    *r_tile;
}               t_img;

// Get next line
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strrchr(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_next_line(int fd, int buffer_size);

// Map validation
void	ft_validate_map(int file, int *size);
void    ft_check_min_chars(char *line);
int     ft_map_line_length(char *str);
void    ft_check_middle_line(char *line);
void    ft_check_horizontal_border(char *line);
void    ft_check_foreign_chars(char *line);
void    ft_check_map_length(char *line);
void	ft_open_for_validation(char	*file, int *size);

// Saving map
char	**ft_create_bi_array(char *file, int size, t_map *map);

// Rendering map
void    ft_render_map(t_map *map);
void    ft_populate_map(t_map *map, int offset, int start);
int     ft_compare_strings(char *s1, char *s2);
void    ft_render_tile(t_map *map, char *path, int offset);
void	ft_render_rocks(t_map *map, int offset, int index);
void	ft_render_player(t_map *map, int offset, int x, int y);
void	ft_render_exit(t_map *map, int offset, int start);
void	ft_render_enemy(t_map *map, int offset, int x, int y);
void    ft_render_collectible(t_map *map, int offset, int start);
char	*ft_itoa(int n);

//  Events
void    ft_listen_events(t_map *map);

// Player movement
void    ft_move_player(t_map *map, int x, int y);
void    ft_swap_tiles(char *tile1, char *tile2);
void    ft_remove_collect(char *player, char *collect);
void    ft_found_exit(char *player, char *collect);
void    ft_check_if_end(t_map *map);
void	ft_enemy_movement(t_map *map);

// Enemy movement
void	ft_kill_player(t_map *map, char *enemy);
void	ft_enemy_up(t_map *map, int *x, int *y, int *direction);
void	ft_enemy_right(t_map *map, int *x, int *y, int *direction);
void	ft_enemy_down(t_map *map, int *x, int *y, int *direction);
void	ft_enemy_left(t_map *map, int *x, int *y, int *direction);

// Text to console
void	ft_put_str(char *str);
void	ft_welcome_player();
void	ft_putnbr_fd(int n, int fd);

// Render text
void	ft_put_moves(t_map *map);
void	ft_render_ui(t_map *map, int start);

#endif
