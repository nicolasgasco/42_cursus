#include "so_long.h"

void    ft_render_tile(t_map *map, char *path, int offset)
{
    t_img		tile;
    static void	*rendered_tile;
    static char	*previous_path;

	tile.width = 32;
    tile.height = 32;
	if (!previous_path)
		previous_path = ft_strdup(path);
	if (!rendered_tile || ft_compare_strings(previous_path, path) == 0)
		rendered_tile = mlx_xpm_file_to_image(map->mlx, path, &tile.width, &tile.height);
	mlx_put_image_to_window (map->mlx, map->win, rendered_tile, map->x * 32 + offset, map->y * 32 + offset);
	free(previous_path);
	previous_path = ft_strdup(path);	
}

void    ft_render_text(t_map *map, int start)
{
    int     text_y;
    int     width;
    int     height;
    t_img   black;

    text_y = 25;
    black.width = 20;
    black.height = 30;

    if (start)
    {
        mlx_string_put(map->mlx, map->win, 40, 25, 0x00FFFFFF, "Ahoy, pirate!");
        mlx_string_put(map->mlx, map->win, map->n_cols * 32 - 30, text_y, 0x00FFFFFF, "Moves: ");
    }
    black.rendered_tile = mlx_xpm_file_to_image(map->mlx, "./img/black.xpm", &black.width, &black.height);
    mlx_put_image_to_window (map->mlx, map->win, black.rendered_tile, map->n_cols * 32  + 30, 10);
    mlx_string_put(map->mlx, map->win, map->n_cols * 32  + 30, text_y, 0x00FFFFFF, ft_itoa(map->moves));
}

void    ft_populate_map(t_map *map, int offset, int start)
{
    map->x = 0;
    map->y = 0;

    ft_render_text(map, start);
    while (map->map[map->y] != NULL)
    {
        map->x = 0;
        while (map->map[map->y][map->x] != '\n')
        {
            if (map->map[map->y][map->x] == '0')
                ft_render_tile(map, "./img/water.xpm", offset);
            else if (map->map[map->y][map->x] == '1')
                ft_render_rocks(map, offset, map->y + map->x);
            else if (map->map[map->y][map->x] == 'P')
                ft_render_player(map, offset);
            else if (map->map[map->y][map->x] == 'E')
				ft_render_exit(map, offset, start);
            else if (map->map[map->y][map->x] == 'C')
                ft_render_collectible(map, offset, start);
            map->x++;
        }
        map->y++;
    }
}

void    ft_render_map(t_map *map)
{
    int offset;

    offset = 40;
    // printf("Initializing window.\n");
	map->mlx = mlx_init();
    map->win = mlx_new_window(map->mlx, map->n_cols * 32 + offset * 2, map->n_rows * 32 + offset * 2, "42 Escape");
    map->end_game = 0;
    map->moves = 0;
    map->n_collect = 0;
    ft_populate_map(map, offset, 1);
    ft_listen_events(map);
    mlx_loop(map->mlx);
}