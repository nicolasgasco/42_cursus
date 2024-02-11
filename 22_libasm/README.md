# libasm

> The aim of this project is to get familiar with assembly language.

Create a small library of x86_64 NASM assembly functions:
- ft_strlen ([man 3 strlen](https://man7.org/linux/man-pages/man3/strlen.3.html))
- ft_strcpy ([man 3 strcpy](https://man7.org/linux/man-pages/man3/strcpy.3.html))
- ft_strcmp ([man 3 strcmp](https://man7.org/linux/man-pages/man3/strcmp.3.html))
- ft_write ([man 2 write](https://man7.org/linux/man-pages/man2/write.2.html))
- ft_read ([man 2 read](https://man7.org/linux/man-pages/man2/read.2.html))
- ft_strdup ([man 3 strdup](https://man7.org/linux/man-pages/man3/strdup.3.html))

Functions were tested in a C main file.

## Run tests
```
make re && ./test
```
The library was tested on Intel MacOs and Linux virtual machines (Github Codespaces).
