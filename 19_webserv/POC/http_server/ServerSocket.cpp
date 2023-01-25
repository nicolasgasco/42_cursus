#include "ServerSocket.hpp"
#include "Socket.hpp"

#include <iostream>

ServerSocket::ServerSocket() : Socket()
{
    std::cout << "ServerSocket default constructor" << std::endl;

    // Establishing connection
    this->setConnection(this->connectToNetwork(this->getSock(), this->getAddress()));
    this->testConnection(this->getConnection());
    std::cout << "Connecction established on port " << 8080 << "..." << std::endl;
}

ServerSocket::ServerSocket(int domain, int service, int protocol, int port, u_long interface) : Socket(domain, service, protocol, port, interface)
{
    std::cout << "ServerSocket parameter constructor" << std::endl;
    std::cout << std::endl;

    // Establishing connection
    this->setConnection(this->connectToNetwork(this->getSock(), this->getAddress()));
    this->testConnection(this->getConnection());
    std::cout << "Connecction established on port " << port << "..." << std::endl;
}

ServerSocket::~ServerSocket()
{
    std::cout << "ServerSocket destructor" << std::endl;
}

int ServerSocket::connectToNetwork(int sock, struct sockaddr_in sockaddr_in)
{
    return bind(sock, (const struct sockaddr *)&sockaddr_in, sizeof(this->getAddress()));
}
