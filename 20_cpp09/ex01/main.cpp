#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Please provide exactly one argument" << std::endl;
        return 1;
    }

    RPN rpn(argv[1]);
    rpn.output_result();

    return 0;
}