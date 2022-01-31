BONUS = philo_bonus

SRCS = $(wildcard *.c)

FLAGS = -Wall -Wextra -Werror

$(BONUS):
	@ gcc $(FLAGS) $(SRCS) -lpthread -o $(BONUS)
	@ echo "Compiling Philosophers - Bonus..."

all : $(BONUS)

clean :
	@ rm -rf $(wildcard *.o)
	@ echo "Deleting .o..."

fclean : clean
	@ rm -rf $(BONUS)
	@ echo "Deleting program..."

re : fclean all

.PHONY : all clean fclean re bonus
