#include "so_long.h"

void	ft_render_rocks(t_map *map, int offset, int index)
{
    if ((index + 1) % 5 == 0)
        ft_render_tile(map, "./img/rock_3.xpm", offset);
    else if ((index + 1) % 3 == 0)
        ft_render_tile(map, "./img/rock_2.xpm", offset);
    else
        ft_render_tile(map, "./img/rock_1.xpm", offset);
}

void	ft_render_player(t_map *map, int offset)
{
	if (map->end_game == 0)
		ft_render_tile(map, "./img/player.xpm", offset);
	else
		ft_render_tile(map, "./img/success.xpm", offset);
	map->p_x = map->x;
	map->p_y = map->y;
}

void	ft_render_exit(t_map *map, int offset, int start)
{
	if (start == 0 && map->n_collect == 0)
		ft_render_tile(map, "./img/exit.xpm", offset);
	else
		ft_render_tile(map, "./img/exit_closed.xpm", offset);
}

void    ft_render_collectible(t_map *map, int offset, int start)
{
    if (start == 1)
        map->n_collect++;
    ft_render_tile(map, "./img/star.xpm", offset);

}