# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 10:07:55 by ngasco            #+#    #+#              #
#    Updated: 2021/10/04 18:55:58 by ngasco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRCS = $(wildcard src/*.c)

SRCS_BONUS = $(wildcard bonus/*bonus.c)


FLAGS = -Wall -Wextra -Werror

# %.o: %.c
	#  @ $(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	# @ $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@



all : $(SRCS)
	@ echo "Compiling for macOs"
	@ $(CC) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

sanitizer : $(SRCS)
	@ echo "Compiling for macOs"
	@ $(CC) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -fsanitize=address -fno-omit-frame-pointer -o $(NAME)


bonus : $(SRCS_BONUS)
	@ echo "Compiling bonus for macOs"
	@ $(CC) $(SRCS_BONUS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus_sanitizer : $(SRCS_BONUS)
	@ echo "Compiling bonus for macOs"
	@ $(CC) $(SRCS_BONUS) -Lmlx -lmlx -framework OpenGL -framework AppKit -fsanitize=address -fno-omit-frame-pointer -o $(NAME)

linux : $(SRCS)
	@ echo "Compiling for Linux"
	@ $(CC) $(SRCS) -I . -L minilibx -lmlx_Linux -lXext -lX11 -ggdb -o $(NAME)

linux_sanitizer : $(SRCS)
	@ echo "Compiling for Linux with sanitizer"
	@ $(CC) $(SRCS) -I . -L minilibx -lmlx_Linux -lXext -lX11 -ggdb -fsanitize=address -fno-omit-frame-pointer  -o $(NAME)

bonus_linux : $(SRCS_BONUS)
	@ echo "Compiling bonus for Linux"
	@ $(CC) $(SRCS_BONUS) -I . -L minilibx -lmlx_Linux -lXext -lX11 -ggdb -o $(NAME)

bonus_linux_sanitizer : $(SRCS_BONUS)
	@ echo "Compiling bonus for Linux with sanitizer"
	@ $(CC) $(SRCS_BONUS) -I . -L minilibx -lmlx_Linux -lXext -lX11 -ggdb -fsanitize=address -fno-omit-frame-pointer  -o $(NAME)

clean :
	@ echo "Cleaning bins..."
	@ rm -rf $(OBJS)
	@ rm -rf $(wildcard *.o)

fclean : clean
	@ echo "Cleaning all..."
	@ rm -rf $(NAME)

re : fclean all

rel : fclean linux

.PHONY : all clean fclean re linux bonus bonus_linux

# @ gcc $(FLAGS) $(SRCS) -I . -L minilibx -lmlx_Linux -lXext -lX11 -ggdb -o $(NAME)
# 	@ $(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# $(NAME): $(SRCS)
# 	@ $(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# $(LINUX): $(SRCS)
# 	@ $(CC) $(SRCS) -I . -L minilibx -lmlx_Linux -lXext -lX11 -ggdb -o $(NAME)

#	$(CC) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


# $(NAME): $(OBJS)
# 	@ echo "Compiling $(NAME)..."
# 	@ gcc $(FLAGS) $(SRCS) -o $(NAME)


# LIBS  = -lkernel32 -luser32 -lgdi32 -lopengl32
# CFLAGS = -Wall

# OBJ = 64bitmath.o    \
#       monotone.o     \
#       node_sort.o    \
#       planesweep.o   \
#       triangulate.o  \
#       prim_combine.o \
#       welding.o      \
#       test.o         \
#       main.o

# %.o : %.c
#     gcc -c $(CFLAGS) $< -o $@

# test: $(OBJ)
#     gcc -o $@ $^ $(CFLAGS) $(LIBS)