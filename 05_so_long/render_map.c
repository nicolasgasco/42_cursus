#include "so_long.h"

void    ft_render_tile(win  *window, map *map, char *path, int offset)
{
    img     tile;
    void    *rendered_tile;
    int     width;
    int     height;

    tile.width = 32;
    tile.height = 32;
    rendered_tile = mlx_xpm_file_to_image(window->mlx, path, &tile.width, &tile.height);
    mlx_put_image_to_window (window->mlx, window->win, rendered_tile, map->x * 32 + offset, map->y * 32 + offset);
}

void    ft_populate_map(win *window, map *map, int offset)
{
    map->x = 0;
    map->y = 0;
    while (map->map[map->y] != NULL)
    {
        map->x = 0;
        while (map->map[map->y][map->x] != '\n')
        {
            if (map->map[map->y][map->x] == '0')
                ft_render_tile(window, map, "./img/water.xpm", offset);
            else if (map->map[map->y][map->x] == '1')
                ft_render_tile(window, map, "./img/rock.xpm", offset);
            else if (map->map[map->y][map->x] == 'P')
                ft_render_tile(window, map, "./img/skull.xpm", offset);
            else if (map->map[map->y][map->x] == 'E')
                ft_render_tile(window, map, "./img/exit.xpm", offset);
            else if (map->map[map->y][map->x] == 'C')
                ft_render_tile(window, map, "./img/star.xpm", offset);
            map->x++;
        }
        map->y++;
    }
}

void    ft_render_map(map *map)
{
    win window;
    int offset;

    offset = 40;
    printf("Initializing window.\n");
	window.mlx = mlx_init();
    window.win = mlx_new_window(window.mlx, map->n_cols * 32 + offset * 2, map->n_rows * 32 + offset * 2, "42 Escape");
    ft_populate_map(&window, map, offset);
    mlx_loop(window.mlx);
}