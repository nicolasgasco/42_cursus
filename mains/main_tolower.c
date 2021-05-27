#include <stdio.h>
#include <ctype.h>

int   ft_tolower(int c);

int main () {
   int i = 0;
   char str[] = "TUTORIALS POINT23424#$%$%$";
	
   while( str[i] ) {
      putchar(tolower(str[i]));
      i++;
   }
   
   return(0);
}