#include <iostream>
#include <cstdlib>
#include <Karen.hpp>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: arguments" << std::endl;
        return (1);
    }
    Karen karen = Karen();
    karen.complain(argv[1]);
    return (0);
}
