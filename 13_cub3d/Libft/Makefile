SRCS =	ft_strlen.c		\
        ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c  \
		ft_strncmp.c    \
		ft_substr.c     \
		ft_strtrim.c    \
		ft_strlcpy.c    \
		ft_strchr.c     \
		ft_atoi.c 		\
		ft_isdigit.c    \
		ft_memset.c     \
		ft_strdup.c     \
		ft_strjoin.c    \
		ft_itoa.c       \
		ft_isalpha.c    \
		
NAME = libft.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

OBJSB = $(SRCSB:.c=.o)
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJSB))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror -Wno-parentheses

$(OBJS_DIR)%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_PREFIXED)
	@echo "Libft Done !"

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS_BONUS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_BONUS_PREFIXED)
	@echo "Libft Bonus Done !"
