#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <printf.h>

#define PORT 8081
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

int main(void)
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    servaddr.sin_port = htons(PORT);

    while (1)
    {

        // Binding newly created socket to given IP and verification
        if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        {
            printf("socket bind failed...\n");
            exit(0);
        }
        else
            printf("Socket successfully binded..\n");
        if (listen(sockfd, 10) != 0)
        {
            printf("cannot listen\n");
            exit(0);
        }
        len = sizeof(cli);
        connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t *)&len);
        if (connfd < 0)
        {
            printf("server acccept failed...\n");
            exit(0);
        }
        else
            printf("server acccept the client...\n");

        printf("Ready to receive\n");

        char *msg = (char *)malloc(sizeof(char) * BUFF_SIZE);
        char *buf = (char *)malloc(sizeof(char) * BUFF_SIZE);

        int bytes_recv = recv(connfd, buf, BUFF_SIZE, 0);
        printf("Received %d bytes\n", bytes_recv);

        int extract_res = -1;
        while (extract_res != 0)
        {
            extract_res = extract_message(&buf, &msg);
            printf("Extract result: %d\n", extract_res);
            printf("Message: .%s.\n", msg);
        }

        free(buf);

        printf("Closing connection\n");
        close(sockfd);
        close(connfd);
    }
    return 1;
}