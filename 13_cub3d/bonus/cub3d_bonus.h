/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:29:00 by jsolinis          #+#    #+#             */
/*   Updated: 2022/08/07 20:20:34 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "../mlx/mlx.h"

/* Game params */
# define GAME_TITLE "Cub3D"
# define WIN_WIDTH 1280
# define WIN_HEIGHT 1024
# define NO_TEXTURE_I 0
# define EA_TEXTURE_I 1
# define SO_TEXTURE_I 2
# define WE_TEXTURE_I 3
# define NUM_OF_TEXTURES 4
# define TEXTURE_MIN_SIZE 32
# define TEXTURE_MAX_SIZE 256

/* Events */
# define ON_DESTROY 17
# define ON_KEY_DOWN 2
# define ON_MOUSE_MOVE 6

/* Key bindings */
// Linux
# define ESC_KEY_LINUX 65307
# define LEFT_ARR_LINUX 65361
# define UP_ARR_LINUX 65362
# define RIGHT_ARR_LINUX 65363
# define DOWN_ARR_LINUX 65364
# define A_KEY_LINUX 97
# define W_KEY_LINUX 119
# define D_KEY_LINUX 100
# define S_KEY_LINUX 115

// Mac
# define ESC_KEY_MAC 53
# define LEFT_ARR_MAC 123
# define UP_ARR_MAC 126
# define RIGHT_ARR_MAC 124
# define DOWN_ARR_MAC 125
# define A_KEY_MAC 0
# define W_KEY_MAC 13
# define D_KEY_MAC 2
# define S_KEY_MAC 1

/* Mouse bindings */
# define LEFT_CLICK 1

// Conversion
# define UPPERCASE_DIGIT_DIFF 55
# define LOWERCASE_DIGIT_DIFF 87
# define NO_TRANSPARENCY 0

# define PI 3.14159265359
# define FIELD_OF_VIEW 60
# define V_MOVEMENT_INCREMENT 50
# define H_MOVEMENT_INCREMENT 40
# define L_MOVEMENT_INCREMENT 10
# define MIN_DISTANCE_FORWARD 40
# define MIN_DISTANCE_BACKWARD 20

/*Vector Struct*/
typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

/* Struct for ray calculation */
typedef struct s_projection
{
	char		player_orientation;
	int			view_angle;
	double		distance_to_pp;
	t_vector	*player;
	t_vector	*wall_to_render;
}				t_projection;

/* Struct for each column */
typedef struct s_slice
{
	int			angle;
	int			column;
	double		distance_to_wall;
	int			height;
	int			texture;
	int			v_wall_x;
	int			h_wall_x;
	int			wall_x;
}				t_slice;

/* Linked list used to manipulate texture files */
struct s_cinfo
{
	char			col_char;
	int				col_int;
	struct s_cinfo	*next;
};

/* Struct with info on single texture */
typedef struct s_tdata
{
	int				texture_w;
	int				texture_h;
	int				**texture_columns;
	struct s_cinfo	*col_info_list;
}		t_tdata;

/* Struct with info necessary to render textures */
typedef struct s_rdata
{
	int				c_col_int;
	int				f_col_int;
	t_tdata			*textures;
}		t_rdata;

/* Struct for rendering pixels */
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

/* Struct for mlx */
typedef struct s_view
{
	void	*mlx;
	void	*mlx_win;
	t_data	*plane_data;
	char	*title;
}			t_view;

/* Struct for map data  */
typedef struct s_map
{
	char			*no_path;
	char			*so_path;
	char			*ea_path;
	char			*we_path;
	char			*f_color;
	char			*c_color;
	int				height;
	int				width;
	int				y;
	char			**map_content;
	int				texture_size;
	t_rdata			*rdata;
	t_projection	*prj;
	t_slice			*slc;
	t_view			*view;
}					t_map;

