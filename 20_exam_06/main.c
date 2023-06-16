#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <printf.h>

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

int find_in_array(int *array, int value)
{
    int i = 0;
    while (array[i])
    {
        if (array[i] == value)
            return 1;
        i++;
    }
    return 0;
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
    servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
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
    fd_set read_fds, read_fds_cpy, write_fds, write_fds_cpy;
    FD_ZERO(&read_fds);
    FD_ZERO(&read_fds_cpy);
    FD_ZERO(&write_fds);
    FD_ZERO(&write_fds_cpy);

    struct timeval timeout;
    timeout.tv_sec = 30;
    timeout.tv_usec = 0;

    FD_SET(sockfd, &read_fds_cpy);
    int *active_connections = (int *)malloc(sizeof(int) * FD_SETSIZE);
    bzero(active_connections, FD_SETSIZE);

    while (1)
    {
        // Necessary because select is destructive
        read_fds = read_fds_cpy;
        write_fds = write_fds_cpy;

        if (select(sockfd + 1, &read_fds, &write_fds, NULL, &timeout) < 0)
            printf("Error with select\n");

        for (int i = 3; i <= FD_SETSIZE; ++i)
        {
            if (FD_ISSET(i, &read_fds))
            {
                if (i == sockfd)
                {
                    struct sockaddr_in cli;
                    len = sizeof(cli);
                    // ACCEPT CONNECTION
                    connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t *)&len);
                    if (connfd < 0)
                    {
                        printf("server acccept failed...\n");
                        exit(0);
                    }
                    else
                        printf("server: client %d just arrived\n", i);

                    FD_SET(connfd, &read_fds_cpy);
                }
                else
                {
                    char *msg = (char *)malloc(sizeof(char) * BUFF_SIZE);
                    char *buf = (char *)malloc(sizeof(char) * BUFF_SIZE);
                    if (msg == NULL || buf == NULL)
                    {
                        printf("Fatal error\n");
                        return 1;
                    }

                    int bytes_recv = recv(connfd, buf, BUFF_SIZE, 0);

                    switch (bytes_recv)
                    {
                    case 0:
                        continue;
                    default:
                        printf("Received %d bytes\n", bytes_recv);
                    }

                    int extract_res = extract_message(&buf, &msg);
                    if (extract_res == -1)
                    {
                        printf("Error: %s\n", strerror(errno));
                        return 1;
                    }

                    if (extract_res == 0)
                        break;

                    printf("Message: .%s.\n", msg);
                    free(msg);
                    free(buf);
                }
            }
            else if (FD_ISSET(i, &write_fds))
            {
                printf("Set for writing\n");
            }
        }
    }
    return 1;
}