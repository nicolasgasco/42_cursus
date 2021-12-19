NAME = philo

BONUS = philo_bonus

SRCS = $(wildcard *.c)

SRCS_BONUS = $(wildcard bonus/*)

FLAGS = -Wall -Wextra -Werror

SANITIZER =  -fsanitize=address -static-libasan -g
# SANITIZER =  -fsanitize=thread -static-libsan -g

$(NAME):
	@ gcc $(FLAGS) $(SRCS) -lpthread -o $(NAME)
	@ echo "Compiling philosophers..."

bonus:
	@ gcc $(FLAGS) $(SRCS_BONUS) -lpthread -o $(BONUS)
	@ echo "Compiling bonus..."

all : $(NAME)

clean :
	@ rm -rf $(wildcard *.o)
	@ echo "Deleting .o..."

fclean : clean
	@ rm -rf $(NAME)
	@ echo "Deleting program..."

re : fclean all

.PHONY : all clean fclean re bonus
