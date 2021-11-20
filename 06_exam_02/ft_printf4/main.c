#include <limits.h>

int	ft_printf(const char *, ...);

int	main()
{
	ft_printf("Ci%co %s %x\n", 'a', "sono io", (INT_MIN + 1));
	return (0);
}
