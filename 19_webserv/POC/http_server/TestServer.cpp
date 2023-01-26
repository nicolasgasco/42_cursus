#include "TestServer.hpp"

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

TestServer::TestServer() : Server()
{
    std::cout << "TestServer default constructor" << std::endl;
}

TestServer::TestServer(int domain, int service, int protocol, int port, u_long interface, int backlog) : Server(domain, service, protocol, port, interface, backlog)
{
    std::cout << "TestServer parameter constructor" << std::endl;
    std::cout << std::endl;
}

TestServer::~TestServer()
{
    std::cout << "TestServer destructor" << std::endl;
}

void TestServer::accepter()
{
    struct sockaddr_in address = this->getSocket().getAddress();
    socklen_t sizeOfAddress = sizeof(address);
    this->newSocket = accept(this->getSocket().getSock(), (struct sockaddr *)&address, (socklen_t *)&sizeOfAddress);
    read(this->newSocket, this->buffer, 30000);
}

void TestServer::handler()
{
    std::cout << buffer << std::endl;
}

void TestServer::responder()
{
    char message[] = "Hello world";
    write(this->newSocket, message, sizeof(message));
    close(this->newSocket);
}

void TestServer::launch()
{
    while (true)
    {
        std::cout << "===== Waiting =====" << std::endl;
        accepter();
        handler();
        responder();
        std::cout << "===== Done =====" << std::endl;
    }
}