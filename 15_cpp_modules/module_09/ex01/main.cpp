#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Please provide exactly one argument" << std::endl;
        return 1;
    }

    RPN rpn(argv[1]);
    rpn.output_result();

    // RPN rpn1;
    // rpn1.output_result(argv[1]);

    // RPN rpn2 = rpn1;
    // rpn2.output_result(argv[1]);

    // RPN rpn3(argv[1]);
    // rpn3.output_result();

    // RPN rpn4(rpn3);
    // rpn4.output_result(argv[1]);

    return 0;
}
