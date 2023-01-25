#include "Sockets/ListeningSocket.hpp"
#include "Sockets/ClientSocket.hpp"

#include <iostream>

int main()
{
    ListeningSocket server(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10);
    std::cout << "=====================================" << std::endl;
    // ClientSocket client(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY);

    std::cout << "=====================================" << std::endl;
}