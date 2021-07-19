#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	char	*n_str;

	n_str = ft_itoa(n);
	ft_putstr_fd(n_str, fd);
}
