#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


int	ft_keyboard_events(int keycode, t_vars *vars)
{
    printf("Keycode %d\n", keycode);
    if (keycode == 97)
    {
        printf("You pressed A\n");
    }
    else if (keycode == 119)
    {
        printf("You pressed W\n");
    }
    else if (keycode == 100)
    {
        printf("You press D\n");
    }
    else if (keycode == 115)
    {
        printf("You pressed S\n");
    }
    else if (keycode == 65307)
    {
        printf("You pressed Esc\n");
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
}

int ft_window_events(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}

int	events(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 02, (1L<<0), ft_keyboard_events, &vars);
    // Closing when pressing red cross
    mlx_hook(vars.win, 17, (1L<<8), ft_window_events, &vars);
	mlx_loop(vars.mlx);
}