#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ft_print_string_array(char **array)
{
    printf("- - - - - - - - - - - - - - - -\n");
    for (int i = 0; array[i]; i++)
    {
        printf("\t- %d: %s\n", i, array[i]);
    }
    printf("- - - - - - - - - - - - - - - -\n");
}

void ft_get_cmd_args(char **argv, char **new_args)
{
    for (int i = 0; argv[i]; i++)
    {
        new_args[i] = argv[i];
        if (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0)
        {
            new_args[i] = NULL;
        }
    }
}

int ft_get_num_args(char **argv)
{
    int i;
    for (i = 0; argv[i]; i++)
    {
        if (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0)
            return (i);
    }
    return (i);
}

int main(int argc, char *argv[], char **envp)
{
    // ft_print_string_array(envp);
    printf("________________________\n\n");
    argv++;
    for (int i = 0; i < argc; i++)
    {
        char *arg = argv[i];
        ft_print_string_array(argv);
        printf("%d: %s\n", i, arg);
        if (strcmp(arg, "|") == 0)
        {
            printf("\tFound a pipe\n");
        }
        else if (strcmp(arg, ";") == 0)
        {
            printf("\tFound a semicolon\n");
        }
        else
        {
            printf("\tNot pipe, not semicolon\n");
            int pid = fork();

            if (pid < 0)
            {
                printf("Error with fork\n");
            }
            else if (pid == 0)
            {
                printf("Child process\n");
                char *new_args[argc];
                ft_get_cmd_args(argv, new_args);
                if (execve(arg, new_args, envp) < 0)
                {
                    printf("Execve error\n");
                }
            }
            else
            {
                int status;
                waitpid(0, &status, 0);
                printf("Parent process\n");
                argv += ft_get_num_args(argv);
                ft_print_string_array(argv);
            }
        }
        return (0);
        printf("________________________\n\n");
    }
    // system("leaks a.out");
    return (0);
}