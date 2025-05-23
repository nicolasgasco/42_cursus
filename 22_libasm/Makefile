NAME = ft_libasm.a
EXECUTABLE = test
FLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJS_DIR = objs

SANITIZE=# -fsanitize=address -g3 -fno-omit-frame-pointer


all: $(NAME)

$(NAME):
	@ mkdir -p ${OBJS_DIR}
	@ nasm -f elf64 ${SRC_DIR}/ft_strlen.s -o ${OBJS_DIR}/ft_strlen.o
	@ nasm -f elf64 ${SRC_DIR}/ft_strcpy.s -o ${OBJS_DIR}/ft_strcpy.o
	@ nasm -f elf64 ${SRC_DIR}/ft_strcmp.s -o ${OBJS_DIR}/ft_strcmp.o
	@ nasm -f elf64 ${SRC_DIR}/ft_write.s -o ${OBJS_DIR}/ft_write.o
	@ nasm -f elf64 ${SRC_DIR}/ft_read.s -o ${OBJS_DIR}/ft_read.o
	@ nasm -f elf64 ${SRC_DIR}/ft_strdup.s -o ${OBJS_DIR}/ft_strdup.o
	@ echo "Compiling ${NAME} library"
	@ ar rcs $(NAME) ${OBJS_DIR}/*.o

	gcc main.c ${FLAGS} ${SANITIZE} -L. -lasm -o ${EXECUTABLE}

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