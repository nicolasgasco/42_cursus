
NAME = so_long

SRCS = $(wildcard *.c)

FLAGS = # -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME):
	@ echo "Compiling $(NAME)..."
	@ gcc $(FLAGS) $(SRCS) -I . -L minilibx -lmlx_Linux -lXext -lX11 -ggdb -o $(NAME)

all : $(NAME)

clean :
	@ echo "Cleaning bins..."
	@ rm -rf $(OBJS)

fclean : clean
	@ echo "Cleaning all..."
	@ rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re