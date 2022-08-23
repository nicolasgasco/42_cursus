#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ft_write_fd(int fd, char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], sizeof(char));
		i++;
	}
}

void ft_fatal_error(void)
{
	ft_write_fd(STDERR_FILENO, "error: fatal\n");
	exit(2);
}

int ft_get_num_args(char **argv)
{
	int i = 0;
	while (*(argv + i))
	{
		if (strcmp(*(argv + i), "|") == 0 || strcmp(*(argv + i), ";") == 0)
			break;
		i++;
	}
	return (i);
}

void ft_get_trimmed_args(char **trimmed_args, char **argv)
{
	int i = 0;
	while (*(argv + i))
	{
		if (strcmp(*(argv + i), "|") == 0 || strcmp(*(argv + i), ";") == 0)
			break;
		trimmed_args[i] = *(argv + i);
		i++;
	}
	trimmed_args[i] = NULL;
}

void ft_cd(char **argv)
{
	argv++;
	int num_args = ft_get_num_args(argv);
	if (num_args != 1)
	{
		ft_write_fd(STDERR_FILENO, "error: cd: bad arguments\n");
		exit(2);
	}
	if (chdir(*argv) == -1)
	{
		ft_write_fd(STDERR_FILENO, "error: cd: cannot change directory to ");
		ft_write_fd(STDERR_FILENO, *argv);
		ft_write_fd(STDERR_FILENO, "\n");
		exit(2);
	}
	argv++;
}

int main(int argc, char **argv, char **envp)
{
	int fd[2][2];
	int pipe_opened = 0;
	fd[0][0] = -1;
	fd[0][1] = -1;
	fd[1][0] = -1;
	fd[1][1] = -1;
	argv++;
	while (*argv)
	{
		int must_read = 0;
		int must_write = 0;
		int must_write_read = 0;
		if (strcmp(*argv, ";") == 0)
			argv++;
		else if (strcmp(*argv, "cd") == 0)
		{
			ft_cd(argv);
			argv += ft_get_num_args(argv);
		}
		else if (strcmp(*argv, "|") == 0)
			argv++;
		else
		{
			int num_args = ft_get_num_args(argv);
			if (*(argv + num_args) && strcmp(*(argv + num_args), "|") == 0)
			{
				int fd_num;
				if (pipe_opened == 0)
				{
					fd_num = 0;
					must_write = 1;
				}
				else
				{
					fd_num = 1;
					must_write_read = 1;
				}
				if (pipe(fd[fd_num]) == -1)
					ft_fatal_error();
				pipe_opened = 1;
			}
			else
			{
				if (pipe_opened == 1)
				{
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
					if (dup2(fd[0][1], STDOUT_FILENO) < 0)
						ft_fatal_error();
				}
				else if (must_read == 1)
				{
					if (dup2(fd[0][0], STDIN_FILENO) < 0)
						ft_fatal_error();
				}
				else if (must_write_read == 1)
				{
					if (dup2(fd[0][0], STDIN_FILENO) < 0)
						ft_fatal_error();
					if (dup2(fd[1][1], STDOUT_FILENO) < 0)
						ft_fatal_error();
				}
				char *trimmed_args[argc];
				ft_get_trimmed_args(trimmed_args, argv);
				if (execve(*argv, trimmed_args, envp) == -1)
				{
					ft_write_fd(STDERR_FILENO, "error: cannot execute ");
					ft_write_fd(STDERR_FILENO, *argv);
					ft_write_fd(STDERR_FILENO, "\n");
				}
				exit(2);
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
				argv += ft_get_num_args(argv);
			}
		}
	}
	if (fd[0][0] != -1 && fd[1][0] == -1)
		close(fd[0][0]);
	if (fd[1][0] != -1)
		close(fd[1][0]);
	system("lsof -c microshell | grep PIPE");
	return (0);
}
