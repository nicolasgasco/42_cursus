NAME = account
CC = c++
STD = -std=c++98 -pedantic
FLAGS = -Wall -Wextra -Werror
SANITIZE = -g -fsanitize=address

SRC_NAME =	Account.cpp \
			tests.cpp \

INCLUDES = Account.hpp \

OBJ_NAME = $(SRC_NAME:.cpp=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(STD) $(FLAGS) $(SANITIZE) -o $(NAME) $(OBJ)
	@echo "Compilation done."

$(OBJ_DIR)%.o: %.cpp $(INCLUDES)
	$(CC) $(STD) $(FLAGS) $(SANITIZE) -c $< -I. -o $@

clean:
	@rm -f $(OBJ)
	@echo "Removed object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Removed binary files"

re: fclean all

.PHONY: all clean fclean re
