#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int x = 2;

	ft_printf("Decimal: %d.\nInteger: %i.\nUnsigned: %u.\nCharacter: %c.\nPercentage: %%.\nString: %s.\nHex low: %x\nHex up: %X.\nPointer: %p\n", -12345, 12345, 1111, '?', "hola que tal?", 1232344545, 1232344545, &x);
	return (0);
}
