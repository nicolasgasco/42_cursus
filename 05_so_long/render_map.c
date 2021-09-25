#include "so_long.h"

void    ft_render_tile(win  *window, map *map, char *path)
{
    img     tile;
    void    *rendered_tile;
    int     width;
    int     height;

    tile.width = 32;
    tile.height = 32;
    rendered_tile = mlx_xpm_file_to_image(window->mlx, path, &tile.width, &tile.height);
    mlx_put_image_to_window (window->mlx, window->win, rendered_tile, map->x * 32, map->y * 32);
}

void    ft_populate_map(win *window, map *map)
{
    map->x = 0;
    map->y = 0;
    while (map->map[map->y] != NULL)
    {
        map->x = 0;
        while (map->map[map->y][map->x] != '\n')
        {
            if (map->map[map->y][map->x] == '0')
                ft_render_tile(window, map, "./img/water.xpm");
            else if (map->map[map->y][map->x] == '1')
                ft_render_tile(window, map, "./img/rock.xpm");
            else if (map->map[map->y][map->x] == 'P')
                ft_render_tile(window, map, "./img/skull.xpm");
            else if (map->map[map->y][map->x] == 'E')
                ft_render_tile(window, map, "./img/exit.xpm");
            else if (map->map[map->y][map->x] == 'C')
                ft_render_tile(window, map, "./img/star.xpm");
            map->x++;
        }
        map->y++;
    }
}

void    ft_render_map(map *map)
{
    win window;
	// void	*img;
	// char	*relative_path = "./img/tile_water.xpm";
	// int		img_width;
	// int		img_height;

    printf("Initializing window.\n");
	window.mlx = mlx_init();
    window.win = mlx_new_window(window.mlx, map->n_cols * 32, map->n_rows * 32, "42 Escape");
    ft_populate_map(&window, map);
    mlx_loop(window.mlx);
}