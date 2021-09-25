#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook (%d)!\n", keycode);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook (%d)!\n", keycode);
}

int	hook(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	// mlx_key_hook(vars.win, key_hook, &vars);
    mlx_mouse_hook(vars.mlx, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
