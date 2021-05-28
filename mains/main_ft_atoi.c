#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int   ft_atoi(const char *str);


int main()
{
    int val;
    char strn1[] = "12546";

    val = ft_atoi(strn1);
    printf("String value = %s\n", strn1);
    printf("Integer value = %d\n", val);
	
    val = ft_atoi("-12345");
    printf("String value = %s\n", "-12345");
    printf("Integer value = %d\n", val);
    
    char strn2[] = "GeeksforGeeks";
    val = ft_atoi(strn2);
    printf("String value = %s\n", strn2);
    printf("Integer value = %d\n", val);

    return (0);
}
