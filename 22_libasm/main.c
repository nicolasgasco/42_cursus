#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "src/ft_libasm.h"
#include "test_seeds.h"

#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define NC "\033[0m"

char *STRING_SEEDS[] = {NORMAL_STRING,
                        EMPTY_STRING,
                        EMOJI_STRING,
                        LONG_STRING,
                        UNREACHABLE,
                        NULL};

void ft_print_test_title(char *title)
{
    printf("%s%s%s\n", BLUE, title, NC);
}

void ft_strlen_assertion(char *str)
{
    size_t expected = strlen(str);
    size_t actual = ft_strlen(str);

    printf("  - ");
    if (expected == actual)
        printf("✅");
    else
        printf("❌");
    printf(" When string is |%s%.50s%s|\n", BLUE, str, NC);
    printf("    strlen: %s%lu%s, ft_strlen: %s%lu%s\n", YELLOW, expected, NC, YELLOW, actual, NC);
    printf("\n");
}

void ft_strlen_tests()
{
    ft_print_test_title("FT_STRLEN");

    for (int i = 0; STRING_SEEDS[i]; i++)
        ft_strlen_assertion(STRING_SEEDS[i]);
}

void ft_strcpy_assertion(char *src)
{
    size_t src_len = strlen(src);

    char dest[src_len + 1];
    bzero(dest, src_len + 1);

    printf("  - When source is .%s%.50s%s. (%lu chars)\n", BLUE, src, NC, strlen(src));

    printf("    Dest (before strcpy): .%s%.50s%s.\n", YELLOW, dest, NC);
    char *original_ret = strcpy(dest, src);
    printf("    Dest (after strcpy): .%s%.50s%s.\n", YELLOW, dest, NC);
    printf("    Return value is: .%s%.50s%s.\n", BLUE, original_ret, NC);

    printf("      -\n");
    bzero(dest, src_len + 1);

    printf("    Dest (before ft_strcpy): .%s%.50s%s.\n", YELLOW, dest, NC);
    char *own_ret = ft_strcpy(dest, src);
    printf("    Dest (after ft_strcpy): .%s%.50s%s.\n", YELLOW, dest, NC);
    printf("    Return value is: .%s%.50s%s.\n", BLUE, own_ret, NC);

    printf("\n");
}

void ft_strcpy_tests()
{
    ft_print_test_title("FT_STRCPY");

    for (int i = 0; STRING_SEEDS[i]; i++)
        ft_strcpy_assertion(STRING_SEEDS[i]);
}

void ft_strcmp_assertion(char *s1, char *s2)
{
    printf("  - When s1 is .%s%.50s%s. and s2 is .%s%.50s%s.\n", BLUE, s1, NC, BLUE, s2, NC);

    printf("    strcmp: %s%d%s, ft_strcmp: %s%d%s\n", YELLOW, strcmp(s1, s2), NC, YELLOW, ft_strcmp(s1, s2), NC);
    printf("\n");
}

void ft_strcmp_tests()
{
    char *cmp_seeds1[] = {
        "Hello world!",
        "",
        "String containing 👋🌍 emojis",
        "Not a very long string, but still long enough to be considered long",
        "Hi\0This string is unreachable",
        NULL};

    char *cmp_seeds2[] = {
        "hello world!",
        "hey",
        "",
        " \t",
        "\0",
        NULL};

    ft_print_test_title("FT_STRCMP");

    for (int i = 0; STRING_SEEDS[i]; i++)
    {
        ft_strcmp_assertion(STRING_SEEDS[i], cmp_seeds1[i]);
        ft_strcmp_assertion(cmp_seeds1[i], STRING_SEEDS[i]);
    }

    for (int i = 0; STRING_SEEDS[i]; i++)
    {
        ft_strcmp_assertion(STRING_SEEDS[i], cmp_seeds2[i]);
        ft_strcmp_assertion(cmp_seeds2[i], STRING_SEEDS[i]);
    }
}

