NAME = phonebook
CC = c++
STD = -std=c++98 -pedantic
FLAGS = -Wall -Wextra -Werror
SANITIZE = -g -fsanitize=address

SRC_NAME =	Contact.cpp \
			PhoneBook.cpp \
			main.cpp \

INCLUDES = Contact.class.hpp \
		   PhoneBook.class.hpp \

OBJ_NAME = $(SRC_NAME:.cpp=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(STD) $(FLAGS) -o $(NAME) $(OBJ)
	@echo "##### retro_contacts compiling finished! #####"

$(OBJ_DIR)%.o: %.cpp $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	$(CC) $(STD) $(FLAGS) -c $< -I. -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "##### Removed object files #####"

fclean: clean
	@rm -f $(NAME)
	@echo "##### Removed binary files #####"

re: fclean all

.PHONY: all clean fclean re
