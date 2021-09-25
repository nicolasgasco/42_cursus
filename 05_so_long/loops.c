#include "so_long.h"

int	loops(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_loop(mlx);
}