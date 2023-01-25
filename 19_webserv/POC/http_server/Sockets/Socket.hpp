#pragma once

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Socket
{
private:
    struct sockaddr_in address;
    int sock;
    int connection;

public:
    // Lifecycle
    Socket();
    Socket(int domain, int service, int protocol, int port, u_long interface);

    virtual ~Socket();

    // Logic
    virtual int connectToNetwork(int sock, struct sockaddr_in sockaddr_in) = 0;
    void testConnection(int);

    // Getters
    struct sockaddr_in getAddress();
    int getSock();
    int getConnection();

    // Setter
    void setConnection(int value);
};