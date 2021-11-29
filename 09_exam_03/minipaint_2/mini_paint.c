#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include  <math.h>

// Board
int		b_w;
int		b_h;
char	empty;
char	**board;

// Shape
char	shape;
float	s_x;
float	s_y;
float	radius;
char	stroke;

void	ft_draw_board()
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

char	**ft_create_board()
{
	int	y, x;
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
	return result;
}

int	ft_scan_shape(FILE *file)
{
	return fscanf(file, "%c %f %f %f %c\n", &shape, &s_x, &s_y, &radius, &stroke);
}

int	ft_scan_board(FILE *file)
{
	return fscanf(file, "%d %d %c\n", &b_w, &b_h, &empty);
}

void	ft_draw_shape()
{
	int	y, x;
	float	distance;
	y = 0;
	while (board[y] != NULL)
	{
		x = 0;
		while (board[y][x] != '\0')
		{
			distance = sqrt(powf((float)x - s_x, 2) + powf((float)y - s_y, 2));
			if (distance <= radius)
			{
				if (shape == 'C')
					board[y][x] = stroke;
				else
				{
					if (radius - distance < 1)
						board[y][x] = stroke;
				}
			}
			x++;
		}
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

int	main(int argc, char *argv[])
{
	int	shape_res;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	FILE	*file;

	if (!(file = fopen(argv[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (ft_scan_board(file) != 3 || b_w > 300 || b_h > 300 || b_w <= 0 || b_h <= 0)
	{			
		fclose(file);
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	board = ft_create_board();
	while (1)
	{
		shape_res = ft_scan_shape(file);
		if (shape_res == -1)
			break;
		else if (shape_res == 5 && radius > 0 && (shape == 'c' || shape == 'C'))
		{
			ft_draw_shape();
		}
		else
		{
			ft_free_board();
			write(1, "Error: Operation file corrupted\n", 32);	
			fclose(file);
			return (1);
		}
	}
	ft_draw_board();
	ft_free_board();
	fclose(file);
	return (0);
}
