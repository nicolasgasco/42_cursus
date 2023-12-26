NAME = ft_libasm

all: $(NAME)

up:
	docker compose up --build -d

exec:
	docker exec -it linux bash

$(NAME):
	@ echo "Compiling ${NAME}..."
	@ nasm -f elf -o first.o first.s
	@ ld -m elf_i386 -s -o $(NAME) first.o