#include "minipaint.h"

void ft_print_struct(struct board board)
{
	printf("Board.width is %d\n", board.width);
	printf("Board.height is %d\n", board.height);
	printf("Board.empty is %c\n", board.empty);
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
	int size;
	char empty;
	while (fscanf(file, "%d", &size) == 1)
	{
		if (board.width)
			board.height = size;
		else
			board.width = size;
	}
	while (fscanf(file, "%s", &empty) == 1)
	{
		printf("Empty is %c\n", empty);
	}

	// ft_print_struct(board);
	ft_draw_board(board);
	fclose(file);
	return (0);
}