/* Utils */
// Utils - Common error
void			ft_malloc_error(void);
void			ft_open_file_error(void);
void			ft_print_error_exit(t_map *map, char *msg, int err);
// Utils - Debug
void			ft_write_debug_msg(char *msg);
void			ft_write_debug_msg_int(char *msg, int int_arg);
// Utils - Free
void			ft_free_allocated_map_data(t_map *map);
void			ft_free_allocated_render_data(t_map *map);
void			ft_free_map_content(t_map *map);
void			ft_free_col_info_list(t_tdata *texture);
void			ft_free_texture_columns(t_map *map, t_tdata *texture);
void			ft_free_raycast_data(t_map *map);
void			ft_free_slice_data(t_map *map);
// Utils - Common utils
int				ft_open_file(char *file_path);
int				ft_isspace(char c);
void			ft_skip_to_non_space_char(char *line, int *iterator);
char			*ft_substr_no_leaks(char *s, unsigned int start, size_t len);
char			*ft_strtrim_no_leaks(char *s1, const char *set);
int				ft_str_is_numeric(char *str);
void			ft_skip_to_content(char *line, int *iterator);
int				ft_str_contains_char(char *str, char c);
int				ft_str_is_not_hex(char *str, int start);
int				ft_str_contains_spaced_char(char *str, char c);
// Utils - Get next line
char			*get_next_line(int fd);
// Utils - Map content
int				ft_is_player_char(char c);
int				ft_is_valid_map_char(char c);
void			ft_check_player_number(t_map *map, int player);
int				ft_isspace_no_endl(char c);
// Utils - Map
int				ft_is_map_start(char *line);
void			ft_get_map_width(char *line, t_map *map);
char			*ft_skip_to_map_start(char *line, int fd);
void			ft_skip_to_non_space_char_backwards(char *line, int *iterator);
char			*ft_check_to_eof(char *line, int fd, t_map *map);
// Utils - Raycast
void			ft_set_player_data(t_map *map, int *iterator, int *j, char c);
void			ft_set_viewing_angle(t_map *map);
void			ft_convert_to_cube_position(t_map *map);
int				ft_is_facing_down(double angle);
int				ft_is_facing_right(double angle);
int				ft_transform_angle(int angle);
t_vector		ft_increment(t_vector position, t_vector increment);
int				ft_hit(t_map *map, t_vector position, int angle);
//Raycast tables
t_vector		ft_horizontal_increment(int texture_size, int angle);
t_vector		ft_vertical_increment(int texture_size, int angle);
double			ft_cosine(int angle);
double			ft_sine(int angle);
double			ft_tangent(int angle);
void			ft_get_texture(t_map *map, int angle, char axis);

/* Scene desc validation errors */
void			ft_invalid_extension_error_exit(void);
void			ft_invalid_id_error_exit(t_map *map, char *line);
void			ft_empty_scene_file_error_exit(void);
void			ft_missing_file_path_error_exit(char *o_path_id, char *line,
					t_map *map);
void			ft_invalid_color_code_error_exit(t_map *map, char *line,
					char *col_code_str);
void			ft_invalid_col_statement_error_exit(t_map *map, char *line);
void			ft_incomplete_scene_info_error_exit(t_map *map);
void			ft_duplicate_scene_info_error_exit(t_map *map);
void			ft_invalid_orientation_path_error_exit(char *line,
					char *o_path_id, char *o_path);

/* Scene description file validation */
void			ft_scene_desc_file_validation(int argc, char *file_path,
					t_map *map);
void			ft_check_num_args(int argc);
void			ft_file_extension_validation(char *file_path);
// Type ids
void			ft_type_ids_validation(char *file_path, t_map *map);
int				ft_validate_scene_file_line(char *line, t_map *map);
// Type ids - Orientation paths
void			ft_validate_parse_o_path(char *line, int *i, t_map *map);
char			*ft_validate_o_path(t_map *map, char *o_path_id,
					char *line, int *i);
char			*ft_parse_valid_path(t_map *map, char *o_path_id,
					char *line, int *i);
int				ft_calc_path_length(char *line, int i);
int				ft_check_o_path_already_assigned(t_map *map, char *o_path_id);
int				ft_validate_f_path(t_map *map, char *o_path, char *line,
					char *o_p_id);
// Type ids - Colors validation
void			ft_validate_parse_color(char *line, int *i, t_map *map);
char			*ft_validate_color_codes(char *line, int *i, t_map *map);
int				ft_parse_color_codes(char *line, int *iterator, t_map *map);
int				ft_parse_single_color_code(t_map *map, char *line,
					int *iterator);
void			ft_validate_single_col_code(t_map *map, char *col_code_str,
					char *line);
