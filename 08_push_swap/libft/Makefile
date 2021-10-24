NAME    = libft.a

SRCS    = $(wildcard *.c)

OBJS    = $(SRCS:.c=.o)

LIBC    = ar -rcs
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror
INCS    = libft.h

$(NAME): $(OBJS) $(INCLUDE)
	@ $(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re .c .o
