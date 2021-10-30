NAME = push_swap

SRCS=$(wildcard *.c)

FLAGS = -Wall -Wextra -Werror

$(NAME):
	@ cd libft && make libft.a && make clean
	@ echo "Compiling libft..."
	@ gcc $(FLAGS) $(SRCS) libft/libft.a -o push_swap
	@ echo "Compiling push_swap..."

all : $(NAME)

clean :
	@ rm -rf $(OBJS)
	@ echo "Deleting .o..."

fclean : clean
	@ rm -rf $(NAME)
	@ echo "Deleting program..."

re : fclean all

.PHONY : all clean fclean re