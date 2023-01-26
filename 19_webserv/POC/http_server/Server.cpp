#include "Server.hpp"

#include <iostream>
#include <sys/socket.h>

Server::Server()
{
    std::cout << "Server default constructor" << std::endl;
    this->socket = ListeningSocket();
}

Server::Server(int domain, int service, int protocol, int port, u_long interface, int backlog)
{
    std::cout << "Server parameter constructor" << std::endl;
    std::cout << std::endl;

    this->socket = ListeningSocket(domain, service, protocol, port, interface, backlog);
}

Server::~Server()
{
    std::cout << "Server destructor" << std::endl;
}

ListeningSocket Server::getSocket()
{
    return this->socket;
}
