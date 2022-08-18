#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#define READ 0
#define WRITE 1

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
    // printf("________________________\n\n");
    int pipe_opened = 0;
    int next_is_pipe = 0;
    int must_write = 0;
    int must_read = 0;
    int must_write_read = 0;

    argv++;
    while (*argv)
    {
        if (strcmp(*argv, "|") == 0 && *(argv + 1))
        {
            // printf("Pipe\n\n");
            argv += 1;
        }
        else if (strcmp(*argv, ";") == 0 && *(argv + 1))
        {
            argv += 1;
        }
        else if (strcmp(*argv, "cd") == 0 && *(argv + 1))
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
            int fd[2][2];
            // ft_print_string_array(argv);
            num_args = ft_get_num_args(argv);
            if (*(argv + num_args) && strcmp(*(argv + num_args), "|") == 0)
            {
                // printf("Next one is a pipe\n");
                next_is_pipe = 1;
                if (pipe_opened == 0)
                {
                    // printf("Opening first pipe for writing only\n");
                    if (pipe(fd[0]) == -1)
                    {
                        printf("Error with pipe\n");
                        exit(2);
                    }
                    pipe_opened = 1;
                    must_write = 1;
                }
                else if (next_is_pipe == 1)
                {
                    // printf("Opening second pipe for reading and writing\n");
                    if (pipe(fd[1]) == -1)
                    {
                        printf("Error with pipe\n");
                        exit(2);
                    }
                    pipe_opened = 1;
                    must_write_read = 1;
                }
            }
            else
            {
                // printf("Next one is not a pipe (%s)\n", *argv);
                next_is_pipe = 0;
                if (pipe_opened == 1)
                {
                    // printf("Not opening pipe, only reading\n");
                    must_read = 1;
                }
                else
                {
                    pipe_opened = 0;
                }
            }
            // printf("Fd[0] is %d and %d\n", fd[0][READ], fd[0][WRITE]);
            // printf("Fd[1] is %d and %d\n", fd[1][READ], fd[1][WRITE]);
            int pid = fork();
            if (pid < 0)
            {
                printf("Error with fork\n");
                exit(2);
            }
            if (pid == 0)
            {
                if (must_write == 1)
                {
                    // printf("Writing into first pipe (%s)\n", *argv);
                    if (dup2(fd[0][WRITE], STDOUT_FILENO) < 0)
                    {
                        printf("error with dup2 (%s)\n", strerror(errno));
                        exit(2);
                    }
                }
                else if (must_read == 1)
                {
                    // printf("Reading from first pipe (%s)\n", *argv);
                    if (dup2(fd[0][READ], STDIN_FILENO) < 0)
                    {
                        printf("error with dup2 (%s)\n", strerror(errno));
                        exit(2);
                    }
                }
                else if (must_write_read == 1)
                {
                    // printf("Reading from first pipe and writing into one (%s)\n", *argv);
                    if (dup2(fd[0][READ], STDIN_FILENO) < 0)
                    {
                        printf("error with dup2 (%s)\n", strerror(errno));
                        exit(2);
                    }
                    if (dup2(fd[1][WRITE], STDOUT_FILENO) < 0)
                    {
                        printf("error with dup2 (%s)\n", strerror(errno));
                        exit(2);
                    }
                }

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
            // if (WIFEXITED(status))
            //     return (WEXITSTATUS(status));
            if (must_write == 1)
            {
                // printf("Closing for must_write\n");
                if (close(fd[0][WRITE]) == -1)
                    printf("Error with close (0, WRITE)\n");
            }
            else if (must_read == 1)
            {
                // printf("Closing for must_read\n");
                if (close(fd[0][READ]) == -1)
                    printf("Error with close (0, READ)\n");
                // if (close(fd[0][WRITE]) == -1)
                //     printf("Error with close (0, WRITE)\n");
            }
            else if (must_write_read == 1)
            {
                // printf("Closing for must_write_read\n");
                fd[0][READ] = fd[1][READ];
                if (close(fd[1][WRITE]) == -1)
                    printf("Error with close (0, READ)\n");
            }

            must_read = 0;
            must_write = 0;
            must_write_read = 0;

            int num_args = ft_get_num_args(argv);
            argv += num_args;
            if (!*(argv + 1))
                exit(1);
            // printf("\n");
        }
    }
    system("leaks microshell");
    return (0);
}