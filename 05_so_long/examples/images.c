#include "so_long.h"

int	images(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./img/tile_water.xpm";
	int		img_width;
	int		img_height;
    void	*win;
    int     i;

    i = 0;
	mlx = mlx_init();
    win = mlx_new_window(mlx, 600, 400, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    while (i <= 600)
    {
        mlx_put_image_to_window (mlx, win, img, i, 0);
        i += img_width;
    }
    printf("%p\n", img);
    mlx_loop(mlx);
}