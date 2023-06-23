#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <printf.h>
#include <stdio.h>

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

void add_to_array(int *array, int value)
{
    int i = 0;
    while (array[i])
        i++;
    array[i] = value;
}

void remove_from_array(int *array, int value)
{
    int i = 0;
    while (array[i])
    {
        if (array[i] == value)
            array[i] = -1;
        i++;
    }
}

int ft_find_value_in_arr(int *array, int value)
{
    int i = 0;
    while (array[i])
    {
        if (array[i] == value)
            return i;
        i++;
    }
    return -1;
}

void ft_print_int(int fd, char *msg, int value)
{
    char print_msg[100];
    sprintf(print_msg, msg, value);
    write(fd, print_msg, strlen(print_msg));
}

void ft_print_str(int fd, char *msg)
{
    write(fd, msg, strlen(msg));
}

void print_to_clients(char *msg, int *active_connections, int connfd)
{
    int j = 0;
    while (active_connections[j])
    {
        if (active_connections[j] != connfd && active_connections[j] != -1)
            ft_print_int(active_connections[j], msg, ft_find_value_in_arr(active_connections, connfd));
        j++;
    }
    ft_print_int(1, msg, ft_find_value_in_arr(active_connections, connfd));
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_print_str(2, "Wrong number of arguments\n");
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd, connfd, len;
    struct sockaddr_in servaddr = {0};
    bzero(&servaddr, sizeof(servaddr));

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        ft_print_str(2, "Fatal error\n");
        exit(1);
    }

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = 16777343;
    servaddr.sin_port = htons(port);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
    {
        ft_print_str(2, "Fatal error\n");
        exit(1);
    }

    if (listen(sockfd, 128) != 0)
    {
        ft_print_str(2, "Fatal error\n");
        exit(1);
    }

    // SELECT
    fd_set read_fds, read_fds_cpy;
    FD_ZERO(&read_fds);
    FD_ZERO(&read_fds_cpy);

    FD_SET(sockfd, &read_fds_cpy);

    int active_connections[FD_SETSIZE];
    bzero(active_connections, FD_SETSIZE);

    while (1)
    {
        // Necessary because select is destructive
        read_fds = read_fds_cpy;

        if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) < 0)
        {
            ft_print_str(2, "Fatal error\n");
            exit(1);
        }

        for (int i = 3; i <= FD_SETSIZE; ++i)
        {
            if (FD_ISSET(i, &read_fds))
            {
                // New connection waiting to be accepted
                if (i == sockfd)
                {
                    struct sockaddr_in cli;
                    len = sizeof(cli);
                    connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t *)&len);
                    if (connfd < 0)
                    {
                        ft_print_str(2, "Fatal error\n");
                        exit(1);
                    }
                    else
                    {
                        add_to_array(active_connections, connfd);
                        FD_SET(connfd, &read_fds_cpy);
                        print_to_clients("server: client %d just arrived\n", active_connections, connfd);
                    }
                }
                // Existing connection sending data
                else
                {
                    char *buf = (char *)malloc(sizeof(char) * 30000);
                    bzero(buf, 30000);

                    int bytes_recv = recv(i, buf, 30000, 0);
                    switch (bytes_recv)
                    {
                    case -1:
                        ft_print_str(2, "Fatal error\n");
                        if (buf)
                            free(buf);
                        exit(1);
                    case 0:
                    {
                        print_to_clients("server: client %d just left\n", active_connections, i);
                        remove_from_array(active_connections, i);
                        FD_CLR(i, &read_fds_cpy);
                        close(i);

                        // if (buf)
                        //     free(buf);
                        break;
                    }
                    }

                    int must_break = 0;
                    while (!must_break)
                    {
                        char *msg = (char *)malloc(sizeof(char) * 30000);
                        bzero(msg, 30000);

                        int extract_res = extract_message(&buf, &msg);
                        if (extract_res == -1)
                        {
                            ft_print_str(2, "Fatal error\n");
                            if (msg)
                                free(msg);
                            return 1;
                        }
                        else if (extract_res == 0)
                        {
                            must_break = 1;
                            if (strlen(buf) == 0)
                                break;

                            msg = buf;
                        }

                        char string[] = "client %d: ";
                        char *output = (char *)malloc(sizeof(char) * (strlen(string) + strlen(msg) + 50));
                        strcat(output, string);
                        strcat(output, msg);
                        print_to_clients(output, active_connections, i);
                        free(output);

                        if (must_break)
                            break;

                        free(msg);
                    }
                    if (buf)
                        free(buf);
                }
            }
        }
    }
}