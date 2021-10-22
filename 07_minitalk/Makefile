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

SRCS_CLIENT =  ft_client.c \

SRCS_SERVER = ft_server.c \

SRC_UTILS = minitalk_utils.c \

SRCS_PRINTF = ft_printf.c \
			  ft_printf_utils.c \

FLAGS = -Wall -Wextra -Werror \

$(CLIENT):
	@ gcc $(FLAGS) $(SRCS_CLIENT) $(SRCS_PRINTF) $(SRC_UTILS) -o client
	@ echo "Compiling client..."

$(SERVER):
	@ gcc $(FLAGS) $(SRCS_SERVER) $(SRCS_PRINTF) $(SRC_UTILS) -o server
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
