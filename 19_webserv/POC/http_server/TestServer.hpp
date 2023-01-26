#pragma once

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "Server.hpp"

class TestServer : public Server
{
private:
    char buffer[30000];
    int newSocket;

public:
    // Lifecycle
    TestServer();
    TestServer(int domain, int service, int protocol, int port, u_long interface, int backlog);

    void accepter();
    void handler();
    void responder();

    void launch();

    ~TestServer();
};