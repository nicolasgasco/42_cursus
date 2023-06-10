#include <iostream>
#include "PmergeMe.hpp"

void output_args(int argc, char *argv[])
{
    const int max_array_len = 20;
    for (int i = 1; i < argc; i++)
    {
        if (i < max_array_len)
            std::cout << argv[i] << (i == (argc - 1) ? "" : " ");
        else if (i == max_array_len)
            std::cout << "...";
        else
            break;
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Please provide an argument" << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    output_args(argc, argv);

    return 0;
}