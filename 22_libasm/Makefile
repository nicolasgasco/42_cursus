NAME = ft_libasm.a

SRCS = ft_strlen.s

OBJS = $(SRCS:.c=.o)

all: $(NAME)

up:
	docker compose up --build -d

exec:
	docker exec -it linux bash

$(NAME):
	@ echo "Compiling ${NAME}..."
	@ nasm -f elf64 ${SRCS}
	@ echo "Creating library file"
	@ ar -rcs $(NAME) ft_strlen.o
	@ echo "Compiling test file"
	@ gcc -Wall -Wextra -Werror main.c ${NAME} -o test

clean:
	@ echo "Cleaning up object files"
	@ rm -rf first.o

fclean: clean
	@ echo "Cleaning up executable"
	@ rm -rf ${NAME}

re: fclean all