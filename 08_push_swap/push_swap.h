#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct NumList {
    int         num_tot;
    int         lo_tot;
    int         hi_tot;
    int         lo_a;
    int         hi_a;
    int         lo_b;
    int         hi_b;
    struct Node *a_list;
    struct Node *b_list;
} num_list;

struct Node {
    int         x;
    struct Node *next;
};

// Libft
size_t  ft_strlen(const char *s);
// size_t  t_strlcpy(char *dst, const char *src, size_t dstsize);
// size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);
// int     ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
// int			ft_isalpha(int c);
// int			ft_isprint(int c);
// int			ft_isdigit(int c);
// int			ft_isalnum(int c);
// int			ft_toupper(int c);
// int			ft_tolower(int c);
// void		*ft_memset(void *b, int c, size_t len);
// void		ft_bzero(void *s, size_t n);
// void		*ft_memcpy(void *dst, const void *src, size_t n);
// void		*ft_memchr(const void *s, int c, size_t n);
// int			ft_memcmp(const void *s1, const void *s2, size_t n);
// char		*ft_strnstr(const char *s, const char *need, size_t len);
// char		*ft_strchr(const char *s, int c);
// char		*ft_strrchr(const char *s, int c);
// void		*ft_memmove(void *dst, const void *src, size_t len);
// int			ft_isascii(int c);
// void		*ft_calloc(size_t count, size_t size);
// char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
// char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
// char		*ft_itoa(int n);
// char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
// void		ft_putstr_fd(char *s, int fd);
// void		ft_putendl_fd(char *s, int fd);
// void		ft_putnbr_fd(int n, int fd);

// Linked list methods
void	ft_insert_beginning(struct Node **root, int value);
void	ft_insert_end(struct Node **root, int value);
void	ft_deallocate_list(struct Node **root);
void	ft_iterate_list(struct Node *root, char c);
void	ft_insert_after(struct Node *node, int value);
void	ft_swap_nodes(struct Node **root, int i1, int i2);
void	ft_remove_node(struct Node **root, int value);

// Rules
void    ft_s(struct Node **root, char c);

// Push swap
void	ft_create_linked_list(int argc, char **args, num_list *num_list);

#endif