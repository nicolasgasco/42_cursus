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

bool is_input_valid(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        for (unsigned int j = 0; j < strlen(argv[i]); j++)
        {
            if (!std::isdigit(argv[i][j]))
                return false;
        }

        int value = std::atoi(argv[i]);
        if (value < 0)
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Please provide an argument" << std::endl;
        return 1;
    }
    else if (argc == 2)
    {
        std::cerr << "Provide more than one number" << std::endl;
        return 1;
    }

    if (!is_input_valid(argc, argv))
    {
        std::cerr << "Invalid input" << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    output_args(argc, argv);

    PmergeMe pmergeMe;

    return 0;
}