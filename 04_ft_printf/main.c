#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int x = 2;

	printf("Normal cases:\n\n");
	ft_printf("Decimal: %d.\nInteger: %i.\nUnsigned: %u.\nCharacter: %c.\nPercentage: %%.\nString: %s.\nHex low: %x\nHex up: %X.\nPointer: %p\n", -12345, 12345, 1111, '?', "hola que tal?", 1232344545, 1232344545, &x);
	printf("\n______________\n\n");
	printf(" (c, char count is %d)\n", ft_printf("%c", 'a'));
	printf(" (s, char count is %d)\n", ft_printf("%s", "This must be 26 characters"));
	printf(" (i, char count is %i)\n", ft_printf("%i", -123456789));
	printf(" (d, char count is %d)\n", ft_printf("%d", 123456789));
	printf(" (u, char count is %d)\n", ft_printf("%u", 21474836479));
	printf(" (%%%%, char count is %d)\n", ft_printf("%%"));
	printf(" (x, char count is %d)\n", ft_printf("%x", 123456789));
	printf(" (X, char count is %d)\n", ft_printf("%X", 42));
	printf(" (p, char count is %d)\n", ft_printf("%p", x));
	return (0);
}
