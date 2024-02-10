#include <stdio.h>
#include <string.h>
#include "ft_libasm.h"
#include "test_seeds.h"

#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define NC "\033[0m"

char *STRING_SEEDS[] = {NORMAL_STRING,
                        EMPTY_STRING,
                        EMOJI_STRING,
                        LONG_STRING,
                        NULL};

void ft_print_test_title(char *title)
{
    printf("%s%s%s\n", BLUE, title, NC);
}

void ft_strlen_assertion(char *str)
{
    size_t expected = strlen(str);
    size_t actual = ft_strlen(str);

    printf("  - When string is %s%.50s%s\n", BLUE, str, NC);
    printf("    strlen: %s%lu%s, ft_strlen: %s%lu%s\n", YELLOW, expected, NC, YELLOW, actual, NC);
    printf("\n");
}

void ft_strlen_tests()
{
    ft_print_test_title("FT_STRLEN");

    for (int i = 0; STRING_SEEDS[i]; i++)
    {
        ft_strlen_assertion(STRING_SEEDS[i]);
    }
}

void ft_strcpy_assertion(char *src)
{
    size_t src_len = strlen(src);

    char dest[src_len + 1];
    bzero(dest, src_len + 1);

    printf("  - When source is '%s%.50s%s' (%lu chars) and dest is '%s%.50s%s' (%lu chars)\n", BLUE, src, NC, strlen(src), BLUE, dest, NC, strlen(dest));

    printf("    Dest (before strcpy): %s%.50s%s\n", YELLOW, dest, NC);
    char *original_ret = strcpy(dest, src);
    printf("    Dest (after strcpy): %s%.50s%s\n", YELLOW, dest, NC);
    printf("    Return value is: %s%.50s%s\n", BLUE, original_ret, NC);

    printf("      -\n");
    bzero(dest, strlen(dest));

    printf("    Dest (before ft_strcpy): %s%.50s%s\n", YELLOW, dest, NC);
    char *own_ret = ft_strcpy(dest, src);
    printf("    Dest (after ft_strcpy): %s%.50s%s\n", YELLOW, dest, NC);
    printf("    Return value is: %s%.50s%s\n", BLUE, own_ret, NC);

    printf("\n");
}

void ft_strcpy_tests()
{
    ft_print_test_title("FT_STRCPY");

    for (int i = 0; STRING_SEEDS[i]; i++)
    {
        ft_strcpy_assertion(STRING_SEEDS[i]);
    }
}

void ft_strcmp_assertion(char *s1, char *s2)
{
    printf("  - When s1 is '%s%.50s%s' and s2 is '%s%.50s%s'\n", BLUE, s1, NC, BLUE, s2, NC);

    printf("    strcmp: %s%d%s, ft_strcmp: %s%d%s\n", YELLOW, strcmp(s1, s2), NC, YELLOW, ft_strcmp(s1, s2), NC);
    printf("\n");
}

void ft_strcmp_tests()
{
    const char *cmp_seeds1[] = {
        "Hello world!",
        "a",
        "String containing 👋🌍 emojis",
        "Not a very long string, but still long enough to be considered long",
        NULL};

    const char *cmp_seeds2[] = {
        "hello world!",
        "",
        "10",
        " \t",
        NULL};

    ft_print_test_title("FT_STRCMP");

    for (int i = 0; STRING_SEEDS[i]; i++)
    {
        ft_strcmp_assertion(STRING_SEEDS[i], cmp_seeds1[i]);
    }

    for (int i = 0; STRING_SEEDS[i]; i++)
    {
        ft_strcmp_assertion(STRING_SEEDS[i], cmp_seeds2[i]);
    }
}

int main()
{
    printf("\n%sLIBASM TESTS%s\n\n", YELLOW, NC);

    ft_strlen_tests();
    ft_strcpy_tests();
    ft_strcmp_tests();

    return 0;
}
