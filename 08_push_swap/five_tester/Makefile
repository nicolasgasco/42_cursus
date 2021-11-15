NAME = five_tester

SRCS=$(wildcard *.c)

FLAGS = -Wall -Wextra -Werror

$(NAME):
	@ gcc $(SRCS) -o five_tester
	@echo "Compiling five_tester..."

all : $(NAME)

clean :
	@ rm -rf $(wildcard *.o)
	@ echo "Deleting .o..."

fclean : clean
	@ rm -rf $(NAME)
	@ echo "Deleting program..."

re : fclean all

.PHONY : all clean fclean re