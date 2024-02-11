NAME = ft_libasm.a
EXECUTABLE = test
FLAGS = -Wall -Wextra -Werror

SRCS = 	ft_strlen.s \
		ft_strcpy.s

SRC_DIR = src
OBJS_DIR = objs
OBJS = $(SRCS:.c=.o)

OS = $(shell uname)


all: $(NAME)

$(NAME):
	@ echo "Compiling ${NAME}..."
	@ echo "Creating library"
	@ mkdir -p ${OBJS_DIR}
ifeq (${OS}, Darwin)
	@ echo "🍏 Intel Mac detected (42Urduliz campus)"
	@ nasm -f macho64 ${SRC_DIR}/ft_strlen.s -o ${OBJS_DIR}/ft_strlen.o
	@ nasm -f macho64 ${SRC_DIR}/ft_strcpy.s -o ${OBJS_DIR}/ft_strcpy.o
	@ nasm -f macho64 ${SRC_DIR}/ft_strcmp.s -o ${OBJS_DIR}/ft_strcmp.o
	@ nasm -f macho64 ${SRC_DIR}/ft_write.s -o ${OBJS_DIR}/ft_write.o
	@ nasm -f macho64 ${SRC_DIR}/ft_read.s -o ${OBJS_DIR}/ft_read.o
	@ nasm -f macho64 ${SRC_DIR}/ft_strdup.s -o ${OBJS_DIR}/ft_strdup.o
else
	@ echo "Other OS detected (Codespaces)"
	@ sh scripts/remove_underscore.sh
	@ echo "Removing underscore from function names"
	@ nasm -f elf64 ${SRC_DIR}/ft_strlen.s -o ${OBJS_DIR}/ft_strlen.o
	@ nasm -f elf64 ${SRC_DIR}/ft_strcpy.s -o ${OBJS_DIR}/ft_strcpy.o
	@ nasm -f elf64 ${SRC_DIR}/ft_strcmp.s -o ${OBJS_DIR}/ft_strcmp.o
	@ nasm -f elf64 ${SRC_DIR}/ft_write.s -o ${OBJS_DIR}/ft_write.o
	@ nasm -f elf64 ${SRC_DIR}/ft_read.s -o ${OBJS_DIR}/ft_read.o
	@ nasm -f elf64 ${SRC_DIR}/ft_strdup.s -o ${OBJS_DIR}/ft_strdup.o
endif
	@ ar rcs $(NAME) ${OBJS_DIR}/*.o
	@ echo "Compiling test file"
ifeq (${OS}, Darwin)
	@ gcc -arch x86_64 ${FLAGS} main.c ${NAME} -o ${EXECUTABLE}
else
	@ gcc main.c ${FLAGS} ${NAME} -o test
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
	@ rm -rf ${OBJS_DIR}
	@ echo "Cleaning up test files"
	@ rm -rf test_files
	@ echo "Cleaning up library"
	@ rm -rf ${NAME}

fclean: clean
	@ echo "Cleaning up executable"
	@ rm -rf ${EXECUTABLE}

re: fclean all