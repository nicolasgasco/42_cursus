#include <limits.h>

int	ft_printf(const char *, ...);

int	main(void)
{
	ft_printf("Ci%xao\n", INT_MAX);
	return (0);
}
