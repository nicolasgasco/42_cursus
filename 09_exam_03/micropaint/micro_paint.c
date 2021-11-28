#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

struct board
{
	int		width;
	int		height;
	char	empty;
	char	**tab;
	int		error;
};

void ft_print_tab(struct board *board)
{
	int x;
	int y;

	y = 0;
	while (board->tab[y] != NULL)
	{
		x = 0;
		while (board->tab[y][x] != '\0')
		{
			printf("%c", board->tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void ft_print_struct(struct board board)
{
	printf("First line:\n");
	printf("Board.width is %d\n", board.width);
	printf("Board.height is %d\n", board.height);
	printf("Board.empty is %c\n", board.empty);
	// ft_print_tab(&board);
}

void ft_draw_board(struct board *board)
{
	int x;
	int y;

	board->tab = malloc(sizeof(char **) * (board->height + 1));
	y = 0;
	while (y < board->height)
	{
		x = 0;
		board->tab[y] = malloc((sizeof(char)) * board->height + 1);
		while (x < board->width)
		{
			board->tab[y][x] = board->empty;
			x++;
		}
		board->tab[y][x] = '\0';
		y++;
	}
	board->tab[y] = NULL;
}

void ft_scan_line(struct board *board, FILE *file)
{
	int width;
	int height;
	char empty;

	fscanf(file, "%d %d %c\n", &width, &height, &empty);
	board->width = width;
	board->height = height;
	board->empty = empty;
}

void ft_draw_shape(struct board *board, int y_coord, int x_coord, int width, int height, char stroke, char shape)
{
	int y = 0;
	while (board->tab[y] != NULL)
	{
		int x = 0;
		while (board->tab[y][x] != '\0')
		{
			if (y == y_coord && (x >= x_coord && x <= (x_coord + width)))
				board->tab[y][x] = stroke;
			else if (y == (y_coord + height) && (x >= x_coord && x <= (x_coord + width)))
				board->tab[y][x] = stroke;
			else if ((y >= y_coord && y <= y_coord + height) && x == x_coord)
				board->tab[y][x] = stroke;
			else if ((y >= y_coord && y <= y_coord + height) && (x == (x_coord + width)))
				board->tab[y][x] = stroke;
			if (shape == 'R')
			{
				if ((y >= y_coord && y <= (y_coord + height)) && (x >= x_coord && x <= x_coord + width))
					board->tab[y][x] = stroke;
			}
			x++;
		}
		y++;
	}
}

int ft_scan_shape(struct board *board, FILE *file)
{
	char shape;
	float x_coord;
	float y_coord;
	float width;
	float height;
	char stroke;
	int result;

	result = fscanf(file, "%c %f %f %f %f %c\n", &shape, &x_coord, &y_coord, &width, &height, &stroke);
	if (result == -1)
		return result;
	if (result < 6)
	{
		board->error = 1;
		return result;
	}
	ft_draw_shape(board, (int)y_coord + 1, (int)x_coord + 1, (int)width - 1, (int)height - 1, stroke, shape);
	return result;
}
int main(int argc, char *argv[])
{
	struct board board;
	FILE *file;
	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	ft_scan_line(&board, file);
	if (board.width > 300 || board.height > 300)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (board.empty == 'r' || board.empty == 'R')
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	ft_draw_board(&board);
	while (ft_scan_shape(&board, file) != -1)
	{
		if (board.error == 1)
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return (1);	
		}
	}
	ft_print_tab(&board);
	// ft_print_struct(board);
	fclose(file);
	return (0);
}