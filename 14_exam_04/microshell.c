#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

void ft_write_fd(int fd, char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], sizeof(char));
		i++;
	}
}

void ft_execve_error(char **argv)
{
	ft_write_fd(STDERR_FILENO, "error: cannot execute ");
	ft_write_fd(STDERR_FILENO, *argv);
	ft_write_fd(STDERR_FILENO, "\n");
	exit(1);
}

void ft_fatal_error(void)
{
	ft_write_fd(STDERR_FILENO, "error: fatal\n");
	exit(1);
}

void ft_trim_args(char **argv, char **new_args)
{
	int i;
	for (i = 0; argv[i]; i++)
	{
		new_args[i] = argv[i];
		if (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0)
			break;
	}
	new_args[i] = NULL;
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

void ft_cd(char **argv)
{
	int num_args = ft_get_num_args(argv);
	if (num_args != 2)
	{
		ft_write_fd(STDERR_FILENO, "error: cd: bad arguments\n");
		exit(1);
	}
	argv++;
	if (chdir(*argv) == -1)
	{
		ft_write_fd(STDERR_FILENO, "error: cd: cannot change directory to ");
		ft_write_fd(STDERR_FILENO, *argv);
		ft_write_fd(STDERR_FILENO, "\n");
		exit(1);
	}
	argv++;
}

int main(int argc, char *argv[], char **envp)
{
	int fd[2][2];
	fd[0][0] = -1;
	fd[0][1] = -1;
	fd[1][0] = -1;
	fd[1][1] = -1;
	int num_args;
	int pipe_opened = 0;

	argv++;
	while (*argv)
	{
		int must_write = 0;
		int must_read = 0;
		int must_write_read = 0;
		if (strcmp(*argv, "|") == 0 && *(argv + 1))
		{
			argv += 1;
		}
		if (strcmp(*argv, ";") == 0)
		{
			argv += 1;
		}
		else if (strcmp(*argv, "cd") == 0)
		{
			ft_cd(argv);
			argv += ft_get_num_args(argv);
		}
		else
		{
			num_args = ft_get_num_args(argv);
			if (*(argv + num_args) && strcmp(*(argv + num_args), "|") == 0)
			{
				int pipe_num;
				if (pipe_opened == 0)
				{
					// printf("Opening first pipe for writing only\n");
					must_write = 1;
					pipe_num = 0;
				}
				else
				{
					// printf("Opening second pipe for reading and writing\n");
					must_write_read = 1;
					pipe_num = 1;
				}
				if (pipe(fd[pipe_num]) == -1)
					ft_fatal_error();
				pipe_opened = 1;
			}
			else
			{
				// printf("Next one is not a pipe (%s)\n", *argv);
				if (pipe_opened == 1)
				{
					// printf("Not opening pipe, only reading\n");
					must_read = 1;
				}
				else
					pipe_opened = 0;
			}
			int pid = fork();
			if (pid < 0)
				ft_fatal_error();
			if (pid == 0)
			{
				if (must_write == 1)
				{
					// printf("Writing into pipe\n");
					if (dup2(fd[0][1], STDOUT_FILENO) < 0)
						ft_fatal_error();
				}
				else if (must_read == 1)
				{
					// printf("Reading into pipe\n");
					if (dup2(fd[0][0], STDIN_FILENO) < 0)
						ft_fatal_error();
				}
				else if (must_write_read == 1)
				{
					// printf("Reading from and writing into pipe\n");
					if (dup2(fd[0][0], STDIN_FILENO) < 0)
						ft_fatal_error();
					if (dup2(fd[1][1], STDOUT_FILENO) < 0)
						ft_fatal_error();
				}
				char *new_args[argc];
				ft_trim_args(argv, new_args);
				if (execve(*argv, new_args, envp) == -1)
					ft_execve_error(argv);
				exit(1);
			}
			else
			{
				int status;
				waitpid(pid, &status, 0);
				if (must_write == 1)
				{
					close(fd[0][1]);
					fd[0][1] = -1;
				}
				else if (must_write_read == 1)
				{
					close(fd[0][0]);
					fd[0][0] = -1;
					fd[0][0] = fd[1][0];
					close(fd[1][1]);
					fd[1][1] = -1;
				}
				num_args = ft_get_num_args(argv);
				argv += num_args;
			}
		}
	}
	if (fd[0][0] != -1 && fd[1][0] == -1)
	{
		close(fd[0][0]);
		fd[0][0] = -1;
	}
	if (fd[1][0] != -1)
	{
		close(fd[1][0]);
		fd[1][0] = -1;
	}
	system("lsof -c microshell | grep PIPE");
	return (0);
}
