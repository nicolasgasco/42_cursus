NAME := computor

.PHONY: all re clean test

all: $(NAME)

$(NAME):
	go build -o $(NAME) .

test:
	go test ./...

clean:
	rm -f $(NAME)

re: clean all
