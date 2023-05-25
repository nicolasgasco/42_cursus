#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
            throw std::runtime_error(std::string("Please provide an argument"));

        RPN rpn;
        std::cout << rpn.calculate(argv[1]) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}