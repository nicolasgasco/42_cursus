# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct  board {
    int     width;
    int     height;
    char    empty;
    char    shape;
    int     x1;
    int     x2;
    int     y1;
    int     y2;
    int     radius;
};

void ft_print_struct(struct board board)
{
	printf("First line:\n");
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
			if ((y == board.x1 && x == board.x2) || (y == board.y1 && x == board.y2))
				write(1, &board.shape, 1);
			else
				write(1, &board.empty, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void ft_scan_line(struct board *board, FILE *file)
{
	int width;
	int height;
	char empty;

	fscanf(file, "%d %d %c", &width, &height, &empty);
	board->width = width;
	board->height = height;
	board->empty = empty;
}

void	ft_scan_shape(struct board *board, FILE *file)
{
	int width;
	int height;
	char empty;

	fscanf(file, "%d %d %c", &width, &height, &empty);
	board->width = width;
	board->height = height;
	board->empty = empty;
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
	ft_scan_shape(&board, file);

	ft_print_struct(board);
	// ft_draw_board(board);
	fclose(file);
	return (0);
}