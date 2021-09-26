#include "so_long.h"

void    ft_render_tile(t_map *map, char *path, int offset)
{
    t_img     tile;
    void    *rendered_tile;
    int     width;
    int     height;

    tile.width = 32;
    tile.height = 32;
    rendered_tile = mlx_xpm_file_to_image(map->mlx, path, &tile.width, &tile.height);
    mlx_put_image_to_window (map->mlx, map->win, rendered_tile, map->x * 32 + offset, map->y * 32 + offset);
}

void    ft_populate_map(t_map *map, int offset)
{
    map->x = 0;
    map->y = 0;
    printf("Populating window\n");
    while (map->map[map->y] != NULL)
    {
        map->x = 0;
        while (map->map[map->y][map->x] != '\n')
        {
            if (map->map[map->y][map->x] == '0')
                ft_render_tile(map, "./img/water.xpm", offset);
            else if (map->map[map->y][map->x] == '1')
                ft_render_tile(map, "./img/rock.xpm", offset);
            else if (map->map[map->y][map->x] == 'P')
            {   
                if (map->end_game == 0)
                    ft_render_tile(map, "./img/skull.xpm", offset);
                else
                    ft_render_tile(map, "./img/success.xpm", offset);
                map->p_x = map->x;
                map->p_y = map->y;
            }
            else if (map->map[map->y][map->x] == 'E')
                ft_render_tile(map, "./img/exit.xpm", offset);
            else if (map->map[map->y][map->x] == 'C')
                ft_render_tile(map, "./img/star.xpm", offset);
            map->x++;
        }
        map->y++;
    }
}

void    ft_render_map(t_map *map)
{
    int offset;

    offset = 40;
    printf("Initializing window.\n");
	map->mlx = mlx_init();
    map->win = mlx_new_window(map->mlx, map->n_cols * 32 + offset * 2, map->n_rows * 32 + offset * 2, "42 Escape");
    map->end_game = 0;
    ft_populate_map(map, offset);
    ft_listen_events(map);
    mlx_loop(map->mlx);
}