NAME = philo_bonus

SRCS = 	philo_bonus.c \
		philo_actions_bonus.c \
		philo_errors_bonus.c \
		philo_free_bonus.c \
		philo_init_bonus.c \
		philo_libft_bonus.c \
		philo_status_bonus.c \
		philo_procs_bonus.c \
		philo_time_bonus.c \

FLAGS 	= -Wall -Wextra -Werror
OBJS    = $(SRCS:.c=.o)

all :
	@ $(MAKE) -s $(NAME)
	@ echo "Compiled..."

$(NAME): $(OBJS)
	@ echo "Compiling philosophers..."
	@ $(CC) ${FLAGS} $(OBJS) -lpthread -o $(NAME)

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

fclean :
	@ echo "Cleaning objects and program..."
	@ rm -rf *.dSYM
	@ rm -rf $(OBJS)
	@ rm -rf $(NAME)
	@ echo "Cleaned"

clean :
	@ echo "Cleaning objects..."
	@ rm -rf *.dSYM
	@ rm -rf $(OBJS)
	@ echo "Cleaned"

re : fclean all

.PHONY : all clean fclean re