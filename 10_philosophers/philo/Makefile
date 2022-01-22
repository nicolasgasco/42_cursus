NAME = philo

BONUS = philo_bonus

SRCS = $(wildcard *.c)

SRCS_BONUS = $(wildcard ../philo_bonus/*)

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@ gcc $(FLAGS) $(OBJS) -lpthread -o $(NAME)
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
