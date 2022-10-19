NAME = inception

NGINX_IMAGE_NAME = nginx-image
NGINX_PATH = srcs/requirements/nginx/

ALL_CONTAINERS := $(docker ps -q)

all: $(NAME)

$(NAME):
	echo "Making inception..."
	@docker build -t $(NGINX_IMAGE_NAME) $(NGINX_PATH)
	@docker run -dit --name nginx $(NGINX_IMAGE_NAME)

clean:
	@docker kill nginx
	@docker rm nginx
	@docker image rm $(NGINX_IMAGE_NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re