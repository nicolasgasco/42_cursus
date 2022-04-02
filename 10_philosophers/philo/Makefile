NAME = philo

SRCS = 	philo_actions.c \
		philo_errors.c \
		philo_free.c \
		philo_init.c \
		philo_libft.c \
		philo_status.c \
		philo_threads.c \
		philo_time.c \
		philo.c \

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
