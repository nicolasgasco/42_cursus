NAME = ft_libasm.a

SRCS = 	ft_strlen.s \
		ft_strcpy.s

OBJS = $(SRCS:.c=.o)

OS = $(shell uname)


all: $(NAME)

$(NAME):
	@ echo "Compiling ${NAME}..."
	@ echo "Creating library"
ifeq (${OS}, Darwin)
	@ echo "🍏 Intel Mac detected (42Urduliz campus)"
	@ nasm -f macho64 ft_strlen.s -o ft_strlen.o
	@ nasm -f macho64 ft_strcpy.s -o ft_strcpy.o
else
	@ echo "Other OS detected (Codespaces)"
	@ sh scripts/remove_underscore.sh
	@ echo "Removing underscore from function names"
	@ nasm -f elf64 ft_strlen.s -o ft_strlen.o
	@ nasm -f elf64 ft_strcpy.s -o ft_strcpy.o
endif
	@ ar rcs $(NAME) *.o
	@ echo "Compiling test file"
ifeq (${OS}, Darwin)
	@ gcc -arch x86_64 main.c ${NAME} -o test
else
	@ gcc main.c ${NAME} -o test
	@ sh scripts/add_underscore.sh
	@ echo "Re-adding underscore to function names"
endif

# %.o: %.s
# ifeq (${OS}, Darwin)
# 	@ echo "🍏 Intel Mac detected (42Urduliz campus)"
# 	@ nasm -f macho64 $< -o $@
# else
# 	@ echo "Other OS detected (Codespaces)"
# 	@ nasm -f elf64 $< -o $@
# endif

clean:
	@ echo "Cleaning up object files"
	@ rm -rf first.o

fclean: clean
	@ echo "Cleaning up executable"
	@ rm -rf ${NAME}

re: fclean all