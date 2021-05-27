#include <stdio.h>
#include <string.h>

char *ft_strlcpy(char *dest, const char *src, int size);
int main () {
   char src[40];
   char dest[100];
  
   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is tutorialspoint.com");
   strlcpy(dest, src, 10);

   printf("Final copied string : %s\n", dest);
   
   return(0);
}