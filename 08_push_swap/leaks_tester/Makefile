NAME = leaks_tester

SRCS=$(wildcard *.c)

FLAGS = -Wall -Wextra -Werror

$(NAME):
	@ gcc $(SRCS) -o leaks_tester
	@echo "Compiling leaks_tester..."

all : $(NAME)

clean :
	@ rm -rf $(wildcard *.o)
	@ echo "Deleting .o..."

fclean : clean
	@ rm -rf $(NAME)
	@ echo "Deleting program..."

re : fclean all

.PHONY : all clean fclean re