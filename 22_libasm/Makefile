NAME = ft_libasm.a

SRCS = 	ft_strlen.s \
		ft_strcpy.s

OBJS = $(SRCS:.c=.o)

OS = $(shell uname)


all: $(NAME)

up:
	docker compose up --build -d

exec:
	docker exec -it linux bash

$(NAME):
	@ echo "Compiling ${NAME}..."
ifeq (${OS}, Darwin)
	@ echo "🍏 Intel Mac detected (42Urduliz campus)"
	@ nasm -f macho64 ft_strlen.s -o ft_strlen.o
	@ nasm -f macho64 ft_strcpy.s -o ft_strcpy.o
else
	@ echo "Other OS detected (Codespaces)"
	@ nasm -f elf64 ft_strlen.s -o ft_strlen.o
	@ nasm -f elf64 ft_strcpy.s -o ft_strcpy.o
endif
	@ echo "Creating library"
	@ ar -rcs $(NAME) *.o
	@ echo "Compiling test file"
	@ gcc -arch x86_64 main.c ${NAME} -o test


clean:
	@ echo "Cleaning up object files"
	@ rm -rf first.o

fclean: clean
	@ echo "Cleaning up executable"
	@ rm -rf ${NAME}

re: fclean all