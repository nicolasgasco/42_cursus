NAME = inception


NGINX_IMAGE_NAME = nginx-image
NGINX_PATH = srcs/requirements/nginx/

WORDPRESS_IMAGE_NAME = wordpress-image
WORDPRESS_PATH = srcs/requirements/wordpress/

DATABASE_VOLUME_NAME = wordpress-database-volume
WEBSITE_VOLUME_NAME = wordpress-website-volume

VOLUME_HOST_PATH = /home/ngasco/data

ALL_CONTAINERS := $(docker ps -q)

all: $(NAME)

$(NAME):
	@echo "Making inception..."
	@docker compose -f srcs/docker-compose.yml up --build

clean:
	@docker compose -f srcs/docker-compose.yml down

fclean: clean
	@docker image prune -a
	@rm -rf ./srcs/requirements/tools/*

re: fclean all

.PHONY: all clean fclean re