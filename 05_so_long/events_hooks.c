#include "so_long.h"

int ft_close_window(t_map *map)
{
    ft_put_str("So long!\n");
    mlx_destroy_window(map->mlx, map->win);
    exit(0);
}

int    ft_keyboard_events(int keycode, t_map *map)
{
    if (keycode == 97 || keycode == 65361)
    {
        // printf("You pressed Left\n");
        ft_move_player(map, -1, 0);
    }
    else if (keycode == 119 || keycode == 65362)
    {
        // printf("You pressed Up\n");
        ft_move_player(map, 0, -1);
    }
    else if (keycode == 100 || keycode == 65363)
    {
        // printf("You pressed Right\n");
        ft_move_player(map, 1, 0);
    }
    else if (keycode == 115 || keycode == 65364)
    {
        // printf("You pressed Down\n");
        ft_move_player(map, 0, 1);
    }
    else if (keycode == 65307)
    {
        // printf("You pressed Esc\n");
        ft_close_window(map);
    }
    return (1);
}


void    ft_listen_events(t_map *map)
{
    // printf("Listening to keyboard.\n");
	mlx_hook(map->win, 02, (1L<<0), ft_keyboard_events, map);
    // printf("Listening to window buttons\n");
    mlx_hook(map->win, 17, (1L<<8), ft_close_window, map);
}
