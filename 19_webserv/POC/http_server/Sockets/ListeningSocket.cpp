#include "ListeningSocket.hpp"
#include "ServerSocket.hpp"

#include <iostream>

ListeningSocket::ListeningSocket() : ServerSocket()
{
    std::cout << "ListeningSocket default constructor" << std::endl;
    this->backlog = 10;
}

ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int backlog) : ServerSocket(domain, service, protocol, port, interface)
{
    std::cout << "ListeningSocket parameter constructor" << std::endl;
    std::cout << std::endl;

    this->backlog = backlog;
    this->listening = startListening();
    this->testConnection(this->listening);
    std::cout << "Listen on socket..." << std::endl;
}

ListeningSocket::~ListeningSocket()
{
    std::cout << "ListeningSocket destructor" << std::endl;
}

int ListeningSocket::startListening()
{
    return listen(this->getSock(), this->backlog);
}

int ListeningSocket::getBacklog()
{
    return this->backlog;
}