#ifndef MINIPAINT_H
# define MINIPAINT_H

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

void ft_print_struct(struct board board);

# endif