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

void    ft_put_text(t_map *map)
{
    int     text_y;
    t_img   *black;

    text_y = 25;
    black->width = 20;
    black->height = 30;

    mlx_string_put(map->mlx, map->win, 40, 25, 0x00FFFFFF, "Ahoy, pirate!");
    black->rendered_tile = mlx_xpm_file_to_image(map->mlx, "./img/black.xpm", &black->width, &black->height);
    mlx_put_image_to_window (map->mlx, map->win, black->rendered_tile, map->n_cols * 32  + 30, 10);
    mlx_string_put(map->mlx, map->win, map->n_cols * 32 - 30, text_y, 0x00FFFFFF, "Moves: ");
    mlx_string_put(map->mlx, map->win, map->n_cols * 32  + 30, text_y, 0x00FFFFFF, ft_itoa(map->moves));
}

void ft_render_rocks(t_map *map, int offset, int index)
{
    if ((index + 1) % 5 == 0)
        ft_render_tile(map, "./img/rock_3.xpm", offset);
    else if ((index + 1) % 3 == 0)
        ft_render_tile(map, "./img/rock_2.xpm", offset);
    else
        ft_render_tile(map, "./img/rock_1.xpm", offset);
}

void    ft_populate_map(t_map *map, int offset, int start)
{
    map->x = 0;
    map->y = 0;

    printf("Populating window\n");
    ft_put_text(map);
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
            {   
                if (map->end_game == 0)
                    ft_render_tile(map, "./img/skull.xpm", offset);
                else
                    ft_render_tile(map, "./img/success.xpm", offset);
                map->p_x = map->x;
                map->p_y = map->y;
            }
            else if (map->map[map->y][map->x] == 'E')
            {
                if (start == 0 && map->n_collect == 0)
                    ft_render_tile(map, "./img/exit.xpm", offset);
                else
                    ft_render_tile(map, "./img/exit_closed.xpm", offset);
            }
            else if (map->map[map->y][map->x] == 'C')
            {
                if (start == 1)
                    map->n_collect++;
                ft_render_tile(map, "./img/star.xpm", offset);
            }
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
    map->moves = 0;
    map->n_collect = 0;
    ft_populate_map(map, offset, 1);
    ft_listen_events(map);
    mlx_loop(map->mlx);
}