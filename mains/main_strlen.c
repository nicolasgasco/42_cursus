#include <stdio.h>
#include <string.h>

int ft_strlen(const char *str);

int main () {
   char str[50];
   int len;

   strcpy(str, "This is tutorialspoint.com");

   len = ft_strlen(str);
   printf("Length of |%s| is |%d|\n", str, len);
   
   return(0);
}