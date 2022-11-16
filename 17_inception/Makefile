NAME = inception

DB_VOLUME_PATH = /home/ngasco/data/db
WP_VOLUME_PATH = /home/ngasco/data/website-files

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
	@rm -rf $(DB_VOLUME_PATH)
	@echo "Removing Wordpress files..."
	@rm -rf $(WP_VOLUME_PATH)

re: fclean all

.PHONY: all clean fclean re