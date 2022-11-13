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
	@echo "Setting env variables..."
	@export $(grep -v '^#' ./srcs/.env | xargs)
	@docker compose -f srcs/docker-compose.yml up --build

clean:
	@echo "Shutting down containers..."
	@docker compose -f srcs/docker-compose.yml down

fclean: clean
	@echo "Pruning images..."
	@docker image prune -af
	@echo "Removing db files..."
	@rm -rf ./srcs/requirements/tools/db/*
	@echo "Removing Wordpress files..."
	@rm -rf ./srcs/requirements/tools/website-files

re: fclean all

.PHONY: all clean fclean re