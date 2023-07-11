#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

int fd_max = 0;
fd_set read_fds, read_fds_copy;
int fds[10000] = {0};
char buf[1024] = {0};
char output_buf[100] = {0};
char *msg[10000];

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

int ft_add_client(int connfd)
{
    int i = 0;
    while (fds[i])
        i++;
    fds[i] = connfd;
    return (i);
}

int ft_remove_client(int fd)
{
    int i = 0;
    while (fds[i])
    {
        if (fds[i] == fd)
        {
            fds[i] = -1;
            return i;
        }
        i++;
    }
    return i;
}

void ft_output_message(int fd, char *output_buf)
{
    int i = 0;
    while (fds[i])
    {
        if (fds[i] != fd && fds[i] != -1)
            send(fds[i], output_buf, strlen(output_buf), 0);
        i++;
    }
}

void ft_print_str(int fd, char *str)
{
    write(fd, str, strlen(str));
}

int ft_fd_pos(int fd)
{
    int i = 0;
    while (fds[i])
    {
        if (fds[i] == fd)
            return i;
        i++;
    }
    return i;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        ft_print_str(2, "Wrong number of arguments\n");
        exit(1);
    }

    // socket create and verification
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        ft_print_str(2, "Fatal error\n");
        exit(1);
    }

    fd_max = sockfd;

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    servaddr.sin_port = htons(atoi(argv[1]));

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
    {
        ft_print_str(2, "Fatal error\n");
        exit(1);
    }

    if (listen(sockfd, 128) != 0)
    {
        write(2, "Fatal error\n", 12);
        exit(1);
    }

    FD_ZERO(&read_fds);
    FD_ZERO(&read_fds_copy);
    FD_SET(sockfd, &read_fds_copy);

    while (1)
    {
        read_fds = read_fds_copy;

        if (select(fd_max + 1, &read_fds, 0, 0, 0) == -1)
        {
            write(2, "Fatal error\n", 12);
            exit(1);
        }

        for (int i = 3; i <= fd_max; i++)
        {
            if (FD_ISSET(i, &read_fds))
            {
                if (i == sockfd)
                {
                    struct sockaddr_in cli;
                    socklen_t len = sizeof(cli);
                    int connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
                    if (connfd < 0)
                        exit(1);

                    fd_max = connfd > fd_max ? connfd : fd_max;
                    FD_SET(connfd, &read_fds_copy);
                    msg[connfd] = NULL;
                    int new_client_pos = ft_add_client(connfd);
                    sprintf(output_buf, "server: client %d just arrived\n", new_client_pos);
                    ft_output_message(connfd, output_buf);
                    break;
                }
                else
                {
                    int ret = recv(i, buf, 1024, 0);
                    if (ret <= 0)
                    {
                        close(i);
                        free(msg[i]);
                        msg[i] = NULL;
                        FD_CLR(i, &read_fds_copy);
                        int removed_client_pos = ft_remove_client(i);
                        sprintf(output_buf, "server: client %d just left\n", removed_client_pos);
                        ft_output_message(i, output_buf);
                        break;
                    }

                    buf[ret] = '\0';
                    msg[i] = str_join(msg[i], buf);
                    char *msg_to_send;
                    while (extract_message(&(msg[i]), &msg_to_send))
                    {
                        sprintf(output_buf, "client %d: ", ft_fd_pos(i));
                        ft_output_message(i, output_buf);
                        ft_output_message(i, msg_to_send);
                        free(msg_to_send);
                        msg_to_send = NULL;
                    }
                }
            }
        }
    }
    return 0;
}