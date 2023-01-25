#pragma once

#include "Socket.hpp"

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

class ServerSocket : public Socket
{
private:
public:
    ServerSocket();
    ServerSocket(int domain, int service, int protocol, int port, u_long interface);

    ~ServerSocket();

    int connectToNetwork(int sock, struct sockaddr_in sockaddr_in);
};