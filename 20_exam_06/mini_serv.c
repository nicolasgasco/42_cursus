#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <printf.h>

int extract_message(char **buf, char **msg)
{
	char *newbuf;
	int i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char *newbuf;
	int len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void ft_putstr(int fd, char *str)
{
	write(fd, str, strlen(str));
}

void ft_putint(int fd, char *str, int value)
{
	char output[100];
	bzero(output, sizeof(output));

	sprintf(output, str, value);
	ft_putstr(fd, output);
}

void ft_add_connection(int *active_fds, int connfd)
{
	int i = 0;
	while (active_fds[i])
		i++;
	active_fds[i] = connfd;
}

int ft_find_connection(int *active_fds, int connfd)
{
	int i = 0;
	while (active_fds[i])
	{
		if (active_fds[i] == connfd)
			return i;
		i++;
	}
	return -1;
}

void ft_remove_connection(int *active_fds, int connfd)
{
	int i = 0;
	while (active_fds[i])
	{
		if (active_fds[i] == connfd)
			active_fds[i] = -1;
		i++;
	}
}

int ft_find_newline(char *buf)
{
	int i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return i;
		i++;
	}
	return -1;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr(2, "Wrong number of arguments\n");
		exit(1);
	}

	int port = atoi(argv[1]);

	// socket create and verification
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		ft_putstr(2, "Fatal error\n");
		exit(1);
	}

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(port);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
	{
		ft_putstr(2, "Fatal error\n");
		close(sockfd);
		exit(1);
	}

	if (listen(sockfd, 10) != 0)
	{
		ft_putstr(2, "Fatal error\n");
		close(sockfd);
		exit(1);
	}

	fd_set read_fds, read_fds_cpy;
	FD_ZERO(&read_fds);
	FD_ZERO(&read_fds_cpy);

	FD_SET(sockfd, &read_fds_cpy);

	int active_fds[124];
	bzero(active_fds, sizeof(active_fds));

	while (1)
	{
		read_fds = read_fds_cpy;

		if (select(124, &read_fds, 0, 0, 0) < 0)
		{
			ft_putstr(2, "Fatal error\n");
			close(sockfd);
			exit(1);
		}

		for (int i = 3; i < 124; ++i)
		{
			if (FD_ISSET(i, &read_fds))
			{
				if (i == sockfd)
				{
					struct sockaddr_in cli;
					bzero(&cli, sizeof(cli));
					int len = sizeof(cli);
					int connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t *)&len);
					if (connfd < 0)
					{
						ft_putstr(2, "Fatal error\n");
						close(sockfd);
						exit(1);
					}

					printf("server acccept the client %d...\n", connfd);
					FD_SET(connfd, &read_fds_cpy);
					ft_add_connection(active_fds, connfd);

					int j = 0;
					while (active_fds[j])
					{
						if (active_fds[j] != connfd && active_fds[j] != -1)
							ft_putint(active_fds[j], "server: client %d just arrived\n", ft_find_connection(active_fds, connfd));
						j++;
					}
				}
				else
				{
					char *buf = (char *)malloc(sizeof(char) * 30000);
					bzero(buf, 30000);

					int bytes_rec = recv(i, buf, 30000, 0);
					if (bytes_rec < 0)
					{
						ft_putstr(2, "Error with recv\n");
						exit(1);
					}
					else if (bytes_rec == 0)
					{
						int j = 0;
						while (active_fds[j])
						{
							if (active_fds[j] != i && active_fds[j] != -1)
								ft_putint(active_fds[j], "server: client %d just left\n", ft_find_connection(active_fds, i));
							j++;
						}

						FD_CLR(i, &read_fds_cpy);
						ft_remove_connection(active_fds, i);
						close(i);

						continue;
					}

					while (buf && strlen(buf) != 0)
					{
						char *msg = (char *)malloc(sizeof(char) * 30000);
						bzero(msg, 30000);
						if (ft_find_newline(buf) == -1)
						{
							strcpy(msg, buf);
							free(buf);
						}
						else
						{
							int ret = extract_message(&buf, &msg);
							if (ret == -1)
							{
								ft_putstr(2, "Error with extract_message\n");
								exit(1);
							}
							else if (ret == 0)
							{
								printf("msg is .%s.\n", msg);
								printf("buf is .%s.\n", buf);
								printf("Is zero:\n");
							}
						}

						int j = 0;
						while (active_fds[j])
						{
							if (active_fds[j] != i && active_fds[j] != -1)
							{
								ft_putint(active_fds[j], "Client %d: ", i);
								if (send(active_fds[j], msg, strlen(msg), 0) < 0)
								{
									ft_putstr(2, "Error with send\n");
									exit(1);
								}
							}
							j++;
						}
						free(msg);
					}
				}
			}
		}
	}
}