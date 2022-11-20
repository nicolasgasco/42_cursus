NAME = inception

DB_VOLUME_PATH = /Users/dev/Documents/42_cursus/17_inception/db
WP_VOLUME_PATH = /Users/dev/Documents/42_cursus/17_inception/website-files

all: $(NAME)

$(NAME):
	@echo "Creating volume folders..."
	@mkdir -p $(DB_VOLUME_PATH)
	@mkdir -p $(WP_VOLUME_PATH)
	@echo "Bulding containers..."
	@docker compose -f srcs/docker-compose.yml up --build

clean:
	@echo "Shutting down containers..."
	@docker compose -f srcs/docker-compose.yml down

fclean: clean
	@echo "Pruning images..."
	@docker image prune -af > /dev/null 2>&1
	@echo "Removing db files..."
	@docker volume rm -f mariadb_data > /dev/null 2>&1
	@echo "Removing Wordpress files..."
	@docker volume rm -f wordpress_data > /dev/null 2>&1

re: fclean all

exec_wordpress:
	@docker exec -it wordpress sh

exec_nginx:
	@docker exec -it nginx sh

exec_mariadb:
	@docker exec -it mariadb sh

.PHONY: all clean fclean re exec_wordpress exec_nginx exec_mariadb