void			ft_check_col_already_assigned(t_map *map, char *color_id,
					char *line);
int				ft_check_if_other_num_same_line(char *line, int iterator);
// Type ids - Completeness check
void			ft_type_ids_completeness_check(t_map *map);
void			ft_check_o_paths_duplicates(t_map *map);
void			ft_find_o_paths_duplicates(char **path_arr, t_map *map);
void			ft_free_validation_path_arr(char **path_arr);
// Map content
void			ft_map_content_validation(char *file_path, t_map *map);
void			ft_check_characters(t_map *map);
void			ft_validate_size(t_map *map);
void			ft_validate_walls(t_map *map);
void			ft_validate_content(t_map *map);

/* Raycasting Calculation */
void			ft_raycasting_calculation(t_map *map);
void			ft_raycast_to_slice(t_map *map);

/* Post validation data manip */
void			ft_validate_texture_files(t_map *map);
void			ft_post_validation_data_manip(t_map *map);
// Post validation data manip - Errros
void			ft_color_not_valid_error(void);
void			ft_texture_file_invalid(t_map *map, void *mlx);
// Post validation data manip - Floor/Ceiling Colors
int				ft_rgb_str_to_int(char *col_str);
void			ft_populate_rgb_int_arr(char *col_str, int *rgb);
int				ft_substr_and_atoi(char *col_str, int start, int end);
int				ft_rgb_to_int(int t, int r, int g, int b);
// Post validation data manip - Color codes
void			ft_readline_color_codes(int fd, char *line, t_tdata *texture);
void			ft_parse_char_col(char *line, t_tdata *rdata);
struct s_cinfo	*ft_create_col_info_struct(char *line);
void			ft_double_color_id_error(void);
int				ft_hex_str_to_int(char *hex);
struct s_cinfo	*ft_populate_col_info(char col_char, char *col_hex);
// Post validation data manip - Asset sizes
void			ft_readline_asset_sizes(int fd, char *line, t_tdata *texture);
void			ft_parse_asset_sizes(char *line, t_tdata *texture);
int				ft_calc_size_len(char *line, int i);
void			ft_parse_all_texture_files(t_map *map);
t_tdata			ft_parse_texture_file(char *texture_path);
void			ft_get_texture_sizes(t_map *map, char *path, int *width,
					int *height);
void			ft_parse_texture_sizes(char *line, int *width, int *height);
int				ft_xpm_file_is_valid(t_map *map, char *path, void *mlx);
void			ft_asset_file_error(int file_fd, t_map *map);
// Post validation data manip - Char map
void			ft_readline_char_map(int fd, char *line, t_tdata *texture);
void			ft_fill_int_matrix_line(t_tdata *texture, char *line, int y);

/* Render view */
void			ft_render_view(t_map *map);
void			ft_view_events(t_map *map);
int				ft_close_window(t_map *map);
int				ft_keyboard_events(int key, t_map *map);
int				ft_mouse_events(int x, int y, t_map *map);
void			ft_mouse_rotation(int x, int y, t_map *map);

/* Rendering textures */
void			ft_render_raycasting_column(t_map *map);
void			ft_render_ceiling(t_map *map, int *y);
void			ft_render_floor(t_map *map, int *y);
void			ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_render_game_scene(t_map *map);

/* Player movements */
void			ft_move_forward(t_map *map, double angle, int increment);
void			ft_move_backward(t_map *map, double angle, int increment);
void			ft_move_leftward(t_map *map, double angle, int increment);
void			ft_move_rightward(t_map *map, double angle, int increment);
void			ft_rotate_leftward(t_map *map, double angle, int increment);
void			ft_rotate_rightward(t_map *map, double angle, int increment);
/* Player movements - Utils */
int				ft_angle_to_degrees(int angle);
char			ft_get_current_map_char(t_map *map, double x, double y);
double			ft_forward_movement_hits_wall(t_map *map, double v_increase,
					double l_increase);
double			ft_backward_movement_hits_wall(t_map *map, double v_increase,
					double l_increase);

/* scaling textures */
void			ft_render_scaled_texture(t_map *map);
void			ft_render_texture_smaller_than_screen(t_map *map);
void			ft_render_texture_bigger_than_screen(t_map *map);

#endif
