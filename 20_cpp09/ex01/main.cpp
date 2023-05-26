#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
        throw std::runtime_error(std::string("Please provide an argument"));

    RPN rpn;
    rpn.calculate(argv[1]);
}