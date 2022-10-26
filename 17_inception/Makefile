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
	@docker compose -f srcs/docker-compose.yml up -d

# # NGINX
# @docker build -t $(NGINX_IMAGE_NAME) $(NGINX_PATH)
# @docker run -dit --name nginx $(NGINX_IMAGE_NAME)
# @echo "✅ nginx image created"

# # DATABASE VOLUME
# @docker volume create $(DATABASE_VOLUME_NAME)
# @echo "✅ wordpress database volume created"

# # WORDPRESS WEBSITE VOLUME
# @docker volume create $(WEBSITE_VOLUME_NAME)
# @echo "✅ wordpress website volume created"

# # WORDPRESS
# @docker build -t $(WORDPRESS_IMAGE_NAME) $(WORDPRESS_PATH)
# @docker run -dit --name wordpress -v $(DATABASE_VOLUME_NAME):$(VOLUME_HOST_PATH)/wordpress_database_volume -v $(WEBSITE_VOLUME_NAME):$(VOLUME_HOST_PATH)/wordpress_website_volume $(WORDPRESS_IMAGE_NAME)
# @echo "✅ wordpress image created"

clean:
	@docker compose -f srcs/docker-compose.yml down
# @docker kill nginx
# @docker rm nginx
# @docker image rm $(NGINX_IMAGE_NAME)
# @echo "🧹 Deleted nginx"

# @docker kill wordpress
# @docker rm wordpress
# @docker image rm $(WORDPRESS_IMAGE_NAME)
# @echo "🧹 Deleted wordpress"

fclean: clean

re: fclean all

.PHONY: all clean fclean re