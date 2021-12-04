NAME = philo

SRCS=$(wildcard *.c)

# FLAGS = -Wall -Wextra -Werror

$(NAME):
	@ gcc $(FLAGS) $(SRCS) -lpthread -o $(NAME)
	@ echo "Compiling philosophers..."

all : $(NAME)

clean :
	@ rm -rf $(wildcard *.o)
	@ echo "Deleting .o..."

fclean : clean
	@ rm -rf $(NAME)
	@ echo "Deleting program..."

re : fclean all

.PHONY : all clean fclean re