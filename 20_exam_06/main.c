#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <printf.h>
#include <stdio.h>

#define BUFF_SIZE 30000

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
    int tmp[FD_SETSIZE];
    bzero(tmp, FD_SETSIZE);

    int i = 0;
    int j = 0;
    while (array[i])
    {
        if (array[i] != value)
        {
            tmp[j] = array[i];
            j++;
        }
        i++;
    }

    bzero(array, FD_SETSIZE);

    i = 0;
    while (tmp[i])
    {
        array[i] = tmp[i];
        i++;
    }
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

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Wrong number of arguments\n");
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd, connfd, len;
    struct sockaddr_in servaddr;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Fatal error\n");
        exit(1);
    }
    else
        printf("Socket successfully created: %d..\n", sockfd); // Remove before submission
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = 16777343;
    servaddr.sin_port = htons(port);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("Fatal error\n");
        exit(1);
    }
    else
        printf("Socket successfully binded..\n"); // Remove before submission

    if (listen(sockfd, 10) != 0)
    {
        printf("Fatal error\n");
        exit(1);
    }
    else
        printf("Server listening..\n"); // Remove before submission

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
            ft_print_str(1, "Error with select\n");

        for (int i = 3; i <= FD_SETSIZE; ++i)
        {
            if (FD_ISSET(i, &read_fds))
            {
                if (i == sockfd)
                {
                    ft_print_int(1, "Socket %d is ready to accept new connections\n", i);

                    struct sockaddr_in cli;
                    len = sizeof(cli);
                    connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t *)&len);
                    ft_print_int(1, "New connection accepted on socket: %d\n", connfd);
                    if (connfd < 0)
                    {
                        ft_print_str(1, "server acccept failed...\n");
                        exit(0);
                    }
                    else
                    {
                        int j = 0;
                        while (active_connections[j])
                        {
                            ft_print_int(active_connections[j], "\033[0;33mserver: client %d just arrived\n\033[0m", connfd);
                            j++;
                        }
                        add_to_array(active_connections, connfd);
                        FD_SET(connfd, &read_fds_cpy);
                    }
                }
                else
                {
                    ft_print_int(1, "Socket %d is ready to be read\n", i);

                    char *msg = (char *)malloc(sizeof(char) * BUFF_SIZE);
                    char *buf = (char *)malloc(sizeof(char) * BUFF_SIZE);
                    if (msg == NULL || buf == NULL)
                    {
                        ft_print_str(1, "Fatal error\n");
                        return 1;
                    }
                    bzero(msg, BUFF_SIZE);
                    bzero(buf, BUFF_SIZE);

                    int bytes_recv = recv(i, buf, BUFF_SIZE, 0);

                    switch (bytes_recv)
                    {
                    case -1:
                        printf("Error recv: %s\n", strerror(errno));
                        // FREE here
                        break;
                    case 0:
                    {
                        remove_from_array(active_connections, i);

                        int j = 0;
                        while (active_connections[j])
                        {
                            if (active_connections[j] != i)
                                ft_print_int(active_connections[j], "\033[0;33mserver: client %d just left\n\033[0m", i);
                            j++;
                        }
                        FD_CLR(i, &read_fds_cpy);
                        // FREE here
                        break;
                    }
                    default:
                        ft_print_str(1, "\n------------------\n");
                        ft_print_int(1, "Received %d bytes\n", bytes_recv);
                    }

                    int extract_res = extract_message(&buf, &msg);
                    if (extract_res == -1)
                    {
                        ft_print_str(1, "Fatal error\n");
                        return 1;
                    }
                    free(buf);

                    if (extract_res == 0)
                    {
                        // FREE here
                        break;
                    }

                    printf("Message: .%s.\n", msg);
                    ft_print_str(1, "\n------------------\n");

                    char string[] = "client %d: ";
                    char *output = (char *)malloc(sizeof(char) * (strlen(string) + strlen(msg) + 50));
                    strcat(output, string);
                    strcat(output, msg);
                    int j = 0;
                    while (active_connections[j])
                    {
                        if (active_connections[j] != i)
                            ft_print_int(active_connections[j], output, i);
                        j++;
                    }
                    free(output);
                    free(msg);
                }
            }
        }
    }
    return 1;
}