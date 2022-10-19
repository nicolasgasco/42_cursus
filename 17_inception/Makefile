NAME = inception

NGINX_IMAGE_NAME = nginx-image
NGINX_PATH = srcs/requirements/nginx/

WORDPRESS_IMAGE_NAME = wordpress-image
WORDPRESS_PATH = srcs/requirements/wordpress/

ALL_CONTAINERS := $(docker ps -q)

all: $(NAME)

$(NAME):
	@echo "Making inception..."
	@docker build -t $(NGINX_IMAGE_NAME) $(NGINX_PATH)
	@docker run -dit --name nginx $(NGINX_IMAGE_NAME)
	@echo "✅ nginx image created"

	@docker build -t $(WORDPRESS_IMAGE_NAME) $(WORDPRESS_PATH)
	@docker run -dit --name wordpress $(WORDPRESS_IMAGE_NAME)
	@echo "✅ wordpress image created"

clean:
	@docker kill nginx
	@docker rm nginx
	@docker image rm $(NGINX_IMAGE_NAME)
	@echo "🧹 Deleted nginx"

	@docker kill wordpress
	@docker rm wordpress
	@docker image rm $(WORDPRESS_IMAGE_NAME)
	@echo "🧹 Deleted wordpress"

fclean: clean

re: fclean all

.PHONY: all clean fclean re