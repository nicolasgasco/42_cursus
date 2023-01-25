#include "ClientSocket.hpp"
#include "Socket.hpp"

#include <iostream>

ClientSocket::ClientSocket() : Socket()
{
    std::cout << "ClientSocket default constructor" << std::endl;

    // Establishing connection
    this->setConnection(this->connectToNetwork(this->getSock(), this->getAddress()));
    this->testConnection(this->getConnection());
    std::cout << "Connecction established on port " << 8080 << "..." << std::endl;
}

ClientSocket::ClientSocket(int domain, int service, int protocol, int port, u_long interface) : Socket(domain, service, protocol, port, interface)
{
    std::cout << "ClientSocket parameter constructor" << std::endl;
    std::cout << std::endl;

    // Establishing connection
    this->setConnection(this->connectToNetwork(this->getSock(), this->getAddress()));
    this->testConnection(this->getConnection());
    std::cout << "Connecction established on port " << port << "..." << std::endl;
}

ClientSocket::~ClientSocket()
{
    std::cout << "ClientSocket destructor" << std::endl;
}

int ClientSocket::connectToNetwork(int sock, struct sockaddr_in sockaddr_in)
{
    return connect(sock, (const struct sockaddr *)&sockaddr_in, sizeof(this->getAddress()));
}
