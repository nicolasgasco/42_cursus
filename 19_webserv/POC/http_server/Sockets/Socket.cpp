#include "Socket.hpp"

#include <iostream>
#include <sys/socket.h>

Socket::Socket() 
{
    std::cout << "Socket default constructor" << std::endl;

    // Define address structure
    this->address.sin_family = AF_INET;
    this->address.sin_port = htons(8080);
    this->address.sin_addr.s_addr = htonl(INADDR_ANY);

    // Establish socket
    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    this->testConnection(this->sock);

    /// Establish connection in child class constructor
}

Socket::Socket(int domain, int service, int protocol, int port, u_long interface)
{
    std::cout << "Socket parameter constructor" << std::endl;
    std::cout << std::endl;

    // this->port = port;

    // Define address structure
    this->address.sin_family = domain;
    this->address.sin_port = htons(port);
    this->address.sin_addr.s_addr = htonl(interface);
    std::cout << "Address defined..." << std::endl;

    // Establish socket
    this->sock = socket(domain, service, protocol);
    this->testConnection(this->sock);
    std::cout << "Socket established..." << std::endl;
    std::cout << std::endl;

    /// Establish connection in child class constructor
}

Socket::~Socket()
{
    std::cout << "Socket destructor" << std::endl;
}

void Socket::testConnection(int itemToTest)
{
    if (itemToTest < 0)
    {
        perror("Failed to connect..");
        exit(EXIT_FAILURE);
    }
}

struct sockaddr_in Socket::getAddress()
{
    return this->address;
}

int Socket::getSock()
{
    return this->sock;
}

int Socket::getConnection()
{
    return this->connection;
}

void Socket::setConnection(int value)
{
    this->connection = value;
}