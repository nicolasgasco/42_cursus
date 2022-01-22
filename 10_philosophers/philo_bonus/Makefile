BONUS = philo_bonus

SRCS = $(wildcard *.c)

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

SANITIZER =  -fsanitize=address -static-libsan -g
# SANITIZER =  -fsanitize=thread -static-libsan -g

$(BONUS): $(OBJS)
	@ $(CC) $(FLAGS) $(SRCS) -lpthread -o $(BONUS)
	@ echo "Compiling Philosophers - Bonus..."

all : $(BONUS)

clean :
	@ rm -rf $(wildcard *.o)
	@ echo "Deleting .o..."

fclean : clean
	@ rm -rf $(NAME)
	@ echo "Deleting program..."

re : fclean all

.PHONY : all clean fclean re bonus
