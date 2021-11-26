#ifndef MINIPAINT_H
# define MINIPAINT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct  board {
    int     width;
    int     height;
    char    empty;
};

void ft_print_struct(struct board board);

# endif