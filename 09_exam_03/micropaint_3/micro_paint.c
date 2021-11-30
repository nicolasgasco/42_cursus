#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Board
int		b_w;
int		b_h;
char	empty;
char	**board;


// Shape
char	shape;
float	r_x;
float	r_y;
float	r_w;
float	r_h;
char	stroke;

char		**ft_create_board()
{
	int		y, x;
	char	**result;
	
	y = 0;
	result = malloc(sizeof(char *) * b_h + 1);
	while (y < b_h)
	{
		x = 0;
		result[y] = malloc(sizeof(char) * b_w + 1);
		while (x < b_w)
		{
			result[y][x] = empty;
			x++;
		}
		result[y][x] = '\0';
		y++;
	}
	result[y] = NULL;
	return (result);
}

void	ft_put_board()
{
	int	y, x;

	y = 0;
	while (board[y] != NULL)
	{
		x = 0;
		while (board[y][x] != '\0')
		{
			write(1, &board[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	ft_free_board()
{
	int	y;

	y = 0;
	while (board[y] != NULL)
	{
	 	free(board[y]);
		y++;
	}
	free(board);
}
int	ft_scan_board(FILE *file)
{
	return fscanf(file, "%d %d %c\n", &b_w, &b_h, &empty);
}

int	ft_scan_shape(FILE *file)
{
	return fscanf(file, "%c %f %f %f %f %c\n", &shape, &r_x, &r_y, &r_w, &r_h, &stroke);
}

void	ft_draw_shape()
{
	int	y, x;

	y = 0;
	while (board[y] != NULL)
	{
		x = 0;
		while (board[y][x] != '\0')
		{
			if (x < r_x || y < r_y || x > (r_x + r_w) || y > (r_y + r_h))
			{
				// Continue
			}	
			else
			{
				if (shape == 'R')
					board[y][x] = stroke;
				else
				{
					if (x - r_x < 1 || y - r_y < 1 || (r_y + r_h) - y < 1 || (r_x + r_w) - x < 1)
					{
						board[y][x] = stroke;
					}
				}
			}
			x++;
		}
		y++;
	}
}

int	main(int argc, char *argv[])
{
	FILE	*file;
	int		res_shape;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(file = fopen(argv[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (ft_scan_board(file) != 3 || b_w > 300 || b_h > 300 || b_w <= 0 || b_h <= 0)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
		fclose(file);
	}
	board = ft_create_board();
	while (1)
	{
		res_shape = ft_scan_shape(file);
		if (res_shape == -1)
			break;
		else if (res_shape != 6 || (shape != 'r' && shape != 'R') || r_w <= 0 || r_h <= 0)
		{
			write(1, "Error: Operation file corrupted\n", 32);
			ft_free_board();
			fclose(file);
			return (1);
		}
		else
			ft_draw_shape();
	}	
	ft_put_board();
	ft_free_board();
	fclose(file);
	return (0);
}
