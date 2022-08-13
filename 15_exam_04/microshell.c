#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ft_print_string_array(char **array)
{
    printf("- - - - - - - - - - - - - - - -\n");
    int i;
    for (i = 0; array[i]; i++)
    {
        printf("\t- %d: %s\n", i, array[i]);
    }
    if (array[i] == NULL)
        printf("\t- %d: NULL\n", i);
    printf("- - - - - - - - - - - - - - - -\n");
}

void ft_get_cmd_args(char **argv, char **new_args)
{
    int i;
    for (i = 0; argv[i]; i++)
    {
        new_args[i] = argv[i];
        if (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0)
        {
            break;
        }
    }
    new_args[i] = NULL;
}

int ft_get_num_args(char **argv)
{
    int i;
    for (i = 0; argv[i]; i++)
    {
        if (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0)
        {
            return (i);
        }
    }
    return (i);
}

void ft_write_fd(int fd, char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        write(fd, &string[i], sizeof(char));
        i++;
    }
}

int main(int argc, char *argv[], char **envp)
{
    printf("________________________\n\n");
    argv++;
    while (*argv)
    {
        if (strcmp(*argv, "|") == 0)
        {
            // printf("\tFound a pipe\n");
        }
        else if (strcmp(*argv, ";") == 0)
            argv += 1;
        else if (strcmp(*argv, "cd") == 0)
        {
            int num_args = ft_get_num_args(argv);
            if (num_args != 2)
            {
                ft_write_fd(STDERR_FILENO, "error: cd: bad arguments\n");
                // system("leaks microshell");
                exit(2);
            }
            argv++;
            if (chdir(*argv) == -1)
            {
                ft_write_fd(STDERR_FILENO, "error: cd: cannot change directory to ");
                ft_write_fd(STDERR_FILENO, *argv);
                ft_write_fd(STDERR_FILENO, "\n");
                // system("leaks microshell");
                exit(2);
            }
            argv++;
        }
        else
        {
            // printf("\tNot pipe, not semicolon\n");
            int pid = fork();

            if (pid < 0)
            {
                printf("Error with fork\n");
            }
            else if (pid == 0)
            {
                char *new_args[argc];
                ft_get_cmd_args(argv, new_args);
                if (execve(*argv, new_args, envp) == -1)
                {
                    ft_write_fd(STDERR_FILENO, "error: cannot execute ");
                    ft_write_fd(STDERR_FILENO, *argv);
                    ft_write_fd(STDERR_FILENO, "\n");
                    // system("leaks microshell");
                    exit(2);
                }
            }
            else
            {
                int status;
                waitpid(0, &status, 0);
                int num_args = ft_get_num_args(argv);
                argv += num_args;
            }
        }
    }
    // system("leaks microshell");
    return (0);
}