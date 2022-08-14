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

void ft_trim_args(char **argv, char **new_args)
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
    int num_args;
    printf("________________________\n\n");
    int pipe_opened = 0;
    int next_is_pipe = 0;
    int wrote_into_pipe = 0;

    argv++;
    while (*argv)
    {
        if (strcmp(*argv, "|") == 0)
            argv += 1;
        else if (strcmp(*argv, ";") == 0)
            argv += 1;
        else if (strcmp(*argv, "cd") == 0)
        {
            num_args = ft_get_num_args(argv);
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
            int fd[2];
            int fd2[2];
            // ft_print_string_array(argv);
            num_args = ft_get_num_args(argv);
            if (*(argv + num_args) && strcmp(*(argv + num_args), "|") == 0)
            {
                printf("Opening main pipe\n");
                if (pipe_opened == 0)
                {
                    pipe_opened = 1;
                    if (pipe(fd) == -1)
                    {
                        printf("Error with pipe\n");
                        exit(2);
                    }
                }
                else
                {
                    printf("Opening second pipe\n");
                    if (pipe(fd2) == -1)
                    {
                        printf("Error with pipe\n");
                        exit(2);
                    }
                }
            }
            else
                next_is_pipe = 0;
            int pid = fork();
            if (pid < 0)
            {
                printf("Error with fork\n");
                exit(2);
            }
            if (pid == 0)
            {

                if (wrote_into_pipe == 0)
                {
                    printf("Writing into pipe (%s, %d)\n", *argv, wrote_into_pipe);
                    if (dup2(fd[1], STDOUT_FILENO) < 0)
                    {
                        printf("error with dup2\n");
                        exit(2);
                    }
                }
                if (wrote_into_pipe == 1)
                {

                    printf("Reading from pipe (%s)\n", *argv);
                    if (dup2(fd[0], STDIN_FILENO) < 0)
                    {
                        printf("Error with dup2\n");
                        exit(2);
                    }
                    if (next_is_pipe == 1)
                    {
                        printf("mierda\n");
                        if (dup2(fd2[1], STDOUT_FILENO) < 0)
                        {
                            printf("Error with dup2\n");
                            exit(2);
                        }
                    }
                }
                close(fd[1]);
                close(fd[0]);
                char *new_args[argc];
                ft_trim_args(argv, new_args);
                if (execve(*argv, new_args, envp) == -1)
                {
                    ft_write_fd(STDERR_FILENO, "error: cannot execute ");
                    ft_write_fd(STDERR_FILENO, *argv);
                    ft_write_fd(STDERR_FILENO, "\n");
                    // system("leaks microshell");
                    exit(2);
                }
            }

            int status;
            waitpid(0, &status, 0);
            if (wrote_into_pipe == 0 || next_is_pipe == 1)
                close(fd[1]);
            if (wrote_into_pipe == 1)
                close(fd[0]);
            wrote_into_pipe = 1;
            int num_args = ft_get_num_args(argv);
            argv += num_args;
        }
    }
    // system("leaks microshell");
    return (0);
}