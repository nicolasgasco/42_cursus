# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 17:53:00 by ngasco            #+#    #+#              #
#    Updated: 2021/10/22 18:33:55 by ngasco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

SRCS_BONUS_PRINTF = ft_printf.c \
			  ft_printf_utils.c \

SRCS_BONUS_CLIENT = ft_client_bonus.c \

SRCS_BONUS_SERVER = ft_server_bonus.c \

SRCS_BONUS_PRINTF = ft_printf_bonus.c \
			  	   	ft_printf_utils_bonus.c \

FLAGS = -Wall -Wextra -Werror \

$(CLIENT):
	@ gcc $(FLAGS) $(SRCS_BONUS_CLIENT) $(SRCS_BONUS_PRINTF) -o client
	@ echo "Compiling client..."

$(SERVER):
	@ gcc $(FLAGS) $(SRCS_BONUS_SERVER) $(SRCS_BONUS_PRINTF) -o server
	@ echo "Compiling server..."

bonus :
	@ gcc $(FLAGS) $(SRCS_BONUS_CLIENT) $(SRCS_BONUS_PRINTF) -o client
	@ echo "Compiling client..."
	@ gcc $(FLAGS) $(SRCS_BONUS_SERVER) $(SRCS_BONUS_PRINTF) -o server
	@ echo "Compiling server..."

all : $(SERVER) $(CLIENT)

clean_client :
	@ rm -rf client
	@ echo "Deleting client..."

clean_server :
	@ rm -rf server
	@ echo "Deleting server..."

fclean : clean
	@ rm -rf server
	@ rm -rf client
	@ echo "Deleting binaries..."

re : fclean all

.PHONY : all clean fclean re
