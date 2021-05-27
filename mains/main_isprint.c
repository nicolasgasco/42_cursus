#include <ctype.h>
#include <stdio.h>

int   ft_isprint(int c);
 


int main()
{
    char c;

    c = 'Q';
    printf("Result when a printable character %c is passed to isprint(): %d", c, isprint(c));

    c = '\n';
    printf("\nResult when a control character %c is passed to isprint(): %d", c, isprint(c));

    return 0;
}