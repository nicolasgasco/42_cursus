NAME = philo

BONUS = philo_bonus

SRCS = $(wildcard *.c)

SRCS_BONUS = $(wildcard ../philo_bonus/*)

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

SANITIZER =  -fsanitize=address -static-libsan -g
# SANITIZER =  -fsanitize=thread -static-libsan -g

$(NAME): $(OBJS)
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

.PHONY : all clean fclean re bonus
