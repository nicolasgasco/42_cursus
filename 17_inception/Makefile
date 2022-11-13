NAME = inception

all: $(NAME)

$(NAME):
	@echo "Bulding containers..."
	@docker compose -f srcs/docker-compose.yml up --build

clean:
	@echo "Shutting down containers..."
	@docker compose -f srcs/docker-compose.yml down

fclean: clean
	@echo "Pruning images..."
	@docker image prune -af > /dev/null 2>&1
	@echo "Removing db files..."
	@rm -rf /Users/dev/Documents/42_cursus/17_inception/db/*
	@echo "Removing Wordpress files..."
	@rm -rf /Users/dev/Documents/42_cursus/17_inception/website-files

re: fclean all

.PHONY: all clean fclean re