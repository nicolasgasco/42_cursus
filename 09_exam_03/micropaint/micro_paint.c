#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

char **tab;

// Board line
int board_width = 0;
int board_height = 0;
char empty = '0';

// Shape line
char shape;
float x_coord;
float y_coord;
float width;
float height;
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
			printf("%c", tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void ft_print_struct()
{
	printf("First line:\n");
	printf("width is %d\n", width);
	printf("height is %d\n", height);
	printf("empty is %c\n", empty);
	// ft_print_tab(&;
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
	And a rectangle with a top left corner (Xtl, Ytl) and a bottom right corner (Xbr, Ybr)
If Xtl <= Xa <= Xbr and Ytl <= Ya <= Ybr then the point is in the rectangle

	int y = 0;

	while (tab[y] != NULL)
	{
		int x = 0;
		while (tab[y][x] != '\0')
		{
			if (
			x++;
		}
		y++;
	}
}

int ft_round_float(float n)
{
	n *= 10.00;
	if ((int)n % 10 > 5)
		n++;
	return (int)n / 10;
}

void ft_scan_line(FILE *file)
{
	fscanf(file, "%d %d %c\n", &board_width, &board_height, &empty);
}

int ft_scan_shape(FILE *file)
{
	int result;

	return fscanf(file, "%c %f %f %f %f %c\n", &shape, &x_coord, &y_coord, &width, &height, &stroke);
}

int main(int argc, char *argv[])
{
	FILE *file;
	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	ft_scan_line(file);
	if (width > 300 || height > 300)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	ft_draw_board();
	while (ft_scan_shape(file) == 6)
	{
		if (width <= 0 || height <= 0 || (shape != 'R' && shape != 'r'))
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return (1);
		}
		ft_draw_shape();
	}
	ft_print_tab();
	// ft_print_struct();
	fclose(file);
	return (0);
}