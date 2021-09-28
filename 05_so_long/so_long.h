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
#include "mlx/mlx.h"

#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3


#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	Maps {
	char    **map;
	int     n_rows;
	int     n_cols;
	int     x;
	int     y;
	int     p_x;
	int     p_y;
	void	*mlx;
	void	*win;
	int     moves;
	int     end_game;
	int     n_collect;
}				t_map;

typedef struct Imgs {
	char    *path;
	int		width;
	int		height;
	void    *rendered_tile;
}               t_img;

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
char	**ft_create_bi_array(char *file, int size, t_map *map);

// Rendering map
void    ft_render_map(t_map *map);
void    ft_populate_map(t_map *map, int offset, int start);
char	*ft_itoa(int n);
int     ft_compare_strings(char *s1, char *s2);
void    ft_render_tile(t_map *map, char *path, int offset);
void	ft_render_rocks(t_map *map, int offset, int index);
void	ft_render_player(t_map *map, int offset, int x, int y);
void	ft_render_exit(t_map *map, int offset, int start);
void	ft_render_enemy(t_map *map, int offset);
void    ft_render_collectible(t_map *map, int offset, int start);

// Keyboard events
void    ft_listen_events(t_map *map);
int		ft_automated_events(t_map *map);

// Player movement
void    ft_move_player(t_map *map, int x, int y);
void    ft_swap_tiles(char *tile1, char *tile2);
void    ft_remove_collectible(char *player, char *collect);
void    ft_found_exit(char *player, char *collect);
void    ft_end_game(t_map *map);

// Text
void	ft_put_str(char *str);
void	ft_welcome_player();
void	ft_putnbr_fd(int n, int fd);

// Render text
void	ft_put_moves(t_map *map);
void	ft_render_ui(t_map *map, int start);

// Delete
void	ft_print_map(char **map);

#endif
