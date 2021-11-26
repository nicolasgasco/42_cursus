#include "minipaint.h"

void ft_print_struct(struct board board)
{
    printf("Board.width is %d\n", board.width);
    printf("Board.height is %d\n", board.height);
    printf("Board.empty is %c\n", board.empty);
}