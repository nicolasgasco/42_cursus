#pragma once

#include "ServerSocket.hpp"

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

class ListeningSocket : public ServerSocket
{
private:
    int backlog;
    int listening;

public:
    ListeningSocket();
    ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int backlog);

    ~ListeningSocket();

    int startListening();

    int getBacklog();
};