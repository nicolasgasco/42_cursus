NAME = ft_libasm.a

SRCS = 	ft_strlen.s \
		ft_strcpy.s

OBJS = $(SRCS:.c=.o)

all: $(NAME)

up:
	docker compose up --build -d

exec:
	docker exec -it linux bash

$(NAME):
	@ echo "Compiling ${NAME}..."
	@ nasm -f elf64 ft_strlen.s
	@ nasm -f elf64 ft_strcpy.s
	@ echo "Creating library file"
	@ ar -rcs $(NAME) ft_strlen.o ft_strcpy.o
	@ echo "Compiling test file"
	@ gcc main.c ${NAME} -o test

clean:
	@ echo "Cleaning up object files"
	@ rm -rf first.o

fclean: clean
	@ echo "Cleaning up executable"
	@ rm -rf ${NAME}

re: fclean all