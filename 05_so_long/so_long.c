#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	int	fp;
	char	*line;
	int	i;

	i = 0;
	if (argc < 2)
	{
		perror("Not enough arguments");
		return (-1);
	}
	if (argc > 2)
	{
		perror("Too many arguments");
		return (-1);
	}
	if (argc == 2)
	{
		printf("File is: '%s'\n", argv[1]);
		fp = open(argv[1], O_RDONLY);
		if (fp == -1)
		{
			perror("An error ocurred");
			return (-1);
		} else {
			printf("File opened. Fd is %d.\n", fp);
			ft_validate_map(fp);
			if (close(fp) == 0) {
				printf("File closed successfully.\n");
			} else {
				perror("Error while closing file");
				return(-1);
			}
		}
	}
	return (1);
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	int		i = 50;
// 	int 	y = 50;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	while (i < 500)
// 	{
// 		my_mlx_pixel_put(&img, i, y, 0x00FF0000);
// 		i++;
// 	}
// 	while (y < 250)
// 	{
// 		my_mlx_pixel_put(&img, i, y, 0x00FF0000);
// 		y++;
// 	}
// 	while (i != 50)
// 	{
// 		my_mlx_pixel_put(&img, i, y, 0x00FF0000);
// 		i--;
// 	}
// 	while (i < 250)
// 	{
// 		my_mlx_pixel_put(&img, i, y, 0x00FF0000);
// 		i++;
// 		y--;
// 	}

// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
}