#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <time.h>

#define BUFFER_SIZE 65535

volatile sig_atomic_t running;

void stop()
{
    running = 0;
}

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
    {
        printf("Usage: client [port] [mode]");
        return 1;
    }

    // Connect to server

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket()");
        return 1;
    }

    int port = atoi(argv[1]);
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(struct sockaddr);
    // memset(&server_addr, 0, addr_len);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, addr_len) < 0)
    {
        perror("connect()");
        return -1;
    }
    fcntl(sockfd, F_SETFL, O_NONBLOCK);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    printf("Connected to Server port %d\n", port);

    // Main Loop

    char buffer[BUFFER_SIZE];
    signal(SIGINT, stop);

    fd_set reads;
    fd_set writes;
    int mode = 0;
    int flag_ln = 0;
    if (argc == 3)
        mode = 1;

    running = 1;
    int do_send = 0;
    while (running)
    {
        FD_ZERO(&reads);
        FD_ZERO(&writes);
        FD_SET(sockfd, &reads);
        FD_SET(STDIN_FILENO, &reads);
        if (do_send)
            FD_SET(sockfd, &writes);

        int activity = select(sockfd + 1, &reads, &writes, NULL, NULL);
        if (activity > 0)
        {
            if (FD_ISSET(sockfd, &reads))
            {
                int received = recv(sockfd, buffer, BUFFER_SIZE - 1, MSG_DONTWAIT);
                if (received < 0)
                {
                    perror("recv()");
                    close(sockfd);
                    return 1;
                }
                else if (received == 0)
                {
                    printf("Server disconnected\n");
                    close(sockfd);
                    return 0;
                }
                else
                {
                    buffer[received] = 0;
                    printf("%s", buffer);
                }
            }
            if (FD_ISSET(sockfd, &writes) && do_send)
            {
                size_t length = strlen(buffer);
                send(sockfd, buffer, length, MSG_DONTWAIT);
                do_send = 0;
                flag_ln++;
            }
            if (FD_ISSET(STDIN_FILENO, &reads))
            {
                ssize_t typed = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
                if (typed < 0)
                {
                    perror("read()");
                    close(sockfd);
                    return 1;
                }
                else
                {
                    buffer[typed] = 0;
                    if (mode && flag_ln % 2 == 0)
                        buffer[typed - 1] = 0;
                    do_send = 1;
                }
            }
        }
    }

    close(sockfd);
    return 0;
}