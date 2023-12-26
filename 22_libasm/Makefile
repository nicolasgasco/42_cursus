NAME = ft_libasm

all: $(NAME)

up:
	docker compose up --build -d

exec:
	docker exec -it linux bash

$(NAME):
	@ echo "Compiling ${NAME}..."
	@ nasm -f elf64 -o first.o first.s
	@ echo "Creating executable..."
	@ ld -o $(NAME) first.o

clean:
	@ echo "Cleaning up files"
	@ rm -rf ${NAME}
	@ rm -rf first.o

re: clean all