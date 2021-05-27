#include <stdio.h>
#include <ctype.h>

int   ft_toupper(int c);
 

int main() {
    char c;

    c = 'm';
    printf("%c -> %c", c, toupper(c));

    c = 'D';
    printf("\n%c -> %c", c, toupper(c));

    c = '9';
    printf("\n%c -> %c", c, toupper(c));
    return 0;
}