void ft_write_assertion(int fd, char *str, size_t len)
{
    printf("  - When fd is %d, str is '%s%.50s%s' and len is %lu\n", fd, BLUE, str, NC, len);

    int original_ret = write(fd, str, len);
    int original_errno = errno;

    errno = 0;

    int own_ret = ft_write(fd, str, len);
    int own_errno = errno;
    printf("    write: %s%d%s, ft_write: %s%d%s\n", YELLOW, original_ret, NC, YELLOW, own_ret, NC);

    if (original_ret < 0 || own_ret < 0)
        printf("    errno: %s%s%s (%d), ft_errno: %s%s%s (%d)\n", YELLOW, strerror(original_errno), NC, original_errno, YELLOW, strerror(own_errno), NC, own_errno);
    printf("\n");
}

void ft_write_tests()
{
    ft_print_test_title("FT_WRITE");

    for (int i = 0; STRING_SEEDS[i]; i++)
    {
        if (strlen(STRING_SEEDS[i]) < 50)
            ft_write_assertion(1, STRING_SEEDS[i], strlen(STRING_SEEDS[i]));
    }

    ft_write_assertion(1, "Hello world!", 5);
    ft_write_assertion(1, "Hello world!", 1);
    ft_write_assertion(1, "Hello world!", 0);
    ft_write_assertion(1, "Hello world! Hey hey hey", 25);
    ft_write_assertion(1, "Hello world!", -2);

    ft_write_assertion(-1, "Hello world!", 5);
    ft_write_assertion(0, "Hello world!", 5);
    ft_write_assertion(1203, NULL, 10);
    ft_write_assertion(2, "Hello world!", 5);

    ft_write_assertion(1, NULL, 5);

    int fd = open("test_files/test_write", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
    ft_write_assertion(fd, "Hello world!", 5);
    close(fd);
}

void ft_read_assertion(int fd, size_t len, char *filename)
{
    char buf[len];

    if (filename)
    {
        fd = open("test_files/test_read", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        write(fd, "Hello world!", 12);
        close(fd);

        fd = open("test_files/test_read", O_RDWR);
    }

    printf("  - When fd is %d and buf len is %lu\n", fd, len);

    int original_ret = read(fd, &buf, len);
    int original_errno = errno;

    if (filename)
        close(fd);

    if (filename)
    {
        char new_filename[1024];
        strcpy(new_filename, filename);
        strcat(new_filename, "_own");

        fd = open(new_filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        write(fd, "Hello world!", 12);
        close(fd);

        fd = open("test_files/test_read", O_RDWR);
    }

    int own_ret = ft_read(fd, &buf, len);
    int own_errno = errno;

    if (own_ret < 0 || original_ret < 0)
        printf("    errno: %s%s%s (%d), ft_errno: %s%s%s (%d)\n", YELLOW, strerror(original_errno), NC, original_errno, YELLOW, strerror(own_errno), NC, own_errno);

    printf("    read: %s%d%s, ft_read: %s%d%s\n", YELLOW, original_ret, NC, YELLOW, own_ret, NC);

    if (filename)
        close(fd);

    printf("\n");
}

void ft_read_tests()
{
    ft_print_test_title("FT_READ");

    // ft_read_assertion(0, 10, NULL); User input required, uncomment to test
    ft_read_assertion(0, 0, NULL);
    ft_read_assertion(0, -1, NULL);

    ft_read_assertion(-1, 10, NULL);
    ft_read_assertion(2500, 10, NULL);
    ft_read_assertion(0, -1, NULL);

    ft_read_assertion(0, 7, "test_files/test_read");
}

void ft_strdup_assertion(char *str)
{
    printf("  - When string is |%s%.50s%s|\n", BLUE, str, NC);

    char *original_ret = strdup(str);
    char *own_ret = ft_strdup(str);

    printf("    strdup: |%s%.50s%s|, ft_strdup: |%s%.50s%s|\n", YELLOW, original_ret, NC, YELLOW, own_ret, NC);

    if (original_ret)
        free(original_ret);

    if (own_ret)
        free(own_ret);

    printf("\n");
}

void ft_strdup_tests()
{
    ft_print_test_title("FT_STRDUP");

    for (int i = 0; STRING_SEEDS[i]; i++)
        ft_strdup_assertion(STRING_SEEDS[i]);
}

void ft_subject_tests()
{
    char *empty_str = "";
    char *normal_str = "Hello world!";
    char *very_long_str = "cmvgmblxmhwdenvyyltnhfcuqlyvkldxjcfczezekdyhxfp...zchdahfbghgzxzhxbswalnyeasxpbbcrdwtwkqqqspzstpswgkcjyrgjezbyxncnpacknscagjwbvkryoladtdrvcttpjethsrxmmyycuqoykfuyodgnqnlvzdevfdpziniljvrtvxgtpkuxoodlrtgnyviifkyjpybphtjwjzgofacckcslsagpbsbuhlkmcxazefvbzmtkgciloeopqnzljjbmuntstjdtdqkcefwrbnjiqxkclfqmbxigykeagquooapkeeftawzctydistntkeioaweswvbflwfzazcramnmjrncecspudzuisksukmbgqoxionyvhctipplavajbtgbtlhrhrkyehdvnrplwpycvxaejframiboceruuopjcugajtynrgblkyycpxqapcvmrnsvuwbjsabfpsdfchfksrbpwyguetazxdgwipfafpoytadixikcttnujsggrkucneilksodtnptlzsjzsdbbhisainzdwnilgxchvpfygqtzcflpjxtmxhyrnmxdqfabxvzgkkmbrmjfjtgybmxrwodynglnddowjzhxdcvktuvowdsyqdtztpwdrjcsbakcwwgsmzhesycpyxhpplagsffnukxsxgvsvndgvifniicmpafdvicbyrlhumyygetnvwxtitpwptwzkyxrsdrhpyethmlsziwcxmfxsvfbldzrygeyxrrmtcxpmrdxuhqxjskzxdcctotmblybhxxysvqfxcmonqqcziwhymmqavsjvkacruexxwegtcdxmjcdksoiiiployyugglnrfyzkavrywaxjfvkbhltaobflvxrvyzqcaytfdxitoggtynpaeqrwquorzaxfjbcletikacwvjwviipfoxsknbkbppumxqkcymmnssomenayg";

    // ft_strlen
    ft_print_test_title("FT_STRLEN");
    ft_strlen_assertion(empty_str);
    ft_strlen_assertion(very_long_str);

    // ft_strcpy
    ft_print_test_title("FT_STRCPY");
    char dest[100];
    bzero(dest, 100);
    ft_strcpy_assertion(empty_str);
    ft_strcpy_assertion(very_long_str);

    // ft_strcmp
    ft_print_test_title("FT_STRCMP");
    ft_strcmp_assertion(empty_str, empty_str);
    ft_strcmp_assertion(empty_str, normal_str);
    ft_strcmp_assertion(normal_str, empty_str);

    // ft_write
    ft_print_test_title("FT_WRITE");
    ft_write_assertion(1, normal_str, strlen(normal_str));

    int fd = open("test_files/test_write", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
    ft_write_assertion(fd, normal_str, strlen(normal_str));

    ft_write_assertion(-1, normal_str, strlen(normal_str));

    // ft_read
    ft_print_test_title("FT_READ");
    // ft_read_assertion(0, 50, NULL); User input required, uncomment to test

    int fd2 = open("test_files/test_read", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    write(fd2, normal_str, strlen(normal_str));
    ft_read_assertion(fd2, strlen(normal_str), "test_files/test_read");

    ft_read_assertion(-1, 50, NULL);

    // ft_strdup
    ft_print_test_title("FT_STRDUP");
    ft_strdup_assertion(empty_str);
    ft_strdup_assertion(very_long_str);

}

void ft_exhaustive_tests()
{
    ft_strlen_tests();
    ft_strcpy_tests();
    ft_strcmp_tests();
    ft_write_tests();
    ft_read_tests();
    ft_strdup_tests();
}

int main()
{
    printf("\n%sLIBASM TESTS%s\n\n", YELLOW, NC);

    ft_exhaustive_tests();

    ft_subject_tests();

    return 0;
}
