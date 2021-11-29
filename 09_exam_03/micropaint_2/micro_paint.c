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
float	s_x;
float	s_y;
float	w;
float	h;
char	stroke;


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

void	ft_print_board()
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
	int y, x;
	char	**result;

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

void	ft_draw_shape()
{
	int y, x;

	y = 0;
	while (board[y] != NULL)
	{
		x = 0;
		while (board[y][x] != '\0')
		{
			if ((float)x < s_x || (float)y < s_y || (float)y > (s_y + h) || (float)x > (s_x + w))
			{
					// Continue
			}
			else
			{
				if ((float)x - s_x < 1 || (float)y - s_y < 1 || (s_x + w) - (float)x < 1 || (s_y + h) - (float)y < 1)
				{
					board[y][x] = stroke;
				}
				else
				{
					if (shape == 'R')
						board[y][x] = stroke;
				}
			}
			x++;
		}
		y++;
	}
}

int	ft_scan_board(FILE *file)
{
	return fscanf(file, "%d %d %c\n", &b_w, &b_h, &empty);	
}

int ft_scan_shape(FILE *file)
{
	return fscanf(file, "%c %f %f %f %f %c\n", &shape, &s_x, &s_y, &w, &h, &stroke);
}

int	main(int argc, char *argv[])
{
	int	shape_res;

	if (argc != 2)
		write(1, "Error: argument\n", 16);	
	FILE	*file;
	if (!(file = fopen(argv[1], "r")))
	{				
		write(1, "Error: Operation file corrupted\n", 32);	
		return (1);
	}
	if (ft_scan_board(file) != 3 || b_w > 300 || b_h > 300 || b_w <= 0 || b_h <= 0)
	{	
		write(1, "Error: Operation file corrupted\n", 32);	
		fclose(file);
		return (1);
	}
	board =	ft_create_board();
	while (1)
	{
		shape_res = ft_scan_shape(file);
		if (shape_res == -1)
			break;
		else if (shape_res == 6)
		{
			if (w <= 0 || h <= 0 || (shape != 'r' && shape != 'R'))
			{		
				write(1, "Error: Operation file corrupted\n", 32);	
				ft_free_board();
				fclose(file);
				return (1);
			}
			else
			{
				ft_draw_shape(file);
			}
		}
		else
		{
			write(1, "Error: Operation file corrupted\n", 32);	
			ft_free_board();
			fclose(file);
			return (1);
		}
	}
	ft_print_board();
	ft_free_board();
	fclose(file);
	return (0);
}

