#include "ServerSocket.hpp"
#include "ClientSocket.hpp"

#include <iostream>

int main()
{
    ServerSocket server(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY);
    std::cout << "=====================================" << std::endl;
    ClientSocket client(AF_INET, SOCK_STREAM, 0, 4201, INADDR_ANY);

    std::cout << "=====================================" << std::endl;
}