NAME = libftprintf.a

SRCS =  ft_printf.c \
		ft_printf_utils.c

FLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY:		all clean fclean re
