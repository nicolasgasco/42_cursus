#pragma once

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "Sockets/ListeningSocket.hpp"

class Server
{
private:
    ListeningSocket socket;

public:
    // Lifecycle
    Server();
    Server(int domain, int service, int protocol, int port, u_long interface, int backlog);

    virtual void accepter() = 0;
    virtual void handler() = 0;
    virtual void responder() = 0;

    virtual void launch() = 0;

    ListeningSocket getSocket();
    ~Server();
};