#include <stdio.h>
#include <string.h>

size_t ft_strlen(void);

int main()
{
    printf("LIBASM TESTS\n\n");
    printf("FT_STRLEN\n");

    size_t ret = ft_strlen();
    char *str = "Hello World!";
    printf("- When string is: %s\n", str);
    printf("\tstrlen: %lu\tft_strlen: %lu\n", strlen(str), ret);
    return 0;
}
