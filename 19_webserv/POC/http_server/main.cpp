#include "Sockets/ListeningSocket.hpp"
#include "Sockets/ClientSocket.hpp"
#include "TestServer.hpp"
#include <iostream>

int main()
{
    TestServer server(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10);
    server.launch();
}