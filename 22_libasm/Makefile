NAME = ft_libasm.a
EXECUTABLE = test
FLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJS_DIR = objs

SANITIZE= -fsanitize=address -g3 -fno-omit-frame-pointer
OS = $(shell uname)


all: $(NAME)

$(NAME):
	@ mkdir -p ${OBJS_DIR}
ifeq (${OS}, Darwin)
	@ echo "🍏 Intel Mac detected (42Urduliz campus)"
	@ sh scripts/linux_to_macos.sh
	@ echo "Adapting function names to MacOs format"
	@ rm -rf src/*.s-e
	@ nasm -f macho64 ${SRC_DIR}/ft_strlen.s -o ${OBJS_DIR}/ft_strlen.o
	@ nasm -f macho64 ${SRC_DIR}/ft_strcpy.s -o ${OBJS_DIR}/ft_strcpy.o
	@ nasm -f macho64 ${SRC_DIR}/ft_strcmp.s -o ${OBJS_DIR}/ft_strcmp.o
	@ nasm -f macho64 ${SRC_DIR}/ft_write.s -o ${OBJS_DIR}/ft_write.o
	@ nasm -f macho64 ${SRC_DIR}/ft_read.s -o ${OBJS_DIR}/ft_read.o
	@ nasm -f macho64 ${SRC_DIR}/ft_strdup.s -o ${OBJS_DIR}/ft_strdup.o
else
	@ echo "🐧 Other OS detected (42Urduliz campus after migration to Linux)"
	@ nasm -f elf64 ${SRC_DIR}/ft_strlen.s -o ${OBJS_DIR}/ft_strlen.o
	@ nasm -f elf64 ${SRC_DIR}/ft_strcpy.s -o ${OBJS_DIR}/ft_strcpy.o
	@ nasm -f elf64 ${SRC_DIR}/ft_strcmp.s -o ${OBJS_DIR}/ft_strcmp.o
	@ nasm -f elf64 ${SRC_DIR}/ft_write.s -o ${OBJS_DIR}/ft_write.o
	@ nasm -f elf64 ${SRC_DIR}/ft_read.s -o ${OBJS_DIR}/ft_read.o
	@ nasm -f elf64 ${SRC_DIR}/ft_strdup.s -o ${OBJS_DIR}/ft_strdup.o
endif
	@ echo "Compiling ${NAME} library"
	@ ar rcs $(NAME) ${OBJS_DIR}/*.o

ifeq (${OS}, Darwin)
	gcc -arch x86_64 ${FLAGS} ${SANITIZE} main.c ${NAME} -o ${EXECUTABLE}
	@ sh scripts/macos_to_linux.sh
	@ echo "Bringing back function names to Linux format"
else
	gcc main.c ${FLAGS} ${SANITIZE} ${NAME} -o test
endif
	@ echo "Creating test_files directory"
	@ mkdir -p test_files


clean:
	@ echo "Cleaning up object files"
	@ rm -rf ${OBJS_DIR}
	@ echo "Cleaning up test files"
	@ rm -rf test_files
	@ echo "Cleaning up library"
	@ rm -rf ${NAME}
	@ echo "Cleaning up test_files directory"
	@ rm -rf test_files

fclean: clean
	@ echo "Cleaning up executable"
	@ rm -rf ${EXECUTABLE}

re: fclean all