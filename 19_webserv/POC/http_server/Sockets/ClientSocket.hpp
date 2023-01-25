#pragma once

#include "Socket.hpp"

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

class ClientSocket : public Socket
{
private:
public:
    ClientSocket();
    ClientSocket(int domain, int service, int protocol, int port, u_long interface);

    ~ClientSocket();

    int connectToNetwork(int sock, struct sockaddr_in sockaddr_in);
};