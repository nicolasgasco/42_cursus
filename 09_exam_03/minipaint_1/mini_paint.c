#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>

char **tab;

// Board line
int board_width = 0;
int board_height = 0;
char empty = '0';

// Shape line
char shape;
float x_coord;
float y_coord;
float radius;
char stroke;

void ft_print_tab()
{
	int x;
	int y;

	y = 0;
	while (tab[y] != NULL)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			write(1, &tab[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void ft_draw_board()
{
	int x;
	int y;

	tab = malloc((sizeof(char *) * board_height) + 1);
	y = 0;
	while (y < board_height)
	{
		x = 0;
		tab[y] = malloc((sizeof(char)) * board_width + 1);
		while (x < board_width)
		{
			tab[y][x] = empty;
			x++;
		}
		tab[y][x] = '\0';
		y++;
	}
	tab[y] = NULL;
}

void ft_draw_shape()
{
	int y = 0;
	float distance;

	while (tab[y] != NULL)
	{
		int x = 0;
		while (tab[y][x] != '\0')
		{
			distance = sqrtf(powf((float)x - x_coord, 2) + powf((float)y - y_coord, 2));
			if (distance <= radius)
			{
				if (shape == 'C')
					tab[y][x] = stroke;
				else
				{
					if (radius - distance < 1)
						tab[y][x] = stroke;
				}
			}
			x++;
		}
		y++;
	}
}

int ft_scan_line(FILE *file)
{
	int result;

	result = fscanf(file, "%d %d %c\n", &board_width, &board_height, &empty);
	return result;
}

int ft_scan_shape(FILE *file)
{
	int result;

	result = fscanf(file, "%c %f %f %f %c\n", &shape, &x_coord, &y_coord, &radius, &stroke);
	return result;
}

void ft_free_tab()
{
	int	y;

	y = 0;
	while (tab[y] != NULL)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
}

int main(int argc, char *argv[])
{
	FILE *file;
	int shape_res;

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
	if (ft_scan_line(file) != 3 || board_width > 300 || board_height > 300 || board_width <= 0 || board_height <= 0)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		fclose(file);
		return (1);
	}
	ft_draw_board();
	while (1)
	{
		shape_res = ft_scan_shape(file);
		if (shape_res == 5)
		{
			if (radius <= 0 || (shape != 'C' && shape != 'c'))
			{
				ft_free_tab();
				write(1, "Error: Operation file corrupted\n", 32);
				fclose(file);
				return (1);
			}
			ft_draw_shape();
		}
		else if (shape_res == -1)
			break;
		else
		{
			ft_free_tab();
			write(1, "Error: Operation file corrupted\n", 32);
			fclose(file);
			return (1);
		}
	}
	ft_print_tab();
	ft_free_tab();
	fclose(file);
	return (0);
}