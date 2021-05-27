#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int   ft_isascii(int c);
 
int main(void)
{
   int ch;
 
   for (ch = 0x7c; ch <= 0x82; ch++) {
      printf("%#04x    ", ch);
      if (isascii(ch))
         printf("The character is %c\n", ch);
      else
         printf("Cannot be represented by an ASCII character\n");
   }

         if (isascii('a'))
         printf("The character is %c\n", 'a');
      else
         printf("Cannot be represented by an ASCII character\n");

         
   return 0;
}