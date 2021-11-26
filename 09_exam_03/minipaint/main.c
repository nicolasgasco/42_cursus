#include "minipaint.h"

void ft_print_struct(struct board board)
{
    printf("Board.width is %d\n", board.width);
    printf("Board.height is %d\n", board.height);
    printf("Board.empty is %c\n", board.empty);
    printf("Board.shape is %c\n", board.shape);
	printf("X1 is %d\n", board.x1);
	printf("X2 is %d\n", board.x2);
	printf("Y1 is %d\n", board.y1);
	printf("Y2 is %d\n", board.y2);
	printf("Radius is %d\n", board.radius);
}

void ft_draw_board(struct board board)
{
	int x;
	int y;

	y = 0;
	while (y < board.height)
	{
		x = 0;
		while (x < board.width)
		{
			write(1, &board.empty, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
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
	board.width = 0;
	board.height = 0;
	int		i;
	int		size;
	char	character;
	float	coordinate;
	i = 0;
	while (i < 2)
	{
		fscanf(file, "%d", &size);
		if (board.width != 0)
			board.height = size;
		else
			board.width = size;
		i++;
	}
	i = 0;
	board.empty = 0;
	while (i < 2)
	{
		fscanf(file, "%s", &character);
		if (board.empty == 0)
			board.empty = character;
		else
			board.shape = character;
		i++;
	}
	i = 0;
	board.x1 = 0;
	while (i < 2)
	{
		fscanf(file, "%f", &coordinate);
		printf("Size is %f\n", coordinate);
		if (board.x1 == 0)
		{
			board.x1 = (int)coordinate;
			board.x2 = (int)(coordinate * 10) % 10;
		}
		else
		{
			board.y1 = (int)coordinate;
			board.y2 = (int)(coordinate * 10) % 10;
		}
		i++;
	}
	fscanf(file, "%d", &size);
	board.radius = size;

	ft_print_struct(board);
	ft_draw_board(board);
	fclose(file);
	return (0);
}