#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *, ...);

int	main(void)
{
	// ft_printf("Char: %c\nPercentage: %%\nDecimal: %d\nString: %s\n", 'c', 238434298, "string");
	ft_printf("String: %s\n", "string");
	return (0);